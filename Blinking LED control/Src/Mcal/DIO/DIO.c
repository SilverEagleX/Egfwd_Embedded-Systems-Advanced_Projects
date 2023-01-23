/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  digital input/output driver
 *
 *      \details  The Driver Configure All DIO Ports AND Pins
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DIO.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/* read channel  value  */
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId){

     DIO_LevelType Level=LOW;
     DIO_PortType port;
	  uint8 Pin_Num;
      if(ChannelId<PINE0){
        port=ChannelId/8;
        Pin_Num=ChannelId%8;
      }
      else if ((ChannelId>PIND7)&&(ChannelId<PINF0))
      {
        port=PE;
        Pin_Num=ChannelId%32;
      }else{
                port=PF;
        Pin_Num=ChannelId%38;
      }
      

	  switch(port)
	  {
		  case PA:      
		 Level= READ_BIT(GPIODATA(PA),Pin_Num);
		  break;
		  case PB:
		 Level= READ_BIT(GPIODATA(PB),Pin_Num);
		  break;
		  case PC:
		 Level= READ_BIT(GPIODATA(PC),Pin_Num);
		  break;
		  case PD:
		 Level= READ_BIT(GPIODATA(PD),Pin_Num);
		  break;
          case PE:
		 Level= READ_BIT(GPIODATA(PE),Pin_Num);
		  break;
		  case PF:
		 Level= READ_BIT(GPIODATA(PF),Pin_Num);
		  break;
	  }
	  return Level;
}

/* write value(0||1) at channel  */
void DIO_WriteChannel(DIO_ChannelType ChannelId,DIO_LevelType Level){
      DIO_PortType port;
	  uint8 Pin_Num;
      if(ChannelId<PINE0){
        port=ChannelId/8;
        Pin_Num=ChannelId%8;
      }
      else if ((ChannelId>PIND7)&&(ChannelId<PINF0))
      {
        port=PE;
        Pin_Num=ChannelId%32;
      }else{
                port=PF;
        Pin_Num=ChannelId%38;
      }
      
	 if (Level==HIGH)
	 {
		  switch(port)
		  {
		  case PA:      
		   SET_BIT(GPIODATA(PA),Pin_Num);
		  break;
		  case PB:
		   SET_BIT(GPIODATA(PB),Pin_Num);
		  break;
		  case PC:
		   SET_BIT(GPIODATA(PC),Pin_Num);
		  break;
		  case PD:
		   SET_BIT(GPIODATA(PD),Pin_Num);
		  break;
          case PE:
		   SET_BIT(GPIODATA(PE),Pin_Num);
		  break;
		  case PF:
		   SET_BIT(GPIODATA(PF),Pin_Num);
		  break;
          }
	 }else if(Level==LOW){
		  switch(port)
		  {
		  case PA:      
		   CLEAR_BIT(GPIODATA(PA),Pin_Num);
		  break;
		  case PB:
		   CLEAR_BIT(GPIODATA(PB),Pin_Num);
		  break;
		  case PC:
		   CLEAR_BIT(GPIODATA(PC),Pin_Num);
		  break;
		  case PD:
		   CLEAR_BIT(GPIODATA(PD),Pin_Num);
		  break;
          case PE:
		   CLEAR_BIT(GPIODATA(PE),Pin_Num);
		  break;
		  case PF:
		   CLEAR_BIT(GPIODATA(PF),Pin_Num);
		  break;
		  }
	 }

}

/* read value at Port  */
DIO_PortLevelType DIO_ReadPort(DIO_PortType PortId,DIO_PortLevelType Level){
	 switch(PortId)
	 {
		 case PA:
		 Level= GPIODATA(PA);
		 break;
		 case PB:
		 Level= GPIODATA(PB);
		 break;
		 case PC:
		 Level= GPIODATA(PC);
		 break;
		 case PD:
		 Level= GPIODATA(PD);
		 break;
         case PE:
		 Level= GPIODATA(PE);
		 break;
		 case PF:
		 Level= GPIODATA(PF);
		 break;
	 }
	 return Level;

}

/* write value(0->255) at Port  */
void DIO_WritePort(DIO_PortType PortId,DIO_PortLevelType Level){
 switch(PortId)
	 {
		 case PA:
		 GPIODATA(PA)=Level;
		 break;
		 case PB:
		 GPIODATA(PB)=Level;
		 break;
		 case PC:
		 GPIODATA(PC)=Level;
		 break;
		 case PD:
		 GPIODATA(PD)=Level;
		 break;
         case PE:
		 GPIODATA(PE)=Level;
		 break;
		 case PF:
		 GPIODATA(PF)=Level;
		 break;
	 }
	 
}

/* togle channel  value(0->1||1->0)  */
DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId){
      DIO_LevelType Level=LOW;
      DIO_PortType port;
	  uint8 Pin_Num;
      if(ChannelId<PINE0){
        port=ChannelId/8;
        Pin_Num=ChannelId%8;
      }
      else if ((ChannelId>PIND7)&&(ChannelId<PINF0))
      {
        port=PE;
        Pin_Num=ChannelId%32;
      }else{
                port=PF;
        Pin_Num=ChannelId%38;
      }
	  switch(port)
	  {
		  case PA:      
		    TOG_BIT(GPIODATA(PA),Pin_Num);
            Level=READ_BIT(GPIODATA(PA),Pin_Num);
		  break;
		  case PB:
		    TOG_BIT(GPIODATA(PB),Pin_Num);
            Level=READ_BIT(GPIODATA(PB),Pin_Num);
		  break;
		  case PC:
		    TOG_BIT(GPIODATA(PC),Pin_Num);
            Level=READ_BIT(GPIODATA(PC),Pin_Num);
		  break;
		  case PD:
		    TOG_BIT(GPIODATA(PD),Pin_Num);
            Level=READ_BIT(GPIODATA(PD),Pin_Num);
		  break;
          case PE:
		    TOG_BIT(GPIODATA(PE),Pin_Num);
            Level=READ_BIT(GPIODATA(PE),Pin_Num);
		  break;
		  case PF:
		    TOG_BIT(GPIODATA(PF),Pin_Num);
            Level=READ_BIT(GPIODATA(PF),Pin_Num);
		  break;
	  }
      return Level;
}


/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
