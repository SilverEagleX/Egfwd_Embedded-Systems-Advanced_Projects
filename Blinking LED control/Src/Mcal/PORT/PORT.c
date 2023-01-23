/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT.c
 *        \brief  PORT
 *
 *      \details  Initializes MCU PORTS
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
//============== not used for this project==============//               
// #define PORT_LOCK_VALUE          (uint32)(0x4c4f434b)//
// #define BIT_MASKING_OFFSET        (uint8)(2)         //
// #define PCTL_PIN_MASK            (uint32)(0x0000000F)//
// #define PCTL_BIN_BIT_NUM          (uint8)(4)         //
// #define MIN_PCTL_VAL              (uint8)(1)         //
// #define MAX_PCTL_VAL              (uint8)(15)        //
//======================================================//

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void PORT_Init(const PORT_ConfigType* ConfigPtr )                                      
* \Description     : Initializes MCU PORTS                                   
*******************************************************************************/
void PORT_Init(const PORT_ConfigType* ConfigPtr )
{

  uint8 PinCount =0;

  for(PinCount=0;PinCount<TNUM_OfAPINS;PinCount++){

   PORT_Num Port_N = ConfigPtr[PinCount].PortNum;
   PORT_PinType Pin_N = ConfigPtr[PinCount].PortPinNum;
   /* 1-Initialize the clock */
   SET_BIT(RCGCGPIO,Port_N);
   /* 2-set the Direction */
   if(PORT_PIN_OUTPUT == ConfigPtr[PinCount].PortPinDirection){
    SET_BIT(GPIODIR(Port_N),Pin_N);
		  /* PinLevel  */
		 	 switch (ConfigPtr[PinCount].PortPinLevelValue)
       {
       case PORT_HIGH :
        SET_BIT(GPIODATA(Port_N),Pin_N);
        break;
       case PORT_LOW :
        CLEAR_BIT(GPIODATA(Port_N),Pin_N);
        break;               
       default:
        break;
       }
		 
    
   }else{
    CLEAR_BIT(GPIODIR(Port_N),Pin_N);
		   /*5. Program each pad in the port*/ 
		   switch (ConfigPtr[PinCount].PortPinInternalAttach)
       {
       case PORT_PIN_PULL_UP :
        SET_BIT(GPIOPUR(Port_N),Pin_N);
        break;
       case PORT_PIN_PULL_DOWN :
        SET_BIT(GPIOPDR(Port_N),Pin_N);
        break;
       case PORT_PIN_OPEN_DRAIN :
        SET_BIT(GPIOODR(Port_N),Pin_N);
        break;               
       default:
        break;
       }
  }

   
   /*3-Configure the GPIOAFSEL register (digital mode)*/
   if (PORT_PIN_DEN == ConfigPtr[PinCount].PortPinMode)
   {
     CLEAR_BIT(GPIOAFSEL(Port_N),Pin_N); // optional
     SET_BIT(GPIODEN(Port_N),Pin_N);
     CLEAR_BIT(GPIOAMSEL(Port_N),Pin_N); // optional
   }else{
    break;
   }
   

   /*4-set the drive strenth */
    switch (ConfigPtr[PinCount].PortPinOutputCurrent)
    {
    case PORT_PIN_CUR_2MA:
        SET_BIT(GPIODR2R(Port_N),Pin_N);
        break;
    case PORT_PIN_CUR_4MA:
        SET_BIT(GPIODR4R(Port_N),Pin_N);
        break;
    case PORT_PIN_CUR_8MA:
        SET_BIT(GPIODR8R(Port_N),Pin_N);
        break;    
    default:
        break;
    }

 
	}
	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
