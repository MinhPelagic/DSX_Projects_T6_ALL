
#include "L4X9_includes.h"
/**/
extern TANK_NUM_t GUI_TankN_Linked;

#define LINKED_TMT_1    (BIT_0==(GUI_TankN_Linked&BIT_0))
#define LINKED_TMT_2    (BIT_1==(GUI_TankN_Linked&BIT_1))
#define LINKED_TMT_3    (BIT_2==(GUI_TankN_Linked&BIT_2))
#define LINKED_TMT_4    (BIT_3==(GUI_TankN_Linked&BIT_3))
#define LINKED_TMT_5    (BIT_4==(GUI_TankN_Linked&BIT_4))
#define LINKED_TMT_6    (BIT_5==(GUI_TankN_Linked&BIT_5))
/*Display handle order*/
enum
{
    DeviceSett_TMT_01 = 0x0U,
    DeviceSett_TMT_02,
    DeviceSett_TMT_03,
    DeviceSett_TMT_04,
    DeviceSett_TMT_05,
    DeviceSett_TMT_06,
    DeviceSett_TMT_LEFT,
    DeviceSett_TMT_RIGHT,
    DeviceSett_TMT_Max,
};
extern const contentDispContext_st Transmitters_TMT_SERIAL_Text;
extern const contentDispContext_st Transmitters_TMT_SETSERIAL_Text;
extern const contentDispContext_st Transmitters_TMT_1_PassCodeNumber;
extern const contentDispContext_st Transmitters_TMT_2_PassCodeNumber;
extern const contentDispContext_st Transmitters_TMT_3_PassCodeNumber;
extern const contentDispContext_st Transmitters_TMT_4_PassCodeNumber;
extern const contentDispContext_st Transmitters_TMT_5_PassCodeNumber;
extern const contentDispContext_st Transmitters_TMT_6_PassCodeNumber;
extern const contentDispContext_st Transmitters_TMT_1_Pressure;
extern const contentDispContext_st Transmitters_TMT_2_Pressure;
extern const contentDispContext_st Transmitters_TMT_3_Pressure;
extern const contentDispContext_st Transmitters_TMT_4_Pressure;
extern const contentDispContext_st Transmitters_TMT_5_Pressure;
extern const contentDispContext_st Transmitters_TMT_6_Pressure;
extern const contentDispContext_st Transmitters_TMT_SEARCHING_TXT;
extern const contentDispContext_st Transmitters_TMT_BATTLOW_TXT;
extern const contentDispContext_st Transmitters_TMT_BATTGOOD_TXT;
extern const contentDispContext_st Transmitters_TMT_NOTAVAILABE_TXT;
