/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
    IPL0=0x00000400,  //bxxx.
    IPL1=0x00000500,  //bxx.y
    IPL2=0x00000600,  //bx.yy
    IPL3=0x00000700,  //b.yyy

}IntCtrl_Priority_Levels;

typedef enum{          /* Vector Number */ 
// INTC_RESET=1,               // 1
// INTC_NMI,                   // 2
// INTC_Hard_Fault,            // 3
// INTC_MEMORY_MANAGEMENT,     // 4
// INTC_BUS_FAULT,             // 5
// INTC_USAGE_FAULT,           // 6
// INTC_SV_CALL,               // 11
// INTC_DEBUG_MONITOR,         // 12
// INTC_PEND_SV,               // 14
INTC_SYS_TICK=1,              // 15
 // total numb 10 // 
}IntCtrl_ExceptiontType;

typedef enum{
INTC_GPIO_Port_A=0,
INTC_GPIO_Port_B,
INTC_GPIO_Port_C,
INTC_GPIO_Port_D,
INTC_GPIO_Port_E,
INTC_UART0,
INTC_UART1
}IntCtrl_InterruptType;

typedef enum{
GP0=0x0,
GP1=0x1,
GP2=0x2,
GP3=0x3,
GP4=0x4,
GP5=0x5,
GP6=0x6,
GP7=0x7,
}Intctrl_Group_priority;

typedef enum{
SGP0=0x0,
SGP1=0x1,
SGP2=0x2,
SGP3=0x3,
SGP4=0x4,
SGP5=0x5,
SGP6=0x6,
SGP7=0x7,
}Intctrl_SupGroup_priority;

typedef enum{
    INT_EN=1,
    INT_DIS=0,
}IntCtrl_Statustype;

typedef struct{
 IntCtrl_ExceptiontType       ExceptiontType;
 //IntCtrl_InterruptType        InterruptType;
 //IntCtrl_Priority_Levels      PriorityLevel;
 //Intctrl_Group_priority       GroupPriority;
 //Intctrl_SupGroup_priority    SupGroupPriority;
 IntCtrl_Statustype           statusType;
}User_data_type;

 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
