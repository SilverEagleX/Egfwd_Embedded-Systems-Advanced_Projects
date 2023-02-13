/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <lpc21xx.h>
#include "GPIO.h"


extern int task_1_IN_Time , task_1_OUT_Time , task_1_TotalTime;
extern int task_2_IN_Time , task_2_OUT_Time , task_2_TotalTime;
extern int task_3_IN_Time , task_3_OUT_Time , task_3_TotalTime;
extern int task_4_IN_Time , task_4_OUT_Time , task_4_TotalTime;
extern int task_5_IN_Time , task_5_OUT_Time , task_5_TotalTime;
extern int task_6_IN_Time , task_6_OUT_Time , task_6_TotalTime;
extern int system_Time ;
extern float CPU_Load ;

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION		1
#define configUSE_IDLE_HOOK			1
#define configUSE_TICK_HOOK			1
#define configCPU_CLOCK_HZ			( ( unsigned long ) 60000000 )	/* =12.0MHz xtal multiplied by 5 using the PLL. */
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES		( 4 )
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 90 )
#define configTOTAL_HEAP_SIZE		( ( size_t ) 13 * 1024 )
#define configMAX_TASK_NAME_LEN		( 8 )
#define configUSE_TRACE_FACILITY	1
#define configUSE_16_BIT_TICKS		0
#define configIDLE_SHOULD_YIELD		1
#define configUSE_TIME_SLICING    0
#define configUSE_EDF_SCHEDULER   1 //------------------------------------->EDF


#define configQUEUE_REGISTRY_SIZE 	0



#define configUSE_APPLICATION_TASK_TAG 1
/* Trace hooks */
#define traceTASK_SWITCHED_IN()   do{\
																			if((int)pxCurrentTCB->pxTaskTag == 1)\
																				{\
																				GPIO_write(PORT_0,PIN4,PIN_IS_HIGH);\
																				  task_1_IN_Time = T1TC;	\
																				}else if((int)pxCurrentTCB->pxTaskTag == 2)\
																				{\
																				GPIO_write(PORT_0,PIN5,PIN_IS_HIGH);\
																					task_2_IN_Time = T1TC;\
																				}else if((int)pxCurrentTCB->pxTaskTag == 3)\
																				{\
																				GPIO_write(PORT_0,PIN6,PIN_IS_HIGH);\
																					task_3_IN_Time =T1TC;\
																				}else if((int)pxCurrentTCB->pxTaskTag == 4)\
																				{\
																				GPIO_write(PORT_0,PIN7,PIN_IS_HIGH);\
																					task_4_IN_Time =T1TC;\
																				}else if((int)pxCurrentTCB->pxTaskTag == 5)\
																				{\
																				GPIO_write(PORT_0,PIN8,PIN_IS_HIGH);\
																					task_5_IN_Time =T1TC;\
																				}else if((int)pxCurrentTCB->pxTaskTag == 6)\
																				{\
																				GPIO_write(PORT_0,PIN9,PIN_IS_HIGH);\
																					task_6_IN_Time =T1TC;\
																				}\
																			}while(0)


#define traceTASK_SWITCHED_OUT()  do{\
																			if((int)pxCurrentTCB->pxTaskTag == 1)\
																				{\
																				GPIO_write(PORT_0,PIN4,PIN_IS_LOW);\
																					task_1_OUT_Time =T1TC;\
																					task_1_TotalTime +=(task_1_OUT_Time - task_1_IN_Time );\
																				}else if((int)pxCurrentTCB->pxTaskTag == 2)\
																				{\
																				GPIO_write(PORT_0,PIN5,PIN_IS_LOW);\
																					task_2_OUT_Time =T1TC;\
																					task_2_TotalTime +=(task_2_OUT_Time - task_2_IN_Time );\
																				}else if((int)pxCurrentTCB->pxTaskTag == 3)\
																				{\
																				GPIO_write(PORT_0,PIN6,PIN_IS_LOW);\
																					task_3_OUT_Time =T1TC;\
																					task_3_TotalTime +=(task_3_OUT_Time - task_3_IN_Time );\
																				}else if((int)pxCurrentTCB->pxTaskTag == 4)\
																				{\
																				GPIO_write(PORT_0,PIN7,PIN_IS_LOW);\
																					task_4_OUT_Time =T1TC;\
																					task_4_TotalTime +=(task_4_OUT_Time - task_4_IN_Time );\
																				}else if((int)pxCurrentTCB->pxTaskTag == 5)\
																				{\
																				GPIO_write(PORT_0,PIN8,PIN_IS_LOW);\
																					task_5_OUT_Time =T1TC;\
																					task_5_TotalTime +=(task_5_OUT_Time - task_5_IN_Time );\
																				}else if((int)pxCurrentTCB->pxTaskTag == 6)\
																				{\
																				GPIO_write(PORT_0,PIN9,PIN_IS_LOW);\
																					task_6_OUT_Time =T1TC;\
																					task_6_TotalTime +=(task_6_OUT_Time - task_6_IN_Time );\
																				}\
																				system_Time = T1TC;\
																				CPU_Load = ((task_1_TotalTime+task_2_TotalTime+task_3_TotalTime+task_4_TotalTime+task_5_TotalTime+task_6_TotalTime)/(float)system_Time)*100;\
																			}while(0)

/* configure run-time stats */

#define configUSE_STATS_FORMATTING_FUNCTIONS 0

#define configGENERATE_RUN_TIME_STATS  0

#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()  //configTimer1();

#define portGET_RUN_TIME_COUNTER_VALUE()  (T1TC)


/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1



#endif /* FREERTOS_CONFIG_H */
