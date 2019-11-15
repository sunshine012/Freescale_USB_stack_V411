/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : MK53N512MD100
**     Version     : Component 01.000, Driver 01.04, CPU db: 3.00.000
**     Datasheet   : K53P144M100SF2RM Rev. 6, 6 Nov 2011
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 11:51, # CodeGen: 16
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Cpu. */
#include "usb_host_audio.h"
#include "UART.h"
#include "PIT0.h"
#include "PWM.h"
#include "PTC13.h"
#include "PTC5.h"
#include "usb_host.h"
#include "USB_LDD.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"

/* Global variables */
volatile uint8_t SR_reg;               /* Current value of the FAULTMASK register */
volatile uint8_t SR_lock = 0x00U;      /* Lock */

/*
** ===================================================================
**     Method      :  Cpu_SetBASEPRI (component MK53N512MD100)
**
**     Description :
**         This method sets the BASEPRI core register.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cpu_SetBASEPRI(register uint32_t Level);

/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_PORTC (component MK53N512MD100)
**
**     Description :
**         This ISR services the ivINT_PORTC interrupt shared by several 
**         components.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_ivINT_PORTC)
{
  PTC13_Interrupt();                   /* Call the service routine */
  PTC5_Interrupt();                    /* Call the service routine */
}

/*
** ===================================================================
**     Method      :  Cpu_INT_NMIInterrupt (component MK53N512MD100)
**
**     Description :
**         This ISR services the Non Maskable Interrupt interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_INT_NMIInterrupt)
{
  Cpu_OnNMIINT();
}

/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MK53N512MD100)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  PE_DEBUGHALT();
}


/*** !!! Here you can place your own code using property "User data declarations" on the build options tab. !!! ***/

/*lint -esym(765,__init_hardware) Disable MISRA rule (8.10) checking for symbols (__init_hardware). The function is linked to the EWL library */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cpu_Interrupt). */
void __init_hardware(void)
{

  /*** !!! Here you can place your own code before PE initialization using property "User code before PE initialization" on the build options tab. !!! ***/

  /*** ### MK53DN512ZCMD10 "Cpu" init code ... ***/
  /*** PE initialization code after reset ***/
  SCB_VTOR = (uint32_t)(&__vect_table); /* Set the interrupt vector table position */
  /* Disable the WDOG module */
  /* WDOG_UNLOCK: WDOGUNLOCK=0xC520 */
  WDOG_UNLOCK = WDOG_UNLOCK_WDOGUNLOCK(0xC520); /* Key 1 */
  /* WDOG_UNLOCK: WDOGUNLOCK=0xD928 */
  WDOG_UNLOCK = WDOG_UNLOCK_WDOGUNLOCK(0xD928); /* Key 2 */
  /* WDOG_STCTRLH: ??=0,DISTESTWDOG=0,BYTESEL=0,TESTSEL=0,TESTWDOG=0,??=0,STNDBYEN=1,WAITEN=1,STOPEN=1,DBGEN=0,ALLOWUPDATE=1,WINEN=0,IRQRSTEN=0,CLKSRC=1,WDOGEN=0 */
  WDOG_STCTRLH = WDOG_STCTRLH_STNDBYEN_MASK |
                 WDOG_STCTRLH_WAITEN_MASK |
                 WDOG_STCTRLH_STOPEN_MASK |
                 WDOG_STCTRLH_ALLOWUPDATE_MASK |
                 WDOG_STCTRLH_CLKSRC_MASK;                       
  /* System clock initialization */
  /* SIM_SCGC5: PORTC=1,PORTA=1 */
  SIM_SCGC5 |= (SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTA_MASK); /* Enable clock gate for ports to enable pin routing */
  /* SIM_CLKDIV1: OUTDIV1=0,OUTDIV2=0,OUTDIV3=1,OUTDIV4=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = (SIM_CLKDIV1_OUTDIV3(0x01) | SIM_CLKDIV1_OUTDIV4(0x01)); /* Update system prescalers */
  /* SIM_CLKDIV2: USBDIV=0,USBFRAC=0 */
  SIM_CLKDIV2 &= (uint32_t)~(uint32_t)(
                  SIM_CLKDIV2_USBDIV(0x07) |
                  SIM_CLKDIV2_USBFRAC_MASK
                 );                    /* Update USB clock prescalers */
  /* SIM_SOPT2: PLLFLLSEL=1 */
  SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; /* Select PLL as a clock source for various peripherals */
  /* SIM_SOPT1: OSC32KSEL=0 */
  SIM_SOPT1 &= (uint32_t)~(uint32_t)(SIM_SOPT1_OSC32KSEL_MASK); /* System oscillator drives 32 kHz clock for various peripherals */
  /* PORTA_PCR18: ISF=0,MUX=0 */
  PORTA_PCR18 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));                                                   
  /* Switch to FBE Mode */
  /* MCG_C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG_C2 = MCG_C2_RANGE(0x02);                                                   
  /* OSC_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC_CR = OSC_CR_ERCLKEN_MASK;                                                   
  /* SIM_SOPT2: MCGCLKSEL=0 */
  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_MCGCLKSEL_MASK);                                                   
  /* MCG_C1: CLKS=2,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_CLKS(0x02) | MCG_C1_FRDIV(0x05) | MCG_C1_IRCLKEN_MASK);                                                   
  /* MCG_C4: DMX32=0,DRST_DRS=0 */
  MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));                                                   
  /* MCG_C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0x18 */
  MCG_C5 = MCG_C5_PRDIV(0x18);                                                   
  /* MCG_C6: LOLIE=0,PLLS=0,CME=0,VDIV=0 */
  MCG_C6 = 0x00U;                                                   
  while((MCG_S & MCG_S_IREFST_MASK) != 0x00U) { /* Check that the source of the FLL reference clock is the external reference clock. */
  }
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  /* Switch to PBE Mode */
  /* OSC_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC_CR = OSC_CR_ERCLKEN_MASK;                                                   
  /* SIM_SOPT2: MCGCLKSEL=0 */
  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_MCGCLKSEL_MASK);                                                   
  /* MCG_C1: CLKS=2,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_CLKS(0x02) | MCG_C1_FRDIV(0x05) | MCG_C1_IRCLKEN_MASK);                                                   
  /* MCG_C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG_C2 = MCG_C2_RANGE(0x02);                                                   
  /* MCG_C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0x18 */
  MCG_C5 = MCG_C5_PRDIV(0x18);                                                   
  /* MCG_C6: LOLIE=0,PLLS=1,CME=0,VDIV=0 */
  MCG_C6 = MCG_C6_PLLS_MASK;                                                   
  while((MCG_S & 0x0CU) != 0x08U) {    /* Wait until external reference clock is selected as MCG output */
  }
  while((MCG_S & MCG_S_LOCK_MASK) == 0x00U) { /* Wait until locked */
  }
  /* Switch to PEE Mode */
  /* OSC_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC_CR = OSC_CR_ERCLKEN_MASK;                                                   
  /* SIM_SOPT2: MCGCLKSEL=0 */
  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_MCGCLKSEL_MASK);                                                   
  /* MCG_C1: CLKS=0,FRDIV=5,IREFS=0,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (MCG_C1_FRDIV(0x05) | MCG_C1_IRCLKEN_MASK);                                                   
  /* MCG_C2: ??=0,??=0,RANGE=2,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG_C2 = MCG_C2_RANGE(0x02);                                                   
  /* MCG_C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0x18 */
  MCG_C5 = MCG_C5_PRDIV(0x18);                                                   
  /* MCG_C6: LOLIE=0,PLLS=1,CME=0,VDIV=0 */
  MCG_C6 = MCG_C6_PLLS_MASK;                                                   
  while((MCG_S & 0x0CU) != 0x0CU) {    /* Wait until output of the PLL is selected */
  }
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code after PE initialization using property "User code after PE initialization" on the build options tab. !!! ***/

}

/*
** ===================================================================
**     Method      :  Cpu_SetBASEPRI (component MK53N512MD100)
**
**     Description :
**         This method sets the BASEPRI core register.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/*lint -save  -e586 -e950 Disable MISRA rule (2.1,1.1) checking. */
#ifdef _lint
  #define Cpu_SetBASEPRI(Level)  /* empty */
#else
asm void Cpu_SetBASEPRI(register uint32_t Level) {
  MSR BASEPRI,R0;
  MOV PC,LR
}
#endif
/*lint -restore Enable MISRA rule (2.1,1.1) checking. */


/*
** ===================================================================
**     Method      :  PE_low_level_init (component MK53N512MD100)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
      /* Initialization of the SIM module */
  /* PORTA_PCR4: ISF=0,MUX=7 */
  PORTA_PCR4 = (uint32_t)((PORTA_PCR4 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK
               )) | (uint32_t)(
                PORT_PCR_MUX(0x07)
               ));                                                  
  /* SIM_SOPT6: RSTFLTEN=0,RSTFLTSEL=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_SOPT6 = 0x00U;                   /* Set reset pin filter */
  /* SIM_SCGC7: MPU=1 */
  SIM_SCGC7 |= SIM_SCGC7_MPU_MASK;                                                   
        /* Initialization of the MPU module */
  /* MPU_CESR: SPERR=0,VLD=0 */
  MPU_CESR &= (uint32_t)~(uint32_t)((MPU_CESR_SPERR(0x1F) | MPU_CESR_VLD_MASK));                                                   
      /* Initialization of the PMC module */
  /* PMC_LVDSC1: LVDACK=1,LVDIE=0,LVDRE=1,LVDV=0 */
  PMC_LVDSC1 = (uint8_t)((PMC_LVDSC1 & (uint8_t)~(uint8_t)(
                PMC_LVDSC1_LVDIE_MASK |
                PMC_LVDSC1_LVDV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC1_LVDACK_MASK |
                PMC_LVDSC1_LVDRE_MASK
               ));                                                  
  /* PMC_LVDSC2: LVWACK=1,LVWIE=0,LVWV=0 */
  PMC_LVDSC2 = (uint8_t)((PMC_LVDSC2 & (uint8_t)~(uint8_t)(
                PMC_LVDSC2_LVWIE_MASK |
                PMC_LVDSC2_LVWV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC2_LVWACK_MASK
               ));                                                  
  /* PMC_REGSC: TRAMPO=0,??=0,BGBE=0 */
  PMC_REGSC &= (uint8_t)~(uint8_t)(
                PMC_REGSC_TRAMPO_MASK |
                PMC_REGSC_BGBE_MASK |
                0x02U
               );                                                   
  /* MC_PMPROT: ??=0,??=0,AVLP=0,ALLS=0,??=0,AVLLS3=0,AVLLS2=0,AVLLS1=0 */
  MC_PMPROT = 0x00U;                   /* Setup Power mode protection register */
  /* Common initialization of the CPU registers */
  /* NVICIP62: PRI62=0 */
  NVICIP62 = 0x00U;                                                   
  /* NVICIP20: PRI20=0 */
  NVICIP20 = 0x00U;                                                   
  /* PORTC_PCR1: ISF=0,MUX=4 */
  PORTC_PCR1 = (uint32_t)((PORTC_PCR1 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x03)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x04)
  ));                                                  
/* ### USB_HOST_STACK "usb_host" init code ... */
/* Write code here ... */
/* ### USB_AUDIO_CLASS "usb_host_audio" init code ... */
/* Write code here ... */
  /* ### Serial_LDD "UART" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)UART_Init(NULL);
  /* ### TimerUnit_LDD "PIT0" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)PIT0_Init(NULL);
  /* ### Init_FTM "PWM" init code ... */
  PWM_Init();
  /* ### GPIO_LDD "PTC13" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)PTC13_Init(NULL);
  /* ### GPIO_LDD "PTC5" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)PTC5_Init(NULL);
  /* Enable interrupts of the given priority level */
  Cpu_SetBASEPRI(0U);
}

/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
