/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  System Timer (SysTick)
 *
 *      \details  Initializes (SysTick) 
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SYSTick.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
  
static void (*Callback_Ptr)(void)= NULL_PTR;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/* Init SysTimer */
void SYSTick_Init(uint32 Value){
    /*1. Program the value in the STRELOAD register.*/
      STRELOAD = Value;
    /*2. Clear the STCURRENT register by writing to it with any value.*/
      STCURRENT = 0 ;
    /*3. Configure the STCTRL register for the required operation*/
    SET_BIT(STCTRL,ENABLE); // enable timer
    SET_BIT(STCTRL,INTEN ); // enable interrupt
	SET_BIT(STCTRL,CLK_SRC); 
} 

/* dusable  SysTimer */
void SYSTick_disable(void){
    CLEAR_BIT(STCTRL,ENABLE);   // disable timer
    CLEAR_BIT(STCTRL,INTEN );   // disable interrupt
}
/************************** reset time **************************/
void SYSTick_Period(uint32 Period){
    STRELOAD = Period;
}

/************************************CallbackFun***********************************/

void SysTick_Callback(void(*Ptr)(void)){
  
    if(Ptr != NULL_PTR ){

        Callback_Ptr = Ptr;
    }

}


void SysTick_Handler (void){

    if(Callback_Ptr != NULL_PTR  ){
        Callback_Ptr();
    }

}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
