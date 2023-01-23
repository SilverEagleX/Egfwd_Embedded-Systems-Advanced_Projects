/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"

/* APIs */

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
    IntCtrl_ExceptiontType Type=get_user_data.ExceptiontType;
    uint8 count=0;
    for( count=0;count<AINTNUM;count++){

      //Enable\Disable based on user configurations
      switch (Type)
      {
      case INTC_SYS_TICK:
           if(get_user_data.statusType){
         SET_BIT(STCTRL,INTEN ); // enable interrupt
           }else{
         CLEAR_BIT(STCTRL,INTEN ); // disable interrupt
           }
       
        break;
      
      default:
        break;
      }

    }




 
 


 /*
       uint8 count=0;
    for( count=0;count<AINTNUM;count++){
    IntCtrl_InterruptType IntName=get_user_data.InterruptType;
  	 //TODO Configure Grouping\SubGrouping System in APINT register in SCB
    switch (get_user_data.PriorityLevel)
    {
    case IPL0:
       APINT = 0xFA050000|IPL0;
        break;
    case IPL1:
       APINT = 0xFA050000|IPL1;
        break;
    case IPL2:
       APINT = 0xFA050000|IPL2;
        break;
    case IPL3:
       APINT = 0xFA050000|IPL3;
        break;
    default:
        break;
    }
    
    //TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers  
    switch (get_user_data.GroupPriority)
     {
     case GP0:
        PRIx(IntName)=GP0;
        break;
     case GP1:
        PRIx(IntName)=GP1;
        break;    
     case GP2:
        PRIx(IntName)=GP2;
        break;
     case GP3:
        PRIx(IntName)=GP3;
        break;
     case GP4:
        PRIx(IntName)=GP4;
        break;
     case GP5:
        PRIx(IntName)=GP5;
        break; 
     case GP6:
        PRIx(IntName)=GP6;
        break;
     case GP7:
        PRIx(IntName)=GP7;
        break;                                            
     default:
        break;
     }

	//TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers 
    switch (get_user_data.statusType)
    {
    case INT_EN:
        SET_BIT(ENx(IntName),0);
        break;
    case INT_DIS:
        SET_BIT(DISx(IntName),0);
        break;        
    
    default:
        break;
    }
   }  
*/
   
   
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
