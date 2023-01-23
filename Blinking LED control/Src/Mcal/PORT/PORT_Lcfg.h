/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PORT_Lcfg.h
 *       Module:  GPIO (general purpose input/output)
 *
 *  Description:  Contains Compiler Dependent MACRO Definition     
 *  
 *********************************************************************************************************************/
#ifndef PORT_LCFG_H
#define PORT_LCFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TNUM_OfAPINS      (5)  // total number of active pins


/**********************************************************************************************************************
 * Local DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
PORT_PIN_0=0,
PORT_PIN_1,
PORT_PIN_2,
PORT_PIN_3,
PORT_PIN_4,
PORT_PIN_5,
PORT_PIN_6,
PORT_PIN_7
}PORT_PinType;


typedef enum{
 PORT_A=0,
 PORT_B,
 PORT_C,
 PORT_D,
 PORT_E,
 PORT_F
}PORT_Num;

typedef enum{
PORT_LOW=0,
PORT_HIGH
}PORT_PinLevel;

typedef enum{
   PORT_PIN_INPUT=0,
   PORT_PIN_OUTPUT=1
}PORT_PinDirectionType;

typedef enum{
  PORT_PIN_DEN=0,
  /*todo:not complete yet */
}PORT_PinModeType;

typedef enum{
 PORT_PIN_PULL_UP=0,
 PORT_PIN_PULL_DOWN,
 PORT_PIN_OPEN_DRAIN
}PORT_PinInternalAttachType;

typedef enum{
 PORT_PIN_CUR_2MA=0,
 PORT_PIN_CUR_4MA,
 PORT_PIN_CUR_8MA 
}PORT_PinOutputCurrentType;


typedef struct{
    PORT_PinModeType                PortPinMode;
    PORT_PinLevel                   PortPinLevelValue;
    PORT_PinDirectionType           PortPinDirection;
    PORT_PinInternalAttachType      PortPinInternalAttach;
    PORT_PinOutputCurrentType       PortPinOutputCurrent;
    PORT_Num                        PortNum;
    PORT_PinType                    PortPinNum;

}PORT_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Lcfg.h
 *********************************************************************************************************************/