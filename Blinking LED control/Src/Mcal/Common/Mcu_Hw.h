/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*================================================  core reg ========================================================*/

#define CORTEXM4_PERI_BASE_ADDRESS              0xE000E000
/*********************************************System Timer (SysTick)***************************************************/
#define STCTRL                (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x0010)) // SysTick Control and Status
#define ENABLE       (0)
#define INTEN        (1)   // Interrupt Enabl
#define CLK_SRC      (2)   // Clock Source
#define COUNT        (16)  // Count Flag

#define STRELOAD              (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x0014)) // SysTick Reload Value 
#define STCURRENT             (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x0018)) // SysTick Current Value


/******************************************* IntCtrl ****************************************************/

                                           /* NVIC */
 /*****************************************************************************************************************************                                         
//  #define EN0         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))   //Register 4: Interrupt 0-31 SetEnable
//  #define EN1         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))   //Register 5: Interrupt 32-63 Set Enable
//  #define EN2         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))   //Register 6: Interrupt 64-95 Set Enable
//  #define EN3         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))   //Register 7: Interrupt 96-127 Set Enable
//  #define EN4         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))   //Register 8: Interrupt 128-138 Set Enable
 
//  #define DIS0        (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))   //Register 9: Interrupt 0-31 Clear Enable  
//  #define DIS1        (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))   //Register 10: Interrupt 32-63 Clear Enable
//  #define DIS2        (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))   //Register 11: Interrupt 64-95 Clear Enabl
//  #define DIS3        (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))   //Register 12: Interrupt 96-127 Clear Enable
//  #define DIS4        (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))   //Register 13: Interrupt 128-138 Clear Enable

//  #define PEND0       (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))   //Register 14: Interrupt 0-31 Set Pending  
//  #define PEND1       (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))   //Register 15: Interrupt 32-63 Set Pending 
//  #define PEND2       (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))   //Register 16: Interrupt 64-95 Set Pending
//  #define PEND3       (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))   //Register 17: Interrupt 96-127 Set Pending
//  #define PEND4       (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))   //Register 18: Interrupt 128-138 Set Pending

//  #define UNPEND0     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))   //Register 19: Interrupt 0-31 Clear Pending  
//  #define UNPEND1     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x284))   //Register 20: Interrupt 32-63 Clear Pending
//  #define UNPEND2     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x288))   //Register 21: Interrupt 64-95 Clear Pending
//  #define UNPEND3     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C))   //Register 22: Interrupt 96-127 Clear Pending
//  #define UNPEND4     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x290))   //Register 23: Interrupt 128-138 Clear Pending

//  #define ACTIVE0     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))   //Register 24: Interrupt 0-31 Active Bit  
//  #define ACTIVE1     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304))   //Register 25: Interrupt 32-63 Active Bit
//  #define ACTIVE2     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308))   //Register 26: Interrupt 64-95 Active Bit
//  #define ACTIVE3     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C))   //Register 27: Interrupt 96-127 Active Bit
//  #define ACTIVE4     (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310))   //Register 28: Interrupt 128-138 Active Bit
*********************************************************************************************************************************/

#define ENx(i)          (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x0100+((i/32)*32))))  //Interrupt (i) Set Enable
#define DISx(i)         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x0180+((i/32)*32))))  //Interrupt (i) Clear Enable
#define PENDx(i)        (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x0200+((i/32)*32))))  //Interrupt (i) Set Pending
#define UNPENDX(i)      (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x0280+((i/32)*32))))  //Interrupt (i) Clear Pending
#define ACTIVEX(i)      (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x0300+((i/32)*32))))  //Interrupt (i) Active Bit

#define PRIx(i)         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x0400+((i/4)*4))))    //Interrupt (i) Priority 


 #define SWTRIG         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))   //Register 64: Software Trigger Interrupt


 

                                /**************** SCB ************** */
 
//#define FAULTSTA       (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008)) //Register 65: Auxiliary Control

#define SYSPRI3         (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20)) //Register 74: System Handler Priority 3     SysTick(priority) 


 #define APINT                  (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x0D0C))  //Register 69: Application Interrupt and Reset Control
 #define INTCTRL                (*(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x0D04))

/******============================================================================================================********/
/*======================================= ======== ==================================================*/
/*==================================== System Control  =============================================*/
 #define SYS_CONTROL_BAIS_ADDRESS               0x400FE000
 #define RCGCGPIO                               (*(volatile uint32*)(SYS_CONTROL_BAIS_ADDRESS+0x0608))


/*=========================================== ==== =============================================*/
/*=========================================== GPIO =============================================*/

      /********************************* config *************************/                           
 #define  AHB    1
 #define  APB    2
 #define SELLECT   APB      // write APB  or AHB for preferred bus
      /******************************************************************/
 #if SELLECT == APB
 # define GPIO_OFFSET(i)    (i<4?((0x40004000)+((i)*(0x1000))):((0x40024000)+((i-4)*(0x1000))))
    /*
    GPIO Port A (APB): 0x4000.4000
    GPIO Port B (APB): 0x4000.5000
    GPIO Port C (APB): 0x4000.6000
    GPIO Port D (APB): 0x4000.7000
    GPIO Port E (APB): 0x4002.4000
    GPIO Port F (APB): 0x4002.5000
    */
 #warning "APB is in use "
 #elif SELLECT == AHB
 #define GPIO_OFFSET(i)    ((0x40058000)+((i)*(0x1000)))
    /*
    GPIO Port A (AHB): 0x4005.8000
    GPIO Port B (AHB): 0x4005.9000
    GPIO Port C (AHB): 0x4005.A000
    GPIO Port D (AHB): 0x4005.B000
    GPIO Port E (AHB): 0x4005.C000
    GPIO Port F (AHB): 0x4005.D000
    */
 #warning "AHB is in use "
 #endif


  #define  GPIODATA(i)     (*(volatile uint32*)(GPIO_OFFSET(i)+(0x03FC)))    // GPIO Data 
  #define  GPIODIR(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0400)))    // GPIO Direction 
  #define  GPIOIS(i)       (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0404)))    // GPIO Interrupt Sense 
  #define  GPIOIBE(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0408)))    // GPIO Interrupt Both Edges  
  #define  GPIOIEV(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x040C)))    // GPIO Interrupt Event  
  #define  GPIOIM(i)       (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0410)))    // GPIO Interrupt Mask  
  #define  GPIORIS(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0414)))    // GPIO Raw Interrupt Status  
  #define  GPIOMIS(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0418)))    // GPIO Masked Interrupt Status  
  #define  GPIOICR(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x041C)))    // GPIO Interrupt Clear  
  #define  GPIOAFSEL(i)    (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0420)))    // GPIO Alternate Function Select  
  #define  GPIODR2R(i)     (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0500)))    // GPIO 2-mA Drive Select  
  #define  GPIODR4R(i)     (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0504)))    // GPIO 4-mA Drive Select  
  #define  GPIODR8R(i)     (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0508)))    // GPIO 8-mA Drive Select  
  #define  GPIOODR(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x050C)))    // GPIO Open Drain Select  
  #define  GPIOPUR(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0510)))    // GPIO Pull-Up Select  
  #define  GPIOPDR(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0514)))    // GPIO Pull-Down Select  
  #define  GPIOSLR(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0518)))    // GPIO Slew Rate Control Select  
  #define  GPIODEN(i)      (*(volatile uint32*)(GPIO_OFFSET(i)+(0x051C)))    // GPIO Digital Enable  
  #define  GPIOLOCK(i)     (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0520)))    // GPIO Lock  
  #define  GPIOCR(i)       (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0524)))    // GPIO Commit  
  #define  GPIOAMSEL(i)    (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0528)))    // GPIO Analog Mode Select  
  #define  GPIOPCTL(i)     (*(volatile uint32*)(GPIO_OFFSET(i)+(0x052C)))    // GPIO Port Control  
  #define  GPIOADCCTL(i)   (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0530)))    // GPIO ADC Control  
  #define  GPIODMACTL(i)   (*(volatile uint32*)(GPIO_OFFSET(i)+(0x0534)))    // GPIO DMA Control  



/*=========================================== ==== =============================================*/


 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
