/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 /* PORT config  */
const PORT_ConfigType STR_PortsConfig[TNUM_OfAPINS]={
 /*  PinMode  ,  PinLevel ,  PinDirection   ,PinInternalAttach ,   PinOutputCur  ,PORT NUM , Pin num    */
{PORT_PIN_DEN , PORT_LOW   , PORT_PIN_INPUT  , PORT_PIN_PULL_DOWN , PORT_PIN_CUR_2MA , PORT_D , PORT_PIN_0},  // SW1
{PORT_PIN_DEN , PORT_LOW   , PORT_PIN_INPUT  , PORT_PIN_PULL_DOWN , PORT_PIN_CUR_2MA , PORT_D , PORT_PIN_4},  // SW2
{PORT_PIN_DEN , PORT_LOW  , PORT_PIN_OUTPUT , PORT_PIN_PULL_UP , PORT_PIN_CUR_2MA , PORT_F , PORT_PIN_1},  // Poard Red    Led
{PORT_PIN_DEN , PORT_LOW   , PORT_PIN_OUTPUT , PORT_PIN_PULL_UP , PORT_PIN_CUR_4MA , PORT_F , PORT_PIN_2},  // Poard Blue   Led
{PORT_PIN_DEN , PORT_LOW   , PORT_PIN_OUTPUT , PORT_PIN_PULL_UP , PORT_PIN_CUR_8MA , PORT_F , PORT_PIN_3},  // Poard Green  Led
};



/**********************************************************************************************************************
 *  END OF FILE: PORT_Lcfg.c
 *********************************************************************************************************************/
