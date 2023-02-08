/*******************************************************************************
 * @file        : app.c
 * @brief       : ........
 *
 * @version     XX.0.1
 *******************************************************************************
 * # License
 * <c>Copyright 2018-2020.
 * Author: Phu Thinh Nguyen, Pelagic Pressure Systems
 *******************************************************************************
 *
 *
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "L4X9_includes.h"

#ifdef _DSX_WARNINGSANDALARMS_H_
/*Button handle*/
//#include "ButtonHandle\i330_ButtonHandle.c"
/*Graphic user interface handle*/
//#include "GUI\i330_GUI.c"


/*******************************************************************************
 * @brief   GLOBAL Variables
 ******************************************************************************/
/* Global variable used in all PRTOS delay functions */
//union AlarmUNION  AlarmOn;           // 4-Byte of 32 Alarms and Warnings 1-bit flags

/******************************************************************************
 * @brief   WarningsAlarmsTurnOn
 *
 * @note
 ******************************************************************************/



#define ALARM_LONG_10SEC      80      // Type 1:      [--------][--------][--------][--------][--------][--------][--------][--------][--------][--------]
#define ALARM_SHORT_3PULSES   16      // Type 2:      [- - -   ][        ]
#define ALARM_3SHORT_3PULSES  24      // Type 3:      [- - -   ][- - -   ][- - -   ]  
#define ALARM_FIFO_SIZE       (ALARM_MAX + 1)

union AlarmUNION ALARM_ON;        // Alarm Triggers  [*](- - -     ), momentary or with memory in the future
union AlarmUNION AlarmOn;         // Current running Alarm for the condition, On lasting for one trigger Cycle, Off at the ending of alamrming cycle [- - -][     ]
union AlarmUNION AlarmState;      // Current Alarm Buzzing Sound Pulse Hi/Lo Status, the instant HIGH and LOW status of each bit  [-][ ][-][ ][-][ ]
union AlarmUNION AlarmRepeat;     // The alarm bit to inform system repeatable or not (0): no more alarm in the same dive;   (1): can repeat when same situation re-occurs
union AlarmUNION AlarmOccured;    // The Record of the alarm bits (NOT Occured bit = 0; Occured bit = 1)
union AlarmUNION Alarming;        // The Alarming Condition of the instant, disregard the alarms are turned off, disabled or muted (NOT Alarming bit = 0; Alarming bit = 1)
union AlarmUNION AlarmProfileRec; // Alarm and Violation Record buffer for Profile Record recording

uint8_t AlarmCtr[ALARM_MAX] = {0};
uint16_t AlarmRealtime[ALARM_MAX] = {0};
uint8_t AlarmInTicks[ALARM_MAX] = {0};
uint8_t AlarmFIFO[ALARM_MAX];
uint8_t CurrAlarmID = ALARM_MAX;



// to be continue later*******************************************************************************************
void Alarm_10Seonds(uint32_t *ON_Bit, uint32_t *On_bit, uint32_t *Pre_bit, uint32_t *State_bit, uint8_t *Ctr)
{

    if(*ON_Bit || *On_bit)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        *On_bit = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((*On_bit==true)&&(*Pre_bit==false))        // check if time for new alarm cycle
        {
            *Ctr=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            *ON_Bit = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        *Ctr--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if((*Ctr%8) >= 4)          // First Half Second 7,6,5,4 ON / Second Half Second 3,2,1,0 OFF
            *State_bit = true;
        else
            *State_bit = false;
        //----------------------------------------------------------------------------------------------------

        if(*Ctr==0)
        {
            *On_bit = false;
            *State_bit = false;
        }
    }

    *Pre_bit = *On_bit;
    //End of AlarmCtr[0]------------------------------------------------------------------------------------

}
// to be continue later*******************************************************************************************




/******************************************************************************
 * @brief   AlarmInit
 *
 * @note    Initialize alarms before each new dive
 ******************************************************************************/
void AlarmInit(void)
{
    uint8_t i;

    CurrAlarmID = ALARM_MAX;

    ALARM_ON.AllBits = 0x00000000;                // intialized all alarm OFF

    AlarmOn.AllBits = 0x00000000;                 // intialized all alarm OFF

    AlarmState.AllBits = 0x00000000;              // intialized all alarm OFF

    AlarmRepeat.AllBits = 0xFFFFFFFF;             // intialized repeatable for each new dive

    AlarmOccured.AllBits = 0x00000000;            // intialized all alarm NOT Occured

    Alarming.AllBits = 0x00000000;                // intialized all alarm NOT Occuring

    AlarmProfileRec.AllBits = 0x00000000;         // reset profile's alarm record

    for(i=0; i<ALARM_FIFO_SIZE; i++)
        AlarmFIFO[i]=ALARM_MAX;

    for(i=0; i<ALARM_MAX; i++)
        AlarmRealtime[i]=0;

    for(i=0; i<ALARM_MAX; i++)
        AlarmInTicks[i]=0;

    ConditionTime = 0;

}


/******************************************************************************
 * @brief   AlarmFIFO_Arrange
 *
 * @note    Mark Alarm request into AlarmFIFO queue
 ******************************************************************************/
uint8_t AlarmFIFO_Arrange(uint8_t AlarmID)
{
    uint8_t i;
    uint8_t length;       // current AlarmFIFO queue length

    i=0;
    length=0;

    if((AlarmID == ALARM_AscRate5)||(AlarmID == ALARM_AscRate4))
    {   // process the Highest Priority Alarm(s) to the front of Alarm Buffer (LIFO)

        if(AlarmFIFO[0]==ALARM_MAX)     // if AlarmFIFO buffer is empty
        {
            AlarmFIFO[0]=AlarmID; // append the new coming AlarmID into the newest cell of the AlarmFIFO
            i++;           // i increments from 0 to 1 and done
            length = i;    // length is 1
        }
        else
        {
            while(AlarmFIFO[i]!=ALARM_MAX && i<ALARM_FIFO_SIZE)
            {
                i++;
                length = i;    // length of existing alarm queue detected
            }

            for(i=length; i>=1; i--)
            {
                AlarmFIFO[i]=AlarmFIFO[i-1];  // push one position to yield the new coming AlarmID, for length size
            }

            AlarmFIFO[0]=AlarmID;  // place the new coming AlarmID into the newest cell of the AlarmFIFO

            length++;             // increment by one for the new coming placed at the front
        }
    }
    else
    {   // Process the other normal priority alarms to the end of Alarm Buffer (FIFO)

        while(AlarmFIFO[i]!=ALARM_MAX && i<ALARM_FIFO_SIZE)
        {
            i++;           // counting the length of the existing queues
            length = i;    // length of existing alarm queue detected
        }

        AlarmFIFO[i]=AlarmID; // append the new coming AlarmID into the newest cell of the AlarmFIFO
    }

    return length;        // output the current length of the queue
}


/******************************************************************************
 * @brief   AlarmFIFO_Process
 *
 * @note    Process Alarm request from AlarmFIFO queue
 ******************************************************************************/
uint8_t AlarmFIFO_Process(void)
{
    static uint8_t AlarmID = ALARM_MAX;
    uint8_t i;


    // do next alarm when the previous alarm is completely done
    if((ALARM_ON.AllBits==0) && (AlarmOn.AllBits==0))
    {
        AlarmID = AlarmFIFO[0];       // processing the

        switch(AlarmID)
        {
        //----- [10 long beeps, no repeat at the same dive]---------------
        case ALARM_CondiVio:
            ALARM_ON.Bit.CondiVio = true;
            AlarmOccured.Bit.CondiVio = true;
            break;
        case ALARM_DelayedVio1:
            ALARM_ON.Bit.DelayedVio1 = true;
            AlarmOccured.Bit.DelayedVio1 = true;
            break;
        case ALARM_DelayedVio2:
            ALARM_ON.Bit.DelayedVio2 = true;
            AlarmOccured.Bit.DelayedVio2 = true;
            break;
        case ALARM_O2_80Pct:
            ALARM_ON.Bit.O2_80Pct = true;
            AlarmOccured.Bit.O2_80Pct = true;
            break;
        case ALARM_O2_100Pct:
            ALARM_ON.Bit.O2_100Pct = true;
            AlarmOccured.Bit.O2_100Pct = true;
            break;
        case ALARM_DiveTime:
            ALARM_ON.Bit.DiveTime = true;
            AlarmOccured.Bit.DiveTime = true;
            break;

        //----- [10 long beeps, repeatable at the same dive]---------------
        case ALARM_DepthMax:
            ALARM_ON.Bit.DepthMax = true;
            AlarmOccured.Bit.DepthMax = true;
            break;
        case ALARM_AscRate5:
            ALARM_ON.Bit.AscRate5 = true;
            AlarmOccured.Bit.AscRate5 = true;
            break;
        case ALARM_PO2NearSetPoint:
            ALARM_ON.Bit.PO2NearSetPoint = true;
            AlarmOccured.Bit.PO2NearSetPoint = true;
            break;
        case ALARM_PO2AtSetPoint:
            ALARM_ON.Bit.PO2AtSetPoint = true;
            AlarmOccured.Bit.PO2AtSetPoint = true;
            break;
        case ALARM_DepthSet:
            ALARM_ON.Bit.DepthSet = true;
            AlarmOccured.Bit.DepthSet = true;
            break;
        case ALARM_DiveN2Bar:
            ALARM_ON.Bit.DiveN2Bar = true;
            AlarmOccured.Bit.DiveN2Bar = true;
            break;
        case ALARM_DECO_Entry:
            ALARM_ON.Bit.DECO_Entry = true;
            AlarmOccured.Bit.DECO_Entry = true;
            break;
        case ALARM_DiveDTR:
            ALARM_ON.Bit.DiveDTR = true;
            AlarmOccured.Bit.DiveDTR = true;
            break;

        //----- [3 short beeps, repeatable at the same dive]----------------
        case ALARM_AscRate4:
            ALARM_ON.Bit.AscRate4 = true;
            AlarmOccured.Bit.AscRate4 = true;
            break;
        case ALARM_FreeDiveT:
            ALARM_ON.Bit.FreeDiveT = true;
            AlarmOccured.Bit.FreeDiveT = true;
            break;

        //----- [3 short beeps x 3 times, repeatable at the same dive]------
        case ALARM_FreeDepth1:
            ALARM_ON.Bit.FreeDepth1 = true;
            AlarmOccured.Bit.FreeDepth1 = true;
            break;
        case ALARM_FreeDepth2:
            ALARM_ON.Bit.FreeDepth2 = true;
            AlarmOccured.Bit.FreeDepth2 = true;
            break;
        case ALARM_FreeDepth3:
            ALARM_ON.Bit.FreeDepth3 = true;
            AlarmOccured.Bit.FreeDepth3 = true;
            break;
        case ALARM_FreeN2Bar:
            ALARM_ON.Bit.FreeN2Bar = true;
            AlarmOccured.Bit.FreeN2Bar = true;
            break;
        case ALARM_FreeCDT:
            ALARM_ON.Bit.FreeCDT = true;
            AlarmOccured.Bit.FreeCDT = true;
            break;
        case ALARM_FreeViol:
            ALARM_ON.Bit.FreeViol = true;
            AlarmOccured.Bit.FreeViol = true;
            break;

        //----- [10 long beeps, repeatable at the same dive]---------------
        case ALARM_DECO_Depth70:
            ALARM_ON.Bit.DECO_Depth70 = true;
            AlarmOccured.Bit.DECO_Depth70 = true;
            break;

        case ALARM_SwitchFO2:
            ALARM_ON.Bit.SwitchFO2 = true;
            AlarmOccured.Bit.SwitchFO2 = true;
            break;

        //----- [others]------
        case ALARM_SetupVIOLATION:
            ALARM_ON.Bit.SetupVIOLATION = true;
            AlarmOccured.Bit.SetupVIOLATION = true;
            break;

        case ALARM_LowBatteryWaning:
            ALARM_ON.Bit.LowBattWarning = true;
            AlarmOccured.Bit.LowBattWarning = true;
            break;

        case ALARM_LowBatteryAlarm:
            ALARM_ON.Bit.LowBattAlarm = true;
            AlarmOccured.Bit.LowBattAlarm = true;
            break;

        //----- [default, including ALARM_MAX for empty queue, no alarm needed]------
        default:

            break;

        }

        // remove the oldest alarm already addressed, pop up one position for each remaining alarm(s) to do next
        i=0;

        while((AlarmFIFO[i]!=ALARM_MAX)&&(i<(ALARM_MAX-1)))
        {
            AlarmFIFO[i]=AlarmFIFO[i+1];

            i++;           // counting the length of the existing queues
        }

    }

    return AlarmID;
}


/******************************************************************************
 * @brief   StopTheBuzzingAlarm
 *
 * @note    Stop the currently active alarm (and start the next one if any)
 ******************************************************************************/
void StopTheBuzzingAlarm(void)
{
    /******************************************************************************************
        the way alarm stop is like following

          AlarmCtr[X]--;

          if(AlarmCtr[X]==0)
          {
            AlarmOn.Bit.X = false;
            AlarmState.Bit.X = false;
          }

        so, assigning 'AlarmCtr[X] = 1;', the X alarm would turn itself OFF within 125 mSec

    *******************************************************************************************/

    AlarmCtr[CurrAlarmID] = 1; // to turn OFF alarm in the next step

}



/******************************************************************************
 * @brief   WarningsAlarmsManager
 *
 * @note    Process Alarm Signals
 ******************************************************************************/
void WarningsAlarmsManager(void)
{

    static union AlarmUNION PreAlarmOn;   // Previous Alarm Status


    ImmediateStopAlarmCheck();


    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {
        // Start of Alarm Linking Interface ==============================================================================
        if(USER_Set.DiveMode==NVD_MDSCUBA)
        {
            //----bit-CondiVio------------------------------------------------------------------
            // shall enter CV and remain in CV from 0 second up to 5 minutes (300 seconds)  (not repeatable???)
            if(((ConditionTime > 0)&&(ConditionTime < 300))||((DVSTAT&0xF0)==0x70))
            {
                AlarmRealtime[ALARM_CondiVio]++;
                AlarmInTicks[ALARM_CondiVio]=TICK_ID_PLUS_1;
                Alarming.Bit.CondiVio = true;
                AlarmOccured.Bit.CondiVio = true;

                if(AlarmRepeat.Bit.CondiVio == true)
                {
                    AlarmFIFO_Arrange(ALARM_CondiVio);
                    AlarmRepeat.Bit.CondiVio = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_CondiVio]=0;
                AlarmInTicks[ALARM_CondiVio]=0;
                Alarming.Bit.CondiVio = false;
            }
            //----bit-CondiVio------------------------------------------------------------------


            //----bit-DelayedVio1------------------------------------------------------------------
            // disregards a CV and for over 5 minutes (300 seconds)
            if((DelayFlag & 0x02)==0x02)
            {
                AlarmRealtime[ALARM_DelayedVio1]++;
                AlarmInTicks[ALARM_DelayedVio1]=TICK_ID_PLUS_1;
                Alarming.Bit.DelayedVio1 = true;
                AlarmOccured.Bit.DelayedVio1 = true;

                if(AlarmRepeat.Bit.DelayedVio1 == true)
                {
                    AlarmFIFO_Arrange(ALARM_DelayedVio1);
                    AlarmRepeat.Bit.DelayedVio1 = false; // stop, and not repeatable throughout the same dive
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DelayedVio1]=0;
                AlarmInTicks[ALARM_DelayedVio1]=0;
                Alarming.Bit.DelayedVio1 = false;
            }
            //----bit-DelayedVio1------------------------------------------------------------------


            //----bit-DelayedVio2------------------------------------------------------------------
            // When Deco requires a Stop Depth deeper than 60 FT (18 M), but less than 70 FT (21 M) (not repeatable???)
            if(USER_Set.Units==NVD_IMPERIAL)
            {
                if(DecoStop[1]==60)     // When Deco requires a Stop Depth deeper than 60 FT (18 M), but less than 70 FT (21 M)
                {
                    AlarmRealtime[ALARM_DelayedVio2]++;
                    AlarmInTicks[ALARM_DelayedVio2]=TICK_ID_PLUS_1;
                    Alarming.Bit.DelayedVio2 = true;
                    AlarmOccured.Bit.DelayedVio2 = true;

                    if(AlarmRepeat.Bit.DelayedVio2 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DelayedVio2);
                        AlarmRepeat.Bit.DelayedVio2 = false; // stop, and not repeatable throughout the same dive
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DelayedVio2]=0;
                    AlarmInTicks[ALARM_DelayedVio2]=0;
                    Alarming.Bit.DelayedVio2 = false;
                }
            }
            else
            {
                if(DecoStop[1]==60)     // When Deco requires a Stop Depth deeper than 60 FT (18 M), but less than 70 FT (21 M)
                {
                    AlarmRealtime[ALARM_DelayedVio2]++;
                    AlarmInTicks[ALARM_DelayedVio2]=TICK_ID_PLUS_1;
                    Alarming.Bit.DelayedVio2 = true;
                    AlarmOccured.Bit.DelayedVio2 = true;

                    if(AlarmRepeat.Bit.DelayedVio2 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DelayedVio2);
                        AlarmRepeat.Bit.DelayedVio2 = false; // stop, and not repeatable throughout the same dive
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DelayedVio2]=0;
                    AlarmInTicks[ALARM_DelayedVio2]=0;
                    Alarming.Bit.DelayedVio2 = false;
                }
            }
            //----bit-DelayedVio2------------------------------------------------------------------
        }   // End of if(USER_Set.DiveMode==NVD_MDSCUBA)



        //----bit-DepthMax---------------------------------------------------------------------
        // (Out Of Range Depth) of 330 FT (99.9 M) in DIVE, GAUGE or FREE is exceeded
        if(USER_Set.Units==NVD_IMPERIAL)
        {
            if(Dive_Info.WaterDepth_ft < 330)
                AlarmRepeat.Bit.DepthMax = true;

            if(Dive_Info.WaterDepth_ft >= 330)
            {
                AlarmRealtime[ALARM_DepthMax]++;
                AlarmInTicks[ALARM_DepthMax]=TICK_ID_PLUS_1;
                Alarming.Bit.DepthMax = true;
                AlarmOccured.Bit.DepthMax = true;

                if(AlarmRepeat.Bit.DepthMax == true)
                {
                    AlarmFIFO_Arrange(ALARM_DepthMax);
                    AlarmRepeat.Bit.DepthMax = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DepthMax]=0;
                AlarmInTicks[ALARM_DepthMax]=0;
                Alarming.Bit.DepthMax = false;
            }
        }
        else
        {
            if(Dive_Info.WaterDepth_m < 100)
                AlarmRepeat.Bit.DepthMax = true;

            if(Dive_Info.WaterDepth_m >= 100)
            {
                AlarmRealtime[ALARM_DepthMax]++;
                AlarmInTicks[ALARM_DepthMax]=TICK_ID_PLUS_1;
                Alarming.Bit.DepthMax = true;
                AlarmOccured.Bit.DepthMax = true;

                if(AlarmRepeat.Bit.DepthMax == true)
                {
                    AlarmFIFO_Arrange(ALARM_DepthMax);
                    AlarmRepeat.Bit.DepthMax = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DepthMax]=0;
                AlarmInTicks[ALARM_DepthMax]=0;
                Alarming.Bit.DepthMax = false;
            }
        }
        //----bit-DepthMax--------------------------------------------------------------------


        if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDGAUGE))    // do not do AscRate4 and AscRate5 if Free Dive
        {

            //----bit-AscRate5--------------------------------------------------------------------
            // AscRate4 is only allowed to resume when ASCBGVal ever below 4 and retrigger again.
            if(ASCBGVal < 5)
                AlarmRepeat.Bit.AscRate5 = true;

            if(ASCBGVal >= 5)
            {
                AlarmRealtime[ALARM_AscRate5]++;
                AlarmInTicks[ALARM_AscRate5]=TICK_ID_PLUS_1;
                Alarming.Bit.AscRate5 = true;

                if((AlarmRepeat.Bit.AscRate5 == true)&&(LCD_Flash.Bit.ASCBar==true))  // to sync-up with LCD_Flash.Bit.ASCBar ASCBar-5 flashing
                {
                    AlarmFIFO_Arrange(ALARM_AscRate5);
                    AlarmRepeat.Bit.AscRate5 = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_AscRate5]=0;
                AlarmInTicks[ALARM_AscRate5]=0;
                Alarming.Bit.AscRate5 = false;
            }
            //----bit-AscRate5--------------------------------------------------------------------


            //----bit-AscRate4--------------------------------------------------------------------
            // AscRate4 is only allowed to resume when ASCBGVal ever below 4 and retrigger again.
            if(ASCBGVal < 4)
                AlarmRepeat.Bit.AscRate4 = true;  // AscRate4 is only allowed to resume when ASCBGVal ever below 4 and retrigger again.

            if(ASCBGVal > 3)
            {
                AlarmRealtime[ALARM_AscRate4]++;
                AlarmInTicks[ALARM_AscRate4]=TICK_ID_PLUS_1;
                Alarming.Bit.AscRate4 = true;

                if(AlarmRepeat.Bit.AscRate4 == true)
                {
                    AlarmFIFO_Arrange(ALARM_AscRate4);
                    AlarmRepeat.Bit.AscRate4 = false; // stop for each cycle
                }
            }
            else
            {
                AlarmRealtime[ALARM_AscRate4]=0;
                AlarmInTicks[ALARM_AscRate4]=0;
                Alarming.Bit.AscRate4 = false;
            }
            //----bit-AscRate4--------------------------------------------------------------------

        } // End if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDGAUGE))



        //----bit-PO2NearSetPoint (commented out from i330R's new spec.)----------------------
        //if((Dive_Info.DiveTime_s > 10) && ((100*PO2atDepth) > (SCUBA_Set.PO2A[0]-20)) && (AlarmRepeat.Bit.PO2NearSetPoint == true))
        //{
        //  AlarmFIFO_Arrange(ALARM_PO2NearSetPoint);
        //  AlarmRepeat.Bit.PO2NearSetPoint = false; // stop for each cycle
        //}
        //----bit-PO2NearSetPoint-------------------------------------------------------------


        if(USER_Set.DiveMode==NVD_MDSCUBA)
        {
            //----bit-PO2AtSetPoint------------------------------------------------------------------
            // PO2 increases to the Alarm Set Point
            if(  ((CURRENT_TANK_NUM==1)&&((100*PO2atDepth)<SCUBA_Set.PO2A[1]))  //    whenever assending above threshold of current Tank = Tank1
                    ||((CURRENT_TANK_NUM==2)&&((100*PO2atDepth)<SCUBA_Set.PO2A[2]))  // or whenever assending above threshold of current Tank = Tank2
                    ||((CURRENT_TANK_NUM==3)&&((100*PO2atDepth)<SCUBA_Set.PO2A[3]))  ) // or whenever assending above threshold of current Tank = Tank3
            {
                AlarmRepeat.Bit.PO2AtSetPoint = true;  // PO2AtSetPoint is only allowed to resume after PO2atDepth < PO2AtSetPoint again.
            }

            if( (Dive_Info.DiveTime_s > 10)     // make sure PO2 alarm triggered during diving
                    &&( ((SCUBA_Set.FO2A[CURRENT_TANK_NUM]>=21)&&(100*PO2atDepth >= (SCUBA_Set.PO2A[CURRENT_TANK_NUM])))    // for FO2 = 21% to 100%, , Alarm threshold is calculated at PO2A[0]
                        ||((SCUBA_Set.FO2A[CURRENT_TANK_NUM]<21)&&(100*PO2atDepth >= 160))) )                  // for AIR, Alarm threshold fixed at 1.60
            {
                AlarmRealtime[ALARM_PO2AtSetPoint]++;
                AlarmInTicks[ALARM_PO2AtSetPoint]=TICK_ID_PLUS_1;
                Alarming.Bit.PO2AtSetPoint = true;

                if(AlarmRepeat.Bit.PO2AtSetPoint == true)
                {
                    AlarmFIFO_Arrange(ALARM_PO2AtSetPoint);
                    AlarmRepeat.Bit.PO2AtSetPoint = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_PO2AtSetPoint]=0;
                AlarmInTicks[ALARM_PO2AtSetPoint]=0;
                Alarming.Bit.PO2AtSetPoint = false;
            }
            //----bit-PO2AtSetPoint------------------------------------------------------------------
        } // End if(USER_Set.DiveMode==NVD_MDSCUBA)

        if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDGAUGE))    // for Scuba and Gauge Dives only, not for Free Dive anymore after 2021/01/19
        {
            //----bit-ALARM_DepthSet------------------------------------------------------------------
            // Depth > DepthAlarmSetPoint
            if(USER_Set.Units==NVD_IMPERIAL)
            {
                if(Dive_Info.WaterDepth_ft < (float)DEPTHAL_FT)
                    AlarmRepeat.Bit.DepthSet = true;  // DepthSet is only allowed to resume after Depth < DepthSet again.

                if((Dive_Info.WaterDepth_ft >= (float)DEPTHAL_FT)&&(DEPTHAL_FT > 0))     // (DEPTHAL_M > 0) is the On/Off switch
                {
                    AlarmRealtime[ALARM_DepthSet]++;
                    AlarmInTicks[ALARM_DepthSet]=TICK_ID_PLUS_1;
                    Alarming.Bit.DepthSet = true;

                    if(AlarmRepeat.Bit.DepthSet == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DepthSet);
                        AlarmRepeat.Bit.DepthSet = false; // stop for each cycle
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DepthSet]=0;
                    AlarmInTicks[ALARM_DepthSet]=0;
                    Alarming.Bit.DepthSet = false;
                }
            }
            else
            {
                if(Dive_Info.WaterDepth_m < (float)DEPTHAL_M)
                    AlarmRepeat.Bit.DepthSet = true;  // DepthSet is only allowed to resume after Depth < DepthSet again.

                if((Dive_Info.WaterDepth_m >= (float)DEPTHAL_M)&&(DEPTHAL_M > 0))     // (DEPTHAL_M > 0) is the On/Off switch
                {
                    AlarmRealtime[ALARM_DepthSet]++;
                    AlarmInTicks[ALARM_DepthSet]=TICK_ID_PLUS_1;
                    Alarming.Bit.DepthSet = true;

                    if(AlarmRepeat.Bit.DepthSet == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DepthSet);
                        AlarmRepeat.Bit.DepthSet = false; // stop for each cycle
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DepthSet]=0;
                    AlarmInTicks[ALARM_DepthSet]=0;
                    Alarming.Bit.DepthSet = false;
                }
            }
            //----bit-ALARM_DepthSet------------------------------------------------------------------
        }

        if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDFREE))
        {

            //----bit-DiveN2Bar------------------------------------------------------------------
            // N2Bar Over the alarm set point
            if(TLBGVal < N2BAR_AL)
                AlarmRepeat.Bit.DiveN2Bar = true;  // TLBG_Alarm is only allowed to resume after TLBGVal < TLBG_Alarm again.

            if((TLBGVal >= N2BAR_AL)&&(N2BAR_AL > 0))       // // (N2BAR_AL > 0) is On/Off switch
            {
                AlarmRealtime[ALARM_DiveN2Bar]++;
                AlarmInTicks[ALARM_DiveN2Bar]=TICK_ID_PLUS_1;
                Alarming.Bit.DiveN2Bar = true;

                if(AlarmRepeat.Bit.DiveN2Bar == true)
                {
                    AlarmFIFO_Arrange(ALARM_DiveN2Bar);
                    AlarmRepeat.Bit.DiveN2Bar = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DiveN2Bar]=0;
                AlarmInTicks[ALARM_DiveN2Bar]=0;
                Alarming.Bit.DiveN2Bar = false;
            }
            //----bit-DiveN2Bar------------------------------------------------------------------
        } // End if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDFREE))

        if(USER_Set.DiveMode==NVD_MDSCUBA)
        {

            //----bit-O2_80Pct------------------------------------------------------------------
            // DIVE O2 at 80% (not repeatable???)
            if((OTUpercent >= 80)&&(OTUpercent < 100)&&(FO2_GASx > 20)&&((DVSTAT&0xF0)!=0x80))        // > 80% O2, Non-AIR-Dive, and Not On during VIOTLATION
            {
                AlarmRealtime[ALARM_O2_80Pct]++;
                AlarmInTicks[ALARM_O2_80Pct]=TICK_ID_PLUS_1;
                Alarming.Bit.O2_80Pct = true;

                if(AlarmRepeat.Bit.O2_80Pct == true)
                {
                    AlarmFIFO_Arrange(ALARM_O2_80Pct);
                    AlarmRepeat.Bit.O2_80Pct = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_O2_80Pct]=0;
                AlarmInTicks[ALARM_O2_80Pct]=0;
                Alarming.Bit.O2_80Pct = false;
            }
            //----bit-O2_80Pct------------------------------------------------------------------
        } // End if(USER_Set.DiveMode==NVD_MDSCUBA)
    }   // End if(Dive_Info.Status==AMB_DIVEINFO_DIVE)

    if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE))
    {
        if(USER_Set.DiveMode==NVD_MDSCUBA)
        {

            //----bit-O2_100Pct------------------------------------------------------------------
            // DIVE O2 at 100% (not repeatable???)
            if((OTUpercent >= 100)&&(FO2_GASx > 20)&&((DVSTAT&0xF0)!=0x80))    // > 100% O2, Non-AIR-Dive, and Not On during VIOTLATION
            {
                AlarmRealtime[ALARM_O2_100Pct]++;
                AlarmInTicks[ALARM_O2_100Pct]=TICK_ID_PLUS_1;
                Alarming.Bit.O2_100Pct = true;
                if(AlarmRepeat.Bit.O2_100Pct == true)
                {
                    AlarmFIFO_Arrange(ALARM_O2_100Pct);
                    AlarmRepeat.Bit.O2_100Pct = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_O2_100Pct]=0;
                AlarmInTicks[ALARM_O2_100Pct]=0;
                Alarming.Bit.O2_100Pct = false;
            }
            //----bit-O2_100Pct------------------------------------------------------------------
        }
    }   // End  if((Dive_Info.Status==AMB_DIVEINFO_DIVE)||(Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)||(Dive_Info.Status==AMB_DIVEINFO_SURF))


    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {

        if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDFREE))
        {
            //----bit-DECO_Entry------------------------------------------------------------------
            static uint8_t DV_AtDeco = 0x20;

            DV_AtDeco = (DVSTAT & 0xF0);
            // to detect the moment entrying Deco-Mode from Non-Deco-Mode
            if(DecoTime[1] == 0)        // if Deco conition removed, re-enable the repeat of Deco-Entry alarm
                AlarmRepeat.Bit.DECO_Entry = true;

            if((DV_AtDeco == 0x60)&&(DecoTime[1]!=0)&&(AlarmOccured.Bit.CondiVio!=true)
                    &&(AlarmOccured.Bit.DelayedVio1!=true)&&(AlarmOccured.Bit.DelayedVio2!=true)&&(AlarmOccured.Bit.DepthMax!=true))
            {
                AlarmRealtime[ALARM_DECO_Entry]++;
                AlarmInTicks[ALARM_DECO_Entry]=TICK_ID_PLUS_1;
                Alarming.Bit.DECO_Entry = true;

                if(AlarmRepeat.Bit.DECO_Entry == true)
                {
                    AlarmFIFO_Arrange(ALARM_DECO_Entry);
                    AlarmRepeat.Bit.DECO_Entry = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DECO_Entry]=0;
                AlarmInTicks[ALARM_DECO_Entry]=0;
                Alarming.Bit.DECO_Entry = false;
            }
            //----bit-DECO_Entry------------------------------------------------------------------
        }

        if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDGAUGE))
        {

            //----bit-DiveTime------------------------------------------------------------------
            if((Dive_Info.DiveTime_s >= (int16_t)60*DIVE_T_AL)&&(DIVE_T_AL > 0))    // (DIVE_T_AL > 0) is On/Off switch
            {
                AlarmRealtime[ALARM_DiveTime]++;
                AlarmInTicks[ALARM_DiveTime]=TICK_ID_PLUS_1;
                Alarming.Bit.DiveTime = true;

                if(AlarmRepeat.Bit.DiveTime == true)
                {
                    AlarmFIFO_Arrange(ALARM_DiveTime);
                    AlarmRepeat.Bit.DiveTime = false; // stop for each cycle
                }
            }
            else // for GUI
            {
                AlarmRealtime[ALARM_DiveTime]=0;
                AlarmInTicks[ALARM_DiveTime]=0;
                Alarming.Bit.DiveTime = false;
            }
            //----bit-DiveTime------------------------------------------------------------------
        }

        if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDFREE))
        {

            //----bit-DiveDTR------------------------------------------------------------------
            uint16_t DTR;
            if((Dive_Info.DiveTime_s > 10))
            {
                if(NDT_Data <= otrTime)
                    DTR = NDT_Data;
                else
                    DTR = otrTime;

                if(DTR > (int16_t)DTR_AL)
                    AlarmRepeat.Bit.DiveDTR = true;       // DiveDTR is only allowed to resume after DTR > SCUBA_Set.DTR_Alarm

                if((DTR <= (int16_t)DTR_AL)&&(DTR_AL > 0)&&((DVSTAT&0xF0)!=0x80))    // (DTR_AL > 0) is On/Off switch, and Not On during VIOTLATION
                {
                    AlarmRealtime[ALARM_DiveDTR]++;
                    AlarmInTicks[ALARM_DiveDTR]=TICK_ID_PLUS_1;
                    Alarming.Bit.DiveDTR = true;

                    if(AlarmRepeat.Bit.DiveDTR == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DiveDTR);
                        AlarmRepeat.Bit.DiveDTR = false; // stop for each cycle
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DiveDTR]=0;
                    AlarmInTicks[ALARM_DiveDTR]=0;
                    Alarming.Bit.DiveDTR = false;
                }
            }
            //----bit-DiveDTR------------------------------------------------------------------
        } // End if((USER_Set.DiveMode==NVD_MDSCUBA)||(USER_Set.DiveMode==NVD_MDFREE))


        //----bit-FreeDiveT--------------------------------------------------------------------
        if((USER_Set.DiveMode == NVD_MDFREE)&&(Dive_Info.DiveTime_s > 10)&&((Dive_Info.DiveTime_s % FREE_ALARM_DIVE_T)==0)&&(FREE_ALARM_DIVE_T > 0))  // avoid initial value = 0
        {
            AlarmRealtime[ALARM_FreeDiveT]++;
            AlarmInTicks[ALARM_FreeDiveT]=TICK_ID_PLUS_1;
            Alarming.Bit.FreeDiveT = true;

            if(AlarmRepeat.Bit.FreeDiveT == true)
            {
                AlarmFIFO_Arrange(ALARM_FreeDiveT);
                AlarmRepeat.Bit.FreeDiveT = false; // stop for each cycle
            }
        }
        else
        {
            AlarmRealtime[ALARM_FreeDiveT]=0;
            AlarmInTicks[ALARM_FreeDiveT]=0;
            Alarming.Bit.FreeDiveT = false;
        }
        //----bit-FreeDiveT--------------------------------------------------------------------



        //----bit-FreeDepth1--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(USER_Set.Units==NVD_IMPERIAL)
            {
                if(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH1_FT)
                    AlarmRepeat.Bit.FreeDepth1 = true;      // is allowed to resume when FreeDepth1 is shallower than the retrigger FREE_ALARM_DEPTH1_FT again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft >= (float)FREE_ALARM_DEPTH1_FT)&&(FREE_ALARM_DEPTH1_FT > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth1]++;
                    AlarmInTicks[ALARM_FreeDepth1]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth1 = true;

                    if(AlarmRepeat.Bit.FreeDepth1 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth1);
                        AlarmRepeat.Bit.FreeDepth1 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth1]=0;
                    AlarmInTicks[ALARM_FreeDepth1]=0;
                    Alarming.Bit.FreeDepth1 = false;
                }
            }
            else
            {
                if(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH1_M)
                    AlarmRepeat.Bit.FreeDepth1 = true;      // is allowed to resume when FreeDepth1 is shallower than the retrigger FREE_ALARM_DEPTH1_M again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m >= (float)FREE_ALARM_DEPTH1_M)&&(FREE_ALARM_DEPTH1_M > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth1]++;
                    AlarmInTicks[ALARM_FreeDepth1]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth1 = true;

                    if(AlarmRepeat.Bit.FreeDepth1 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth1);
                        AlarmRepeat.Bit.FreeDepth1 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth1]=0;
                    AlarmInTicks[ALARM_FreeDepth1]=0;
                    Alarming.Bit.FreeDepth1 = false;
                }
            }
        }
        //----bit-FreeDepth1--------------------------------------------------------------------

        //----bit-FreeDepth2--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(USER_Set.Units==NVD_IMPERIAL)
            {
                if(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH2_FT)
                    AlarmRepeat.Bit.FreeDepth2 = true;      // is allowed to resume when FreeDepth2 is shallower than the retrigger FREE_ALARM_DEPTH2_FT again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft >= (float)FREE_ALARM_DEPTH2_FT)&&(FREE_ALARM_DEPTH2_FT > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth2]++;
                    AlarmInTicks[ALARM_FreeDepth2]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth2 = true;

                    if(AlarmRepeat.Bit.FreeDepth2 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth2);
                        AlarmRepeat.Bit.FreeDepth2 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth2]=0;
                    AlarmInTicks[ALARM_FreeDepth2]=0;
                    Alarming.Bit.FreeDepth2 = false;
                }
            }
            else
            {
                if(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH2_M)
                    AlarmRepeat.Bit.FreeDepth2 = true;      // is allowed to resume when FreeDepth2 is shallower than the retrigger FREE_ALARM_DEPTH2_M again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m >= (float)FREE_ALARM_DEPTH2_M)&&(FREE_ALARM_DEPTH2_M > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth2]++;
                    AlarmInTicks[ALARM_FreeDepth2]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth2 = true;

                    if(AlarmRepeat.Bit.FreeDepth2 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth2);
                        AlarmRepeat.Bit.FreeDepth2 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth2]=0;
                    AlarmInTicks[ALARM_FreeDepth2]=0;
                    Alarming.Bit.FreeDepth2 = false;
                }
            }
        }
        //----bit-FreeDepth2--------------------------------------------------------------------

        //----bit-FreeDepth3--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(USER_Set.Units==NVD_IMPERIAL)
            {
                if(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH3_FT)
                    AlarmRepeat.Bit.FreeDepth3 = true;      // is allowed to resume when FreeDepth3 is shallower than the retrigger FREE_ALARM_DEPTH3_FT again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft >= (float)FREE_ALARM_DEPTH3_FT)&&(FREE_ALARM_DEPTH3_FT > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth3]++;
                    AlarmInTicks[ALARM_FreeDepth3]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth3 = true;

                    if(AlarmRepeat.Bit.FreeDepth3 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth3);
                        AlarmRepeat.Bit.FreeDepth3 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth3]=0;
                    AlarmInTicks[ALARM_FreeDepth3]=0;
                    Alarming.Bit.FreeDepth3 = false;
                }
            }
            else
            {
                if(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH3_M)
                    AlarmRepeat.Bit.FreeDepth3= true;      // is allowed to resume when FreeDepth3 is shallower than the retrigger FREE_ALARM_DEPTH3_M again.

                if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m >= (float)FREE_ALARM_DEPTH3_M)&&(FREE_ALARM_DEPTH3_M > 0))
                {
                    AlarmRealtime[ALARM_FreeDepth3]++;
                    AlarmInTicks[ALARM_FreeDepth3]=TICK_ID_PLUS_1;
                    Alarming.Bit.FreeDepth3 = true;

                    if(AlarmRepeat.Bit.FreeDepth3 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_FreeDepth3);
                        AlarmRepeat.Bit.FreeDepth3 = false; // stop for each cycle
                    }
                }
                else
                {
                    AlarmRealtime[ALARM_FreeDepth3]=0;
                    AlarmInTicks[ALARM_FreeDepth3]=0;
                    Alarming.Bit.FreeDepth3 = false;
                }
            }
        }
        //----bit-FreeDepth3--------------------------------------------------------------------



        //----bit-FreeN2Bar--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(TLBGVal < SCUBA_Set.TLBG_Alarm)
                AlarmRepeat.Bit.FreeN2Bar = true;  // TLBG_Alarm is only allowed to resume after TLBGVal < TLBG_Alarm again.

            if((TLBGVal >= SCUBA_Set.TLBG_Alarm)&&(SCUBA_Set.TLBG_Alarm > 0))
            {
                AlarmRealtime[ALARM_FreeN2Bar]++;
                AlarmInTicks[ALARM_FreeN2Bar]=TICK_ID_PLUS_1;
                Alarming.Bit.FreeN2Bar = true;

                if(AlarmRepeat.Bit.FreeN2Bar == true)
                {
                    AlarmFIFO_Arrange(ALARM_FreeN2Bar);
                    AlarmRepeat.Bit.FreeN2Bar = false; // stop for each cycle
                }
            }
            else
            {
                AlarmRealtime[ALARM_FreeN2Bar]=0;
                AlarmInTicks[ALARM_FreeN2Bar]=0;
                Alarming.Bit.FreeN2Bar = false;
            }
        }
        //----bit-FreeN2Bar--------------------------------------------------------------------
    }

    //----bit-FreeCDT--------------------------------------------------------------------
    if(CDT_TIMER_Run!=true)
        AlarmRepeat.Bit.FreeCDT = true;  // when CDT_TIMER_Run==false, that mean CDT Timer has been stop or reset before having a chance to run again

    if(USER_Set.DiveMode==NVD_MDFREE)
    {
        if((CDT_TIMER_Enable==true)&&(CDT_TIMER_Run==true)&&(CDT_TIMER_Alarm==true)&&(FREE_CDT_ALARM_S > 0))  // Turned ON, Countdown to 0, and set non-zero
        {
            AlarmRealtime[ALARM_FreeCDT]++;
            AlarmInTicks[ALARM_FreeCDT]=TICK_ID_PLUS_1;
            Alarming.Bit.FreeCDT = true;

            if(AlarmRepeat.Bit.FreeCDT == true)
            {
                AlarmFIFO_Arrange(ALARM_FreeCDT);
                AlarmRepeat.Bit.FreeCDT = false; // stop for each cycle
            }
        }
        else
        {
            AlarmRealtime[ALARM_FreeCDT]=0;
            AlarmInTicks[ALARM_FreeCDT]=0;
            Alarming.Bit.FreeCDT = false;
        }
    }
    //----bit-FreeCDT--------------------------------------------------------------------

    if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
    {
        //----bit-FreeViol--------------------------------------------------------------------
        if(USER_Set.DiveMode==NVD_MDFREE)
        {
            if(DecoStop[1]!=0)
            {
                AlarmRealtime[ALARM_FreeViol]++;
                AlarmInTicks[ALARM_FreeViol]=TICK_ID_PLUS_1;
                Alarming.Bit.FreeViol = true;

                if(AlarmRepeat.Bit.FreeViol == true)
                {
                    AlarmFIFO_Arrange(ALARM_FreeViol);
                    AlarmRepeat.Bit.FreeViol = false; // stop for each cycle
                }
            }
            else
            {
                AlarmRealtime[ALARM_FreeViol]=0;
                AlarmInTicks[ALARM_FreeViol]=0;
                Alarming.Bit.FreeViol = false;
            }
        }
        //----bit-FreeViol--------------------------------------------------------------------


        if(USER_Set.DiveMode==NVD_MDSCUBA)
        {
            //----bit-DECO_Depth70--------------------------------------------------------------------
            if(USER_Set.Units==NVD_IMPERIAL)
            {
                if((DecoStop[1]>=70)||((DVSTAT&0xF0)==0x80))     // When Deco requires a Stop Depth deeper than 70 FT (21 M), or ALGO reports Immediate Violation VGM
                {
                    AlarmRealtime[ALARM_DECO_Depth70]++;
                    AlarmInTicks[ALARM_DECO_Depth70]=TICK_ID_PLUS_1;
                    Alarming.Bit.DECO_Depth70 = true;
                    AlarmOccured.Bit.SetupVIOLATION = true;

                    if(AlarmRepeat.Bit.DECO_Depth70 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DECO_Depth70);
                        AlarmRepeat.Bit.DECO_Depth70 = false; // stop, and not repeatable throughout the same dive
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DECO_Depth70]=0;
                    AlarmInTicks[ALARM_DECO_Depth70]=0;
                    Alarming.Bit.DECO_Depth70 = false;
                }
            }
            else
            {
                if((DecoStop[1]>=70)||((DVSTAT&0xF0)==0x80))     // When Deco requires a Stop Depth deeper than 70 FT (21 M)
                {
                    AlarmRealtime[ALARM_DECO_Depth70]++;
                    AlarmInTicks[ALARM_DECO_Depth70]=TICK_ID_PLUS_1;
                    Alarming.Bit.DECO_Depth70 = true;
                    AlarmOccured.Bit.SetupVIOLATION = true;

                    if(AlarmRepeat.Bit.DECO_Depth70 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_DECO_Depth70);
                        AlarmRepeat.Bit.DECO_Depth70 = false; // stop, and not repeatable throughout the same dive
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_DECO_Depth70]=0;
                    AlarmInTicks[ALARM_DECO_Depth70]=0;
                    Alarming.Bit.DECO_Depth70 = false;
                }
            }
            //----bit-DECO_Depth70--------------------------------------------------------------------


            //----bit-SwitchFO2--------------------------------------------------------------------
            if (NeedToSwitchGas == true)
            {
                if(CURRENT_TANK_NUM == DecoGas[1])
                    AlarmRepeat.Bit.SwitchFO2 = true;  // SwitchFO2 is only allowed to resume after CURRENT_TANK_NUM == DecoGas[1] (Gas swtiched as suggested).

                if((DecoStop[1]!=0) && ((Dive_Info.WaterDepth_ft < (float)(DecoStop[1]+10))&&(Dive_Info.WaterDepth_ft < (float)MOPDAL[1]))
                        &&( CURRENT_TANK_NUM != DecoGas[1] ) )     // When DecoStop+10FT
                {
                    AlarmRealtime[ALARM_SwitchFO2]++;
                    AlarmInTicks[ALARM_SwitchFO2]=TICK_ID_PLUS_1;
                    Alarming.Bit.SwitchFO2 = true;

                    if(AlarmRepeat.Bit.SwitchFO2 == true)
                    {
                        AlarmFIFO_Arrange(ALARM_SwitchFO2);
                        AlarmRepeat.Bit.SwitchFO2 = false; // stop, and not repeatable throughout the same dive
                    }
                }
                else // for GUI
                {
                    AlarmRealtime[ALARM_SwitchFO2]=0;
                    AlarmInTicks[ALARM_SwitchFO2]=0;
                    Alarming.Bit.SwitchFO2 = false;
                }

            }
            //----bit-SwitchFO2--------------------------------------------------------------------

        } // End if(USER_Set.DiveMode==NVD_MDSCUBA)

    } // End of (Dive_Info.Status==AMB_DIVEINFO_DIVE)



    //----bit-SetupVIOLATION--------------------------------------------------------------------
    //if(((Dive_Info.SurfTime_s > 300)    // After-Dive > 5 minutes, promote any Delayed Viotion(s) to be a Violation offically
    //   &&((AlarmOccured.Bit.DelayedVio1==true)||(AlarmOccured.Bit.DelayedVio2==true)||(AlarmOccured.Bit.DepthMax==true)))
    //   ||((DVSTAT&0xF0)==0x80)||(AlarmOccured.Bit.SetupVIOLATION==true))                // Algorithm sent Violation or Immediate Violation 0x80
    if(isViolation == true)
    {
        AlarmRealtime[ALARM_SetupVIOLATION]++;
        AlarmInTicks[ALARM_SetupVIOLATION]=TICK_ID_PLUS_1;
        Alarming.Bit.SetupVIOLATION = true;

        if(AlarmRepeat.Bit.SetupVIOLATION == true)
        {
            AlarmFIFO_Arrange(ALARM_SetupVIOLATION);
            AlarmRepeat.Bit.SetupVIOLATION = false; // stop for each cycle
        }
    }
    else
    {
        AlarmRealtime[ALARM_SetupVIOLATION]=0;
        AlarmInTicks[ALARM_SetupVIOLATION]=0;
        Alarming.Bit.SetupVIOLATION = false;
    }
    //----bit-SetupVIOLATION--------------------------------------------------------------------


    //----bit-LowBattWarning--------------------------------------------------------------------
    if(SystemSupplyMonitor.Battery_Level > BATT_L1)
        AlarmRepeat.Bit.LowBattWarning = true; // allow do Low Batt warning again if charged over this level

    if(SystemSupplyMonitor.Battery_Level == BATT_L1)  // avoid initial value = 0
    {
        AlarmRealtime[ALARM_LowBatteryWaning]++;
        AlarmInTicks[ALARM_LowBatteryWaning]=TICK_ID_PLUS_1;
        Alarming.Bit.LowBattWarning = true;

        if(AlarmRepeat.Bit.LowBattWarning == true)
        {
            AlarmFIFO_Arrange(ALARM_LowBatteryWaning);
            AlarmRepeat.Bit.LowBattWarning = false; // stop for each cycle
        }
    }
    else
    {
        AlarmRealtime[ALARM_LowBatteryWaning]=0;
        AlarmInTicks[ALARM_LowBatteryWaning]=0;
        Alarming.Bit.LowBattWarning = false;
    }
    //----bit-LowBattWarning--------------------------------------------------------------------


    //----bit-LowBattAlarm--------------------------------------------------------------------
    if((SystemSupplyMonitor.Battery_Level > BATT_L0)/*||(( NewDiveWhenLowBatt==true)&&(Dive_Info.Status==AMB_DIVEINFO_DIVE))*/)
        AlarmRepeat.Bit.LowBattAlarm = true;      // allow do Low Batt alarm again if charged over this level

    if(SystemSupplyMonitor.Battery_Level == BATT_L0)  // avoid initial value = 0
    {
        AlarmRealtime[ALARM_LowBatteryAlarm]++;
        AlarmInTicks[ALARM_LowBatteryAlarm]=TICK_ID_PLUS_1;
        Alarming.Bit.LowBattAlarm = true;

        if(AlarmRepeat.Bit.LowBattAlarm == true)
        {
            AlarmFIFO_Arrange(ALARM_LowBatteryAlarm);
            AlarmRepeat.Bit.LowBattAlarm = false; // stop for each cycle
        }
    }
    else
    {
        AlarmRealtime[ALARM_LowBatteryAlarm]=0;
        AlarmInTicks[ALARM_LowBatteryAlarm]=0;
        Alarming.Bit.LowBattAlarm = false;
    }
    //----bit-LowBattAlarm--------------------------------------------------------------------

    // End of Alarm Linking Interface =============================================================================

    // Must to use Bit-OR logic so none of Alarms and Violations would be missed,
    // Profile_Data_Update() resets it to 0s, after passing and saving the data to profile
    AlarmProfileRec.AllBits |= Alarming.AllBits; // Sync-Up Current Alarming Condition and updating the data to save on Profile
    Profile_Trailer.AlarmOccured.AllBits |= Alarming.AllBits;

    //=============================================================================================================
    // only do AlarmFIFO_Process at Tick0 (once per second), to make sure do it once per second
    //=============================================================================================================
    if(TickHandler.scheduled_tick==0)
        CurrAlarmID = AlarmFIFO_Process();      // check AlarmFIFO buffer and then
    //=============================================================================================================



    //AlarmCtr[0]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.CondiVio || AlarmOn.Bit.CondiVio)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.CondiVio = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.CondiVio==true)&&(PreAlarmOn.Bit.CondiVio==false))        // check if time for new alarm cycle
        {
            AlarmCtr[0]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.CondiVio = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[0]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[0]%8) == 4)||((AlarmCtr[0]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.CondiVio = true;
        else
            AlarmState.Bit.CondiVio = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[0]==0)
        {
            AlarmOn.Bit.CondiVio = false;
            AlarmState.Bit.CondiVio = false;
        }
    }

    PreAlarmOn.Bit.CondiVio = AlarmOn.Bit.CondiVio;
    //End of AlarmCtr[0]------------------------------------------------------------------------------------


    //AlarmCtr[1]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DelayedVio1 || AlarmOn.Bit.DelayedVio1)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DelayedVio1 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DelayedVio1==true)&&(PreAlarmOn.Bit.DelayedVio1==false))        // check if time for new alarm cycle
        {
            AlarmCtr[1]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DelayedVio1 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[1]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[1]%8) == 4)||((AlarmCtr[1]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DelayedVio1 = true;
        else
            AlarmState.Bit.DelayedVio1 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[1]==0)
        {
            AlarmOn.Bit.DelayedVio1 = false;
            AlarmState.Bit.DelayedVio1 = false;
        }
    }

    PreAlarmOn.Bit.DelayedVio1 = AlarmOn.Bit.DelayedVio1;
    //End of AlarmCtr[1]------------------------------------------------------------------------------------


    //AlarmCtr[2]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DelayedVio2 || AlarmOn.Bit.DelayedVio2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DelayedVio2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DelayedVio2==true)&&(PreAlarmOn.Bit.DelayedVio2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[2]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DelayedVio2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[2]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[2]%8) == 4)||((AlarmCtr[2]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DelayedVio2 = true;
        else
            AlarmState.Bit.DelayedVio2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[2]==0)
        {
            AlarmOn.Bit.DelayedVio2 = false;
            AlarmState.Bit.DelayedVio2 = false;
        }
    }

    PreAlarmOn.Bit.DelayedVio2 = AlarmOn.Bit.DelayedVio2;
    //End of AlarmCtr[2]------------------------------------------------------------------------------------


    //AlarmCtr[3]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DepthMax || AlarmOn.Bit.DepthMax)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DepthMax = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DepthMax==true)&&(PreAlarmOn.Bit.DepthMax==false))        // check if time for new alarm cycle
        {
            AlarmCtr[3]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DepthMax = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[3]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[3]%8) == 4)||((AlarmCtr[3]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DepthMax = true;
        else
            AlarmState.Bit.DepthMax = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[3]==0)
        {
            AlarmOn.Bit.DepthMax = false;
            AlarmState.Bit.DepthMax = false;
            //AlarmRepeat.Bit.DepthMax = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DepthMax = AlarmOn.Bit.DepthMax;
    //End of AlarmCtr[3]------------------------------------------------------------------------------------


    //AlarmCtr[4]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.AscRate5 || AlarmOn.Bit.AscRate5)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.AscRate5 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.AscRate5==true)&&(PreAlarmOn.Bit.AscRate5==false))        // check if time for new alarm cycle
        {
            AlarmCtr[4]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.AscRate5 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[4]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[4]%8) == 4)||((AlarmCtr[4]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.AscRate5 = true;
        else
            AlarmState.Bit.AscRate5 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[4]==0)
        {
            AlarmOn.Bit.AscRate5 = false;
            AlarmState.Bit.AscRate5 = false;
            //AlarmRepeat.Bit.AscRate5 = true;        // repeatable if occurs again
        }

        if(((AlarmCtr[4]%8)==0)&&(ASCBGVal < 5))          // if (ASCBGVal < 5) during the ten beeps, those ten beeps would be interrupted and stopped
        {
            AlarmOn.Bit.AscRate5 = false;
            AlarmState.Bit.AscRate5 = false;
            AlarmCtr[4]=0;
        }

    }

    PreAlarmOn.Bit.AscRate5 = AlarmOn.Bit.AscRate5;
    //End of AlarmCtr[4]------------------------------------------------------------------------------------


    //================================================================================================================================
    // for testing only, but do not remove
    //Alarm_10Seonds(&ALARM_ON.Bit.AscRate5, &AlarmOn.Bit.AscRate5, &PreAlarmOn.Bit.AscRate5, &AlarmState.Bit.AscRate5, &AlarmCtr[4]);
    // for testing only, but do not remove
    //================================================================================================================================



    //AlarmCtr[5]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.PO2NearSetPoint || AlarmOn.Bit.PO2NearSetPoint)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.PO2NearSetPoint = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.PO2NearSetPoint==true)&&(PreAlarmOn.Bit.PO2NearSetPoint==false))        // check if time for new alarm cycle
        {
            AlarmCtr[5]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.PO2NearSetPoint = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[5]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[5]%8) == 4)||((AlarmCtr[5]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.PO2NearSetPoint = true;
        else
            AlarmState.Bit.PO2NearSetPoint = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[5]==0)
        {
            AlarmOn.Bit.PO2NearSetPoint = false;
            AlarmState.Bit.PO2NearSetPoint = false;
            //AlarmRepeat.Bit.PO2NearSetPoint = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.PO2NearSetPoint = AlarmOn.Bit.PO2NearSetPoint;
    //End of AlarmCtr[5]------------------------------------------------------------------------------------



    //AlarmCtr[6]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.PO2AtSetPoint || AlarmOn.Bit.PO2AtSetPoint)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.PO2AtSetPoint = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.PO2AtSetPoint==true)&&(PreAlarmOn.Bit.PO2AtSetPoint==false))        // check if time for new alarm cycle
        {
            AlarmCtr[6]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.PO2AtSetPoint = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[6]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[6]%8) == 4)||((AlarmCtr[6]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.PO2AtSetPoint = true;
        else
            AlarmState.Bit.PO2AtSetPoint = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[6]==0)
        {
            AlarmOn.Bit.PO2AtSetPoint = false;
            AlarmState.Bit.PO2AtSetPoint = false;
            //AlarmRepeat.Bit.PO2AtSetPoint = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.PO2AtSetPoint = AlarmOn.Bit.PO2AtSetPoint;
    //End of AlarmCtr[6]------------------------------------------------------------------------------------


    //AlarmCtr[7]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DepthSet || AlarmOn.Bit.DepthSet)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DepthSet = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DepthSet==true)&&(PreAlarmOn.Bit.DepthSet==false))        // check if time for new alarm cycle
        {
            AlarmCtr[7]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DepthSet = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[7]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[7]%8) == 4)||((AlarmCtr[7]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DepthSet = true;
        else
            AlarmState.Bit.DepthSet = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[7]==0)
        {
            AlarmOn.Bit.DepthSet = false;
            AlarmState.Bit.DepthSet = false;
            //AlarmRepeat.Bit.DepthSet = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DepthSet = AlarmOn.Bit.DepthSet;
    //End of AlarmCtr[7]------------------------------------------------------------------------------------



    //AlarmCtr[8]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DiveN2Bar || AlarmOn.Bit.DiveN2Bar)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DiveN2Bar = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DiveN2Bar==true)&&(PreAlarmOn.Bit.DiveN2Bar==false))        // check if time for new alarm cycle
        {
            AlarmCtr[8]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DiveN2Bar = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[8]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[8]%8) == 4)||((AlarmCtr[8]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DiveN2Bar = true;
        else
            AlarmState.Bit.DiveN2Bar = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[8]==0)
        {
            AlarmOn.Bit.DiveN2Bar = false;
            AlarmState.Bit.DiveN2Bar = false;
            //AlarmRepeat.Bit.DiveN2Bar = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DiveN2Bar = AlarmOn.Bit.DiveN2Bar;
    //End of AlarmCtr[8]------------------------------------------------------------------------------------



    //AlarmCtr[9]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.O2_80Pct || AlarmOn.Bit.O2_80Pct)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.O2_80Pct = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.O2_80Pct==true)&&(PreAlarmOn.Bit.O2_80Pct==false))        // check if time for new alarm cycle
        {
            AlarmCtr[9]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.O2_80Pct = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[9]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[9]%8) == 4)||((AlarmCtr[9]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.O2_80Pct = true;
        else
            AlarmState.Bit.O2_80Pct = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[9]==0)
        {
            AlarmOn.Bit.O2_80Pct = false;
            AlarmState.Bit.O2_80Pct = false;
        }
    }

    PreAlarmOn.Bit.O2_80Pct = AlarmOn.Bit.O2_80Pct;
    //End of AlarmCtr[9]------------------------------------------------------------------------------------




    //AlarmCtr[10]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.O2_100Pct || AlarmOn.Bit.O2_100Pct)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.O2_100Pct = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.O2_100Pct==true)&&(PreAlarmOn.Bit.O2_100Pct==false))        // check if time for new alarm cycle
        {
            AlarmCtr[10]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.O2_100Pct = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[10]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[10]%8) == 4)||((AlarmCtr[10]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.O2_100Pct = true;
        else
            AlarmState.Bit.O2_100Pct = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[10]==0)
        {
            AlarmOn.Bit.O2_100Pct = false;
            AlarmState.Bit.O2_100Pct = false;
        }
    }

    PreAlarmOn.Bit.O2_100Pct = AlarmOn.Bit.O2_100Pct;
    //End of AlarmCtr[10]------------------------------------------------------------------------------------



    //AlarmCtr[11]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DECO_Entry || AlarmOn.Bit.DECO_Entry)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DECO_Entry = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DECO_Entry==true)&&(PreAlarmOn.Bit.DECO_Entry==false))        // check if time for new alarm cycle
        {
            AlarmCtr[11]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DECO_Entry = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[11]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[11]%8) == 4)||((AlarmCtr[11]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DECO_Entry = true;
        else
            AlarmState.Bit.DECO_Entry = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[11]==0)
        {
            AlarmOn.Bit.DECO_Entry = false;
            AlarmState.Bit.DECO_Entry = false;
            //AlarmRepeat.Bit.DECO_Entry = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DECO_Entry = AlarmOn.Bit.DECO_Entry;
    //End of AlarmCtr[11]------------------------------------------------------------------------------------


    //AlarmCtr[12]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DiveTime || AlarmOn.Bit.DiveTime)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DiveTime = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DiveTime==true)&&(PreAlarmOn.Bit.DiveTime==false))        // check if time for new alarm cycle
        {
            AlarmCtr[12]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DiveTime = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[12]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[12]%8) == 4)||((AlarmCtr[12]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DiveTime = true;
        else
            AlarmState.Bit.DiveTime = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[12]==0)
        {
            AlarmOn.Bit.DiveTime = false;
            AlarmState.Bit.DiveTime = false;
        }
    }

    PreAlarmOn.Bit.DiveTime = AlarmOn.Bit.DiveTime;
    //End of AlarmCtr[12]------------------------------------------------------------------------------------



    //AlarmCtr[13]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DiveDTR || AlarmOn.Bit.DiveDTR)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DiveDTR = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DiveDTR==true)&&(PreAlarmOn.Bit.DiveDTR==false))        // check if time for new alarm cycle
        {
            AlarmCtr[13]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DiveDTR = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[13]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[13]%8) == 4)||((AlarmCtr[13]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DiveDTR = true;
        else
            AlarmState.Bit.DiveDTR = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[13]==0)
        {
            AlarmOn.Bit.DiveDTR = false;
            AlarmState.Bit.DiveDTR = false;
            //AlarmRepeat.Bit.DiveDTR = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.DiveDTR = AlarmOn.Bit.DiveDTR;
    //End of AlarmCtr[13]------------------------------------------------------------------------------------




    //AlarmCtr[14]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.AscRate4 || AlarmOn.Bit.AscRate4)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.AscRate4 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.AscRate4==true)&&(PreAlarmOn.Bit.AscRate4==false))        // check if time for new alarm cycle
        {
            AlarmCtr[14]=ALARM_SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.AscRate4 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[14]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[14])
        {
        case 15:
        case 13:
        case 11:
            AlarmState.Bit.FreeDepth1 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth1 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[14]==0)
        {
            AlarmOn.Bit.AscRate4 = false;
            AlarmState.Bit.AscRate4 = false;
            //AlarmRepeat.Bit.AscRate4 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.AscRate4 = AlarmOn.Bit.AscRate4;
    //End of AlarmCtr[14]------------------------------------------------------------------------------------



    //AlarmCtr[15]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDiveT || AlarmOn.Bit.FreeDiveT)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDiveT = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDiveT==true)&&(PreAlarmOn.Bit.FreeDiveT==false))        // check if time for new alarm cycle
        {
            AlarmCtr[15]=ALARM_SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDiveT = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[15]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[15])
        {
        case 15:
        case 13:
        case 11:
            AlarmState.Bit.FreeDepth1 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth1 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[15]==0)
        {
            AlarmOn.Bit.FreeDiveT = false;
            AlarmState.Bit.FreeDiveT = false;
            AlarmRepeat.Bit.FreeDiveT = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDiveT = AlarmOn.Bit.FreeDiveT;
    //End of AlarmCtr[15]------------------------------------------------------------------------------------




    //AlarmCtr[16]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDepth1 || AlarmOn.Bit.FreeDepth1)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDepth1 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDepth1==true)&&(PreAlarmOn.Bit.FreeDepth1==false))        // check if time for new alarm cycle
        {
            AlarmCtr[16]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDepth1 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[16]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[16])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeDepth1 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth1 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[16]==0)
        {
            AlarmOn.Bit.FreeDepth1 = false;
            AlarmState.Bit.FreeDepth1 = false;
            //AlarmRepeat.Bit.FreeDepth1 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDepth1 = AlarmOn.Bit.FreeDepth1;
    //End of AlarmCtr[16]------------------------------------------------------------------------------------


    //AlarmCtr[17]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDepth2 || AlarmOn.Bit.FreeDepth2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDepth2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDepth2==true)&&(PreAlarmOn.Bit.FreeDepth2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[17]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDepth2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[17]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[17])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeDepth2 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth2 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[17]==0)
        {
            AlarmOn.Bit.FreeDepth2 = false;
            AlarmState.Bit.FreeDepth2 = false;
            //AlarmRepeat.Bit.FreeDepth2 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDepth2 = AlarmOn.Bit.FreeDepth2;
    //End of AlarmCtr[17]------------------------------------------------------------------------------------


    //AlarmCtr[18]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeDepth3 || AlarmOn.Bit.FreeDepth3)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeDepth3 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeDepth3==true)&&(PreAlarmOn.Bit.FreeDepth3==false))        // check if time for new alarm cycle
        {
            AlarmCtr[18]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeDepth3 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[18]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[18])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeDepth3 = true;
            break;

        default:
            AlarmState.Bit.FreeDepth3 = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[18]==0)
        {
            AlarmOn.Bit.FreeDepth3 = false;
            AlarmState.Bit.FreeDepth3 = false;
            //AlarmRepeat.Bit.FreeDepth3 = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeDepth3 = AlarmOn.Bit.FreeDepth3;
    //End of AlarmCtr[18]------------------------------------------------------------------------------------


    //AlarmCtr[19]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeN2Bar || AlarmOn.Bit.FreeN2Bar)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeN2Bar = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeN2Bar==true)&&(PreAlarmOn.Bit.FreeN2Bar==false))        // check if time for new alarm cycle
        {
            AlarmCtr[19]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeN2Bar = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[19]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[19])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeN2Bar = true;
            break;

        default:
            AlarmState.Bit.FreeN2Bar = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[19]==0)
        {
            AlarmOn.Bit.FreeN2Bar = false;
            AlarmState.Bit.FreeN2Bar = false;
            //AlarmRepeat.Bit.FreeN2Bar = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeN2Bar = AlarmOn.Bit.FreeN2Bar;
    //End of AlarmCtr[19]------------------------------------------------------------------------------------


    //AlarmCtr[20]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeCDT || AlarmOn.Bit.FreeCDT)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeCDT = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeCDT==true)&&(PreAlarmOn.Bit.FreeCDT==false))        // check if time for new alarm cycle
        {
            AlarmCtr[20]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeCDT = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[20]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[20])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeCDT = true;
            break;

        default:
            AlarmState.Bit.FreeCDT = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[20]==0)
        {
            AlarmOn.Bit.FreeCDT = false;
            AlarmState.Bit.FreeCDT = false;
            //AlarmRepeat.Bit.FreeCDT = true;        // repeatable if occurs again
        }
    }

    PreAlarmOn.Bit.FreeCDT = AlarmOn.Bit.FreeCDT;
    //End of AlarmCtr[20]------------------------------------------------------------------------------------


    //AlarmCtr[21]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.FreeViol || AlarmOn.Bit.FreeViol)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.FreeViol = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.FreeViol==true)&&(PreAlarmOn.Bit.FreeViol==false))        // check if time for new alarm cycle
        {
            AlarmCtr[21]=ALARM_3SHORT_3PULSES;         // set for beginning of alarm cycle
            ALARM_ON.Bit.FreeViol = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[21]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        switch(AlarmCtr[21])
        {
        case 23:
        case 21:
        case 19:
        case 15:
        case 13:
        case 11:
        case 7:
        case 5:
        case 3:
            AlarmState.Bit.FreeViol = true;
            break;

        default:
            AlarmState.Bit.FreeViol = false;
            break;
        }
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[21]==0)
        {
            AlarmOn.Bit.FreeViol = false;
            AlarmState.Bit.FreeViol = false;
        }
    }

    PreAlarmOn.Bit.FreeViol = AlarmOn.Bit.FreeViol;
    //End of AlarmCtr[21]------------------------------------------------------------------------------------


    //AlarmCtr[22]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.DECO_Depth70 || AlarmOn.Bit.DECO_Depth70)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.DECO_Depth70 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.DECO_Depth70==true)&&(PreAlarmOn.Bit.DECO_Depth70==false))        // check if time for new alarm cycle
        {
            AlarmCtr[22]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.DECO_Depth70 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[22]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[22]%8) == 4)||((AlarmCtr[22]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.DECO_Depth70 = true;
        else
            AlarmState.Bit.DECO_Depth70 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[22]==0)
        {
            AlarmOn.Bit.DECO_Depth70 = false;
            AlarmState.Bit.DECO_Depth70 = false;
        }
    }


    PreAlarmOn.Bit.DECO_Depth70 = AlarmOn.Bit.DECO_Depth70;
    //End of AlarmCtr[22]------------------------------------------------------------------------------------


    //AlarmCtr[23]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.SwitchFO2 || AlarmOn.Bit.SwitchFO2)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.SwitchFO2 = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.SwitchFO2==true)&&(PreAlarmOn.Bit.SwitchFO2==false))        // check if time for new alarm cycle
        {
            AlarmCtr[23]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.SwitchFO2 = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[23]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[23]%8) == 4)||((AlarmCtr[23]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.SwitchFO2 = true;
        else
            AlarmState.Bit.SwitchFO2 = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[23]==0)
        {
            AlarmOn.Bit.SwitchFO2 = false;
            AlarmState.Bit.SwitchFO2 = false;
        }
    }


    PreAlarmOn.Bit.SwitchFO2 = AlarmOn.Bit.SwitchFO2;
    //End of AlarmCtr[23]------------------------------------------------------------------------------------


    //AlarmCtr[24]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.SetupVIOLATION || AlarmOn.Bit.SetupVIOLATION)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.SetupVIOLATION = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.SetupVIOLATION==true)&&(PreAlarmOn.Bit.SetupVIOLATION==false))        // check if time for new alarm cycle
        {
            AlarmCtr[24]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.SetupVIOLATION = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[24]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[23]%8) == 4)||((AlarmCtr[23]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.SetupVIOLATION = true;
        else
            AlarmState.Bit.SetupVIOLATION = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[24]==0)
        {
            AlarmOn.Bit.SetupVIOLATION = false;
            AlarmState.Bit.SetupVIOLATION = false;
        }
    }


    PreAlarmOn.Bit.SetupVIOLATION = AlarmOn.Bit.SetupVIOLATION;
    //End of AlarmCtr[24]------------------------------------------------------------------------------------


    //AlarmCtr[29]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.LowBattWarning || AlarmOn.Bit.LowBattWarning)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.LowBattWarning = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.LowBattWarning==true)&&(PreAlarmOn.Bit.LowBattWarning==false))        // check if time for new alarm cycle
        {
            AlarmCtr[29]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.LowBattWarning = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[29]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[29]%8) == 4)||((AlarmCtr[29]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.LowBattWarning = true;
        else
            AlarmState.Bit.LowBattWarning = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[29]==0)
        {
            AlarmOn.Bit.LowBattWarning = false;
            AlarmState.Bit.LowBattWarning = false;
        }
    }


    PreAlarmOn.Bit.LowBattWarning = AlarmOn.Bit.LowBattWarning;
    //End of AlarmCtr[29]------------------------------------------------------------------------------------



    //AlarmCtr[30]-------------------------------------------------------------------------------------------
    if(ALARM_ON.Bit.LowBattAlarm || AlarmOn.Bit.LowBattAlarm)   // triggered or conitinue to be ON unitl end (or interrupted (TBD))
    {
        AlarmOn.Bit.LowBattAlarm = true;      // start the Alarm On cycle to the end

        // Initialize and start this alarm cycle
        if((AlarmOn.Bit.LowBattAlarm==true)&&(PreAlarmOn.Bit.LowBattAlarm==false))        // check if time for new alarm cycle
        {
            AlarmCtr[30]=ALARM_LONG_10SEC;         // set for beginning of alarm cycle
            ALARM_ON.Bit.LowBattAlarm = false;    // make if momentary, needs a new trigger to do the same alarm again
        }

        AlarmCtr[30]--;

        //--------------------------------- Alarm Cycle buzzer sound pattern ---------------------------------
        if(((AlarmCtr[30]%8) == 4)||((AlarmCtr[30]%8) == 5))     // Beeps at Tick 4 and 5 ON / Tick 0,1,2,3,6,7 OFF
            AlarmState.Bit.LowBattAlarm = true;
        else
            AlarmState.Bit.LowBattAlarm = false;
        //----------------------------------------------------------------------------------------------------

        if(AlarmCtr[30]==0)
        {
            AlarmOn.Bit.LowBattAlarm = false;
            AlarmState.Bit.LowBattAlarm = false;
        }
    }


    PreAlarmOn.Bit.LowBattAlarm = AlarmOn.Bit.LowBattAlarm;
    //End of AlarmCtr[30]------------------------------------------------------------------------------------



    //--Combined Logic---------------------------------------------------------------------------------------
    if(AlarmState.AllBits != 0)
    {
        if(USER_Set.SwitchSet.Bit.AlarmAudible)
        {
            if(Dive_Info.Status==AMB_DIVEINFO_DIVE)
                SystemStatus.buzzer_on_req = true;      //Buzzer_On(); during Dive time, for all alarms

            if(((Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)||(Dive_Info.Status==AMB_DIVEINFO_SURF)||(Dive_Info.Status==AMB_DIVEINFO_NEWDAY))&&(AlarmState.Bit.FreeCDT==true))
                SystemStatus.buzzer_on_req = true;      //Buzzer_On(); during After-Dive time for some alarm(s)
        }
    }  //--Combined Logic---------------------------------------------------------------------------------------

    if(((((Alarming.AllBits & 0x3FFFFFFF)!=0)&&(Dive_Info.Status==AMB_DIVEINFO_DIVE))||((Dive_Info.Status==AMB_DIVEINFO_AFTERDIVE)))
            &&(SystemStatus.backlight_on==BACKLIGHT_DIM))    // When (Dim at (Dive && Alarming)), or (Dim at After-Dive), request Normal Brightness
        SystemStatus.backlight_on_req = true;    // return to normal brightness if any alarming, only do this during dive mode
}


/*******************************************************************************
    Some Alarm would stop (like straight to its ending)
    as soon as the alarm triggerig condition is out.

    Then the following special restoration treatment (or alarm reset) is needed

*******************************************************************************/
void ImmediateStopAlarmCheck(void)
{
    //===================PO2 Alarm against to the Set Point===================
    if( (Dive_Info.DiveTime_s > 10)     // make sure PO2 alarm triggered during diving
            &&( ((SCUBA_Set.FO2A[CURRENT_TANK_NUM]>=21)&&(100*PO2atDepth < (SCUBA_Set.PO2A[CURRENT_TANK_NUM])))    // for FO2 = 21% to 100%, , Alarm threshold is calculated at PO2A[0]
                ||((SCUBA_Set.FO2A[CURRENT_TANK_NUM]<21)&&(100*PO2atDepth < 160))) )                  // for AIR, Alarm threshold fixed at 1.60
    {
        AlarmCtr[6]=0;
        AlarmOn.Bit.PO2AtSetPoint = false;    // stop itself and yield other alarm waiting at AlarmFIFO[0]
        AlarmState.Bit.PO2AtSetPoint = false; // clear the buzzing buffer for this alarm
        AlarmRealtime[ALARM_PO2AtSetPoint]=0;
        AlarmInTicks[ALARM_PO2AtSetPoint]=0;
        Alarming.Bit.PO2AtSetPoint = false;
    }

    //===================Depth Alarm against to the Set Point===================
    if(USER_Set.Units==NVD_IMPERIAL)
    {
        if((Dive_Info.WaterDepth_ft < (float)DEPTHAL_FT)&&(DEPTHAL_FT > 0))     // (DEPTHAL_M > 0) is the On/Off switch
        {
            AlarmCtr[7]=0;
            AlarmOn.Bit.DepthSet = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState.Bit.DepthSet = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_DepthSet]=0;
            AlarmInTicks[ALARM_DepthSet]=0;
            Alarming.Bit.DepthSet = false;
        }
    }
    else
    {
        if((Dive_Info.WaterDepth_m < (float)DEPTHAL_M)&&(DEPTHAL_M > 0))     // (DEPTHAL_M > 0) is the On/Off switch
        {
            AlarmCtr[7]=0;
            AlarmOn.Bit.DepthSet = false;         // stop itself and yield other alarm waiting at AlarmFIFO[0]
            AlarmState.Bit.DepthSet = false;      // clear the buzzing buffer for this alarm
            AlarmRealtime[ALARM_DepthSet]=0;
            AlarmInTicks[ALARM_DepthSet]=0;
            Alarming.Bit.DepthSet = false;
        }
    }

    //===================Free Depth Alarm 1 against to the Set Point===================
    if(USER_Set.DiveMode==NVD_MDFREE)
    {
        if(USER_Set.Units==NVD_IMPERIAL)
        {
            if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH1_FT)&&(FREE_ALARM_DEPTH1_FT > 0))
            {
                AlarmCtr[16]=0;
                AlarmOn.Bit.FreeDepth1 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
                AlarmState.Bit.FreeDepth1 = false;  // clear the buzzing buffer for this alarm
                AlarmRealtime[ALARM_FreeDepth1]=0;
                AlarmInTicks[ALARM_FreeDepth1]=0;
                Alarming.Bit.FreeDepth1 = false;
            }
        }
        else
        {
            if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH1_M)&&(FREE_ALARM_DEPTH1_M > 0))
            {
                AlarmCtr[16]=0;
                AlarmOn.Bit.FreeDepth1 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
                AlarmState.Bit.FreeDepth1 = false;  // clear the buzzing buffer for this alarm
                AlarmRealtime[ALARM_FreeDepth1]=0;
                AlarmInTicks[ALARM_FreeDepth1]=0;
                Alarming.Bit.FreeDepth1 = false;
            }
        }
    }

    //===================Free Depth Alarm 2 against to the Set Point===================
    if(USER_Set.DiveMode==NVD_MDFREE)
    {
        if(USER_Set.Units==NVD_IMPERIAL)
        {
            if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH2_FT)&&(FREE_ALARM_DEPTH2_FT > 0))
            {
                AlarmCtr[17]=0;
                AlarmOn.Bit.FreeDepth2 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
                AlarmState.Bit.FreeDepth2 = false;  // clear the buzzing buffer for this alarm
                AlarmRealtime[ALARM_FreeDepth2]=0;
                AlarmInTicks[ALARM_FreeDepth2]=0;
                Alarming.Bit.FreeDepth2 = false;
            }
        }
        else
        {
            if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH2_M)&&(FREE_ALARM_DEPTH2_M > 0))
            {
                AlarmCtr[17]=0;
                AlarmOn.Bit.FreeDepth2 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
                AlarmState.Bit.FreeDepth2 = false;  // clear the buzzing buffer for this alarm
                AlarmRealtime[ALARM_FreeDepth2]=0;
                AlarmInTicks[ALARM_FreeDepth2]=0;
                Alarming.Bit.FreeDepth2 = false;
            }
        }
    }

    //===================Free Depth Alarm 3 against to the Set Point===================
    if(USER_Set.DiveMode==NVD_MDFREE)
    {
        if(USER_Set.Units==NVD_IMPERIAL)
        {
            if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_ft < (float)FREE_ALARM_DEPTH3_FT)&&(FREE_ALARM_DEPTH3_FT > 0))
            {
                AlarmCtr[18]=0;
                AlarmOn.Bit.FreeDepth3 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
                AlarmState.Bit.FreeDepth3 = false;  // clear the buzzing buffer for this alarm
                AlarmRealtime[ALARM_FreeDepth3]=0;
                AlarmInTicks[ALARM_FreeDepth3]=0;
                Alarming.Bit.FreeDepth3 = false;
            }
        }
        else
        {
            if((Dive_Info.DiveTime_s > 10)&&(Dive_Info.WaterDepth_m < (float)FREE_ALARM_DEPTH3_M)&&(FREE_ALARM_DEPTH3_M > 0))
            {
                AlarmCtr[18]=0;
                AlarmOn.Bit.FreeDepth3 = false;     // stop itself and yield other alarm waiting at AlarmFIFO[0]
                AlarmState.Bit.FreeDepth3 = false;  // clear the buzzing buffer for this alarm
                AlarmRealtime[ALARM_FreeDepth3]=0;
                AlarmInTicks[ALARM_FreeDepth3]=0;
                Alarming.Bit.FreeDepth3 = false;
            }
        }
    }

}


/*******************************************************************************
  CDT_Manager is to Start, Stop CDT

  CDT links and is ticked by SystemTimers.CounterDWN1

  uint8_t CDT_Set = 0;          // CDT Setting at Surface Menu  0: OFF, 1: ON,  2: SET
  uint8_t CDT_Run = 0;          // CDT Control underwater (FreeDive Only)       0: stop;     1: run
  uint8_t CDT_Alarm = 0;        // CDT Alarm (FreeDive Only)                    0: No Trigger CDT Alarm;        1: To Trigger CDT Alarm

  #define CDT_TIMER             SystemTimers.CounterDWN1_s                // start counting UP from 0 when dive starts
  #define CDT_TIMER_Reset()     SystemTimers.CounterDWN1_s=60*SCUBA_Set.CountDownMin+SCUBA_Set.CountDownSec   // call to reset Dive Timer or CounterUP1_s
  #define CDT_TIMER_Enable      USER_Set.SwitchSet.Bit.CDT_Enable
  #define CDT_TIMER_Run         CDT_Run
  #define CDT_TIMER_Alarm       CDT_Alarm                               // 0: Not Trigger CDT Alarm     1: To Trigger CDT Alarm
  ---------------------------------------------------------------------------------
  CDT_TIMER_Run |     CDT_TIMER_Reset()     |  in between    |   CDT_TIMER==0      |
  ---------------------------------------------------------------------------------
      false     | CDT_TIMER_Reset(), pause  |     pause      |   stop at 0         |
  ---------------------------------------------------------------------------------
      true      | counting down from Reset  |  counting down | CDT_TIMER_Run=false |
  ---------------------------------------------------------------------------------

*******************************************************************************/
void CDT_Manager(void)
{
    if(CDT_TIMER_Run==true)
    {
        if((CDT_TIMER==0)&&(CDT_TIMER_Alarm==false))        // when running down to 0, trigger CDT_Alarm.....
        {
            CDT_TIMER_Alarm = true;         // to trigger CDT alarm in AlarmManager( )
            // keep this for one second, for AlarmManager( ) to handle CDT alarm
        }
        else if((CDT_TIMER==0)&&(CDT_TIMER_Alarm==true))
        {
            CDT_SET = STAT_OFF;
            CDT_TIMER_Alarm = false;        // stop the trigger one second afterward
            CDT_TIMER_Run = false;          // stop running CDT_TIMER for now
            CDT_TIMER_Reset();              // stops at 0, and trigger CDT_Alarm.....
        }
    }
    else
    {
        CDT_TIMER_Alarm = false;        // stop the trigger one second afterward
        CDT_TIMER_Run = false;          // stop running CDT_TIMER for now
        //CDT_TIMER_Reset();              // stops at 0, and trigger CDT_Alarm.....
    }
}
/************************************************************************************
  ShutdownManager is to complete all necessary processes before planned shutdown

    typedef enum
    {
      OPERATE_Run = 0x00,   // Normal Operation, most of time and initial state
      OPERATE_LowBatt,      // Low Battery State (RED)
      OPERATE_EndDive,      // Force End Dive State (10 Hour Dive)
      OPERATE_DataRetain,   // Data Retention State
      OPERATE_DeepSleep,    // Deep Sleep State
      OPERATE_Shutoff,      // Shutoff State
    }OP_Shutdown_t;

    typedef struct
    {
      OP_Shutdown_t State;
      SystemTimeDate_t OP_Time;
    }SHUTDOWN_struct_t;

************************************************************************************/
void ShutdownManager(void)
{
    Operate.OP_Time = SysTimeDatePST;
    Operate.State = OPERATE_Run;

    if((SystemSupplyMonitor.Battery_Level == BATT_L0)&&(USB_STAT == USBState_NotConnected)&&(Dive_Info.SurfTime_s > 600)&&(Dive_Info.Status==AMB_DIVEINFO_SURF))
    {
        //OperateLowBatt_Text(DispFlahing);
        Operate.State = OPERATE_LowBatt;

        // Request Diagnostics
        //SystemStatus.DiagnosticReq = true;

    }
    else if((SystemSupplyMonitor.Battery_Level == BATT_L0)&&(USB_STAT==USBState_NotConnected)&&(Dive_Info.SurfTime_s > 0)&&(Dive_Info.Status==AMB_DIVEINFO_NEWDAY))
    {
        //OperateLowBatt_Text(DispFlahing);
        Operate.State = OPERATE_LowBatt;

        // Request Diagnostics
        //SystemStatus.DiagnosticReq = true;
    }

}

#endif  // _DSX_WARNINGSANDALARMS_H_