/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "lpc21xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )
	
//--------------------------------------------------------------------->
/* TASK PERIODS */
#define Period_T1  50
#define Period_T2  50
#define Period_T3  100
#define Period_T4  20
#define Period_T5  10
#define Period_T6  100
//---------------------------------------------------------------------->
/* TASK HANDLERS */
TaskHandle_t T_1_Button_1_Handler = NULL;
TaskHandle_t T_2_Button_2_Handler = NULL;
TaskHandle_t T_3_Periodic_TR_Handler = NULL;
TaskHandle_t T_4_Uart_RE_Handler = NULL;
TaskHandle_t T_5_Load_1_Handler = NULL;
TaskHandle_t T_6_Load_2_Handler = NULL;

QueueHandle_t xQueue = NULL;
//---------------------------------------------------------------------->

int task_1_IN_Time = 0, task_1_OUT_Time = 0, task_1_TotalTime;
int task_2_IN_Time = 0, task_2_OUT_Time = 0, task_2_TotalTime;
int task_3_IN_Time = 0, task_3_OUT_Time = 0, task_3_TotalTime;
int task_4_IN_Time = 0, task_4_OUT_Time = 0, task_4_TotalTime;
int task_5_IN_Time = 0, task_5_OUT_Time = 0, task_5_TotalTime;
int task_6_IN_Time = 0, task_6_OUT_Time = 0, task_6_TotalTime;
int system_Time = 0;
float CPU_Load = 0;

  pinState_t Current_State_B1=PIN_IS_LOW;// task_1
	pinState_t Current_State_B2=PIN_IS_LOW;// task_2
    char* Data1=" button 1  Rising Edge "; // task_1
		char* Data2=" button 1  Falling Edge"; // task_1
		char* Data3=" button 2  Rising Edge "; // task_2
		char* Data4=" button 2  Falling Edge"; // task_2
		char* Data5=" mohamed elshaarawt ^_^"; // task_3
		char* pvBuffer = (void*)0;// task_4

/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/
/*Tasks prototypes*/

void Button_1_Task( void * pvParameters );


void Button_2_Task( void * pvParameters );


void Periodic_TR_Task( void *pvParameters );


void Uart_RE_Task( void *pvParameters );


void Load_1_Task( void *pvParameters );


void Load_2_Task( void *pvParameters );



/*  Implement TickHook */

void vApplicationTickHook( void ){


	GPIO_write(PORT_0,PIN2,PIN_IS_HIGH);
	GPIO_write(PORT_0,PIN2,PIN_IS_LOW);

}

/*  Implement IdleHook */
void vApplicationIdleHook( void ){

	GPIO_write(PORT_0,PIN3,PIN_IS_HIGH);
	GPIO_write(PORT_0,PIN3,PIN_IS_LOW);

}



/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	
  /* Attempt to create a Queue. */
     xQueue = xQueueCreate( 10, sizeof( char* ) );
    /* Create Tasks here */
	
	/* Create the task, storing the handle. */
     xTaskPeriodicCreate(
                    Button_1_Task,       /* Function that implements the task. */
                    "Button_1_Monitor",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
                    4,/* Priority at which the task is created. */
                    &T_1_Button_1_Handler, /* Used to pass out the created task's handle. */
										 Period_T1);  /*Task_Period*/    
										
	   xTaskPeriodicCreate(
                    Button_2_Task,       /* Function that implements the task. */
                    "Button_2_Monitor",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
                    4,/* Priority at which the task is created. */
                    &T_2_Button_2_Handler,  /* Used to pass out the created task's handle. */	
										Period_T2);  /*Task_Period*/

		xTaskPeriodicCreate(
                    Periodic_TR_Task,       /* Function that implements the task. */
                    "Periodic_Transmitter",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
                    4,/* Priority at which the task is created. */
                    &T_3_Periodic_TR_Handler,  /* Used to pass out the created task's handle. */	
										Period_T3);  /*Task_Period*/    						

		xTaskPeriodicCreate(
                    Uart_RE_Task,       /* Function that implements the task. */
                    "Uart_Receiver",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
                    4,/* Priority at which the task is created. */
                    &T_4_Uart_RE_Handler,  /* Used to pass out the created task's handle. */	
										Period_T4);  /*Task_Period*/    						    								

		xTaskPeriodicCreate(
                    Load_1_Task,       /* Function that implements the task. */
                    "Load_1_Simulation",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
                    4,/* Priority at which the task is created. */
                    &T_5_Load_1_Handler,  /* Used to pass out the created task's handle. */	
										Period_T5);  /*Task_Period*/    	
										
		xTaskPeriodicCreate(
                    Load_2_Task,       /* Function that implements the task. */
                    "Load_2_Simulation",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * ) 0,    /* Parameter passed into the task. */
                    4,/* Priority at which the task is created. */
                    &T_6_Load_2_Handler,  /* Used to pass out the created task's handle. */	
										Period_T6);  /*Task_Period*/    	

	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Task_1  */
void Button_1_Task( void * pvParameters )
{
	int xLastWakeTime = xTaskGetTickCount();
pinState_t Prev_State_B1=PIN_IS_LOW;
	 vTaskSetApplicationTaskTag( NULL, ( void * ) 1 );

    for( ;; )
    {
        /* Task code goes here. */
			Current_State_B1=GPIO_read(PORT_0,PIN0);
					if(Current_State_B1 ==PIN_IS_HIGH &&  Prev_State_B1 == PIN_IS_LOW)
		{
			//Send " button 1  Rising Edge"
			if(xQueue != 0)
			{
				xQueueSend(xQueue, (void *) &Data1, ( TickType_t ) 0 );
			}
		}
		else if(Current_State_B1 ==PIN_IS_LOW && Prev_State_B1 == PIN_IS_HIGH)
		{
			//Send " button 1  Falling Edge"
			if(xQueue != 0)
			{
				
				xQueueSend(xQueue, (void *) &Data2, (TickType_t)0);
			}
		}
			

			
      Prev_State_B1=Current_State_B1;
			

			
		   vTaskDelayUntil(&xLastWakeTime,Period_T1);
			
			
    }
}

/* Task_2  */

void Button_2_Task( void * pvParameters )
{
	int xLastWakeTime = xTaskGetTickCount();
	pinState_t Prev_State_B2=PIN_IS_LOW;
 vTaskSetApplicationTaskTag( NULL, ( void * ) 2 );

    for( ;; )
    {
        /* Task code goes here. */

						Current_State_B2=GPIO_read(PORT_0,PIN1);
		if(Current_State_B2 ==PIN_IS_HIGH &&  Prev_State_B2 == PIN_IS_LOW)
		{
			//Send " button 2  Rising Edge"
			if(xQueue != 0)
			{
				xQueueSend(xQueue, (void *) &Data3, ( TickType_t ) 0 );
			}
		}
		else if(Current_State_B2 ==PIN_IS_LOW && Prev_State_B2 == PIN_IS_HIGH)
		{
			//Send " button 2  Falling Edge"
			if(xQueue != 0)
			{
				
				xQueueSend(xQueue, (void *) &Data4, (TickType_t)0);
			}
		}
					
			
		
            Prev_State_B2=Current_State_B2;

				  vTaskDelayUntil(&xLastWakeTime,Period_T2);

    }
}
/* Task_3 */

void Periodic_TR_Task( void *pvParameters )
{
	int xLastWakeTime = xTaskGetTickCount();
   
    vTaskSetApplicationTaskTag( NULL, ( void * ) 3 );

    for( ;; )
    {
        /* Task code goes here. */
			//Send " string "
			
						if(xQueue != 0)
			{
				xQueueSend(xQueue, (void *) &Data5, ( TickType_t ) 0 );
			}
		
			
			
			vTaskDelayUntil(&xLastWakeTime,Period_T3);
    }
}

/* Task_4 */

void Uart_RE_Task( void *pvParameters )
{
	int xLastWakeTime = xTaskGetTickCount();
    
   vTaskSetApplicationTaskTag( NULL, ( void * ) 4 );

    for( ;; )
    {
        /* Task code goes here. */
			if( xQueue != NULL ){
			   if( xQueueReceive( xQueue,&( pvBuffer ),( TickType_t ) 10 ) == pdPASS )
      {
        vSerialPutString((const signed char*) pvBuffer, 23);
				xSerialPutChar('\n');
      }
		}
			vTaskDelayUntil(&xLastWakeTime,Period_T4);
    }
}

/* Task_5 */
void Load_1_Task( void *pvParameters )
{
   int xLastWakeTime = xTaskGetTickCount();
	 unsigned int i=0;
    vTaskSetApplicationTaskTag( NULL, ( void * ) 5 );

    for( ;; )
    {
        /* Task code goes here. */
			for(i=0;i<37100;i++){
			}
			
			vTaskDelayUntil(&xLastWakeTime,Period_T5);
    }
}
/* Task_6 */

void Load_2_Task( void *pvParameters )
{
   int xLastWakeTime = xTaskGetTickCount();
	 unsigned int i=0;
    vTaskSetApplicationTaskTag( NULL, ( void * ) 6 );

    for( ;; )
    {
        /* Task code goes here. */
						for(i=0;i<89000;i++){
			}
			
			vTaskDelayUntil(&xLastWakeTime,Period_T6);
    }
}



/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


