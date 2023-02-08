

#ifndef _ICON_DSX_H__
#define _ICON_DSX_H__

#define PenSizeLine_SURFnDIVE				2 //The lines on SURFACE and DIVE mode below the vavlue
#define LineColor_SURFnDIVE	  				GUI_GRAY
#define TxtColor_UnSelect					GUI_CYAN
#define TxtColor_Select						GUI_WHITE
#define ColorBatteryLine					GUI_BLUE

/*Item status*/
typedef enum
{
    IteStat_Clear   = 0u,           //Clear item
    IteStat_ClearThenSelect,		//Clear the portion first then display
    IteStat_Select,		            //Display item with Selected color (no clear portion)
    IteStat_UnSelect,	            //Display item with UnSelected color (no clear portion)
    IteStat_Flashing,	            //Flashing item
    IteStat_ClearThenFlashing,	    //Flashing item after clear
    /**/
    IteStat_Initial,	            //Initial item
    IteStat_Update,	                //Update item
    IteStat_DoNothing,              //Do not progress
} ItemStatus_te;

/*LOG status*/
typedef enum {
    /*
    -------------
    LOG item status
    -------------
    */
    LOG_Mode_LOG_Clear,
    LOG_Mode_LOG_Select,
    LOG_Mode_LOG_UnSelect,
    LOG_Mode_LOG_DATA_1, 	//In DATA-1 Tab
    LOG_Mode_LOG_DATA_2,	//In DATA-2 Tab
} LOG_Status_te;

/*Draw icon for DSX*/
void Display_TitleBar(void);
void DispButton_BACK(const GUI_POINT* Pos);
void DispButton_UP(const GUI_POINT* Pos);
void DispButton_DOWN(const GUI_POINT* Pos);
void DispButton_SELECT(const GUI_POINT* Pos);
void DispButton_HOME(const GUI_POINT* Pos);
void DispButton_CANCEL(const GUI_POINT* Pos);
void DrawTheSlash(const GUI_POINT* Pos);
void DispButton_NEXT(const GUI_POINT* Pos);

#endif
