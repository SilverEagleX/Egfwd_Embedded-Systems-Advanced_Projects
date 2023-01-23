
#include "PORT.h"
#include "DIO.h"
#include "SYSTick.h"
#include "LED.h"
#include "IntCtrl.h"

/*****************************************************************************/


/*****************************************************************************/
volatile uint8 T_ON=2;    //defult 1 SEC
volatile uint8 T_OFF=1;   //defult 1 SEC
volatile uint8 counter=0;
volatile uint8 flag=0;
/******************************************************************************/

void FUN(void);
void Period_InSec( void);

/******************************************************************************/
int main(void){

IntCrtl_Init();
PORT_Init(STR_PortsConfig);
SYSTick_Init(ST_MAX_VALUE);//0x00FFFFFF


	while(1){
		 Period_InSec( ); // get clicks from user
		SysTick_Callback(FUN);

	}
	
	return 0;
}

void Period_InSec( void){
	// sw1
	if(DIO_ReadChannel(PIND0)==1){
		 T_ON ++;
	  while (DIO_ReadChannel(PIND0));
	}
     // SW2
	if( DIO_ReadChannel(PIND4)==1){

         T_OFF++;

	   while (DIO_ReadChannel(PIND4));
	}
        
	     
}

void FUN(void){

 counter++;

if( counter ==(T_OFF) && flag==0){	
	
   LED_ON();
	
    counter=0;
	flag=1;
 }
 else if(counter==(T_ON)&&flag==1)
 {
 LED_OFF();
	counter=0;
	 flag=0;
 }else if (counter>250)
 {
	counter=0;
 }
 

}