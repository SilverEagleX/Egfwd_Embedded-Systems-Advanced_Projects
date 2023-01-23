/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  -
 *
 *  Description:  Contains Compiler Dependent MACRO Definition     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Utils.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
     PINA0=0,
	 PINA1=1,
	 PINA2,
	 PINA3,
	 PINA4,
	 PINA5,
	 PINA6,
	 PINA7,
	 PINB0,
	 PINB1,
	 PINB2,
	 PINB3,
	 PINB4,
	 PINB5,
	 PINB6,
	 PINB7,
	 PINC0,
	 PINC1,
	 PINC2,
	 PINC3,
	 PINC4,
	 PINC5,
	 PINC6,
	 PINC7,
	 PIND0,
	 PIND1,
	 PIND2,
	 PIND3,
	 PIND4,
	 PIND5,
	 PIND6,
	 PIND7,
     PINE0,
	 PINE1,
	 PINE2,
	 PINE3,
	 PINE4,
	 PINE5,
     PINF0,
	 PINF1,
	 PINF2,
	 PINF3,
	 PINF4,
	 TOTAL_PINS
}DIO_ChannelType; 
typedef enum{
     PA=0,
	 PB,
	 PC,
	 PD,
     PE,
     PF
}DIO_PortType;
typedef enum{
LOW=0,
HIGH
}DIO_LevelType;

typedef uint8      DIO_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId);
void DIO_WriteChannel(DIO_ChannelType ChannelId,DIO_LevelType Level);
DIO_PortLevelType DIO_ReadPort(DIO_PortType PortId,DIO_PortLevelType Level);
void DIO_WritePort(DIO_PortType PortId,DIO_PortLevelType Level);
DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId);

 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
