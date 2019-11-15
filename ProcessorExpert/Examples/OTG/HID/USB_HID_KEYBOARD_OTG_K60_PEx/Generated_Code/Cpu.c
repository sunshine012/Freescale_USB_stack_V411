/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVMD10
**     Component   : MK60N512MD100
**     Version     : Component 01.032, Driver 01.04, CPU db: 3.00.003
**     Datasheet   : K60P144M100SF2RM, Rev. 5, 8 May 2011
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 13:36, # CodeGen: 85
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
#include "AS1.h"
#include "PTE26.h"
#include "usb_hid.h"
#include "usb_otg.h"
#include "USB_LDD.h"
#include "OTG_MAX3353_INT_PIN.h"
#include "OTG_MAX3353.h"
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
**     Method      :  Cpu_SetBASEPRI (component MK60N512MD100)
**
**     Description :
**         This method sets the BASEPRI core register.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cpu_SetBASEPRI(register uint32_t Level);

/*
** ===================================================================
**     Method      :  Cpu_INT_NMIInterrupt (component MK60N512MD100)
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
**     Method      :  Cpu_Cpu_Interrupt (component MK60N512MD100)
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

  /*** ### MK60DN512ZVMD10 "Cpu" init code ... ***/
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
  /* SIM_SCGC5: PORTE=1,PORTD=1,PORTC=1,PORTA=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK |
               SIM_SCGC5_PORTD_MASK |
               SIM_SCGC5_PORTC_MASK |
               SIM_SCGC5_PORTA_MASK;   /* Enable clock gate for ports to enable pin routing */
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
**     Method      :  Cpu_SetBASEPRI (component MK60N512MD100)
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
**     Method      :  PE_low_level_init (component MK60N512MD100)
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
        /* Initialization of the FMC module */
  /* FMC_PFAPR: M5PFD=1,M4PFD=1,M3PFD=1,M2PFD=0,M1PFD=0,M0PFD=0,M5AP=0,M4AP=3,M3AP=0,M2AP=3,M1AP=3,M0AP=3 */
  FMC_PFAPR = (uint32_t)((FMC_PFAPR & (uint32_t)~(uint32_t)(
               FMC_PFAPR_M2PFD_MASK |
               FMC_PFAPR_M1PFD_MASK |
               FMC_PFAPR_M0PFD_MASK |
               FMC_PFAPR_M5AP(0x03) |
               FMC_PFAPR_M3AP(0x03)
              )) | (uint32_t)(
               FMC_PFAPR_M5PFD_MASK |
               FMC_PFAPR_M4PFD_MASK |
               FMC_PFAPR_M3PFD_MASK |
               FMC_PFAPR_M4AP(0x03) |
               FMC_PFAPR_M2AP(0x03) |
               FMC_PFAPR_M1AP(0x03) |
               FMC_PFAPR_M0AP(0x03)
              ));                                                  
  /* FMC_PFB0CR: B0RWSC=3,CLCK_WAY=0,CINV_WAY=0,S_B_INV=0,B0MW=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CRC=0,B0DCE=1,B0ICE=1,B0DPE=1,B0IPE=1,B0SEBE=1 */
  FMC_PFB0CR = FMC_PFB0CR_B0RWSC(0x03) |
               FMC_PFB0CR_B0MW(0x01) |
               FMC_PFB0CR_B0DCE_MASK |
               FMC_PFB0CR_B0ICE_MASK |
               FMC_PFB0CR_B0DPE_MASK |
               FMC_PFB0CR_B0IPE_MASK |
               FMC_PFB0CR_B0SEBE_MASK;                       
  /* FMC_PFB1CR: B1RWSC=3,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,B1MW=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,B1DCE=1,B1ICE=1,B1DPE=1,B1IPE=1,B1SEBE=1 */
  FMC_PFB1CR = FMC_PFB1CR_B1RWSC(0x03) |
               FMC_PFB1CR_B1MW(0x01) |
               FMC_PFB1CR_B1DCE_MASK |
               FMC_PFB1CR_B1ICE_MASK |
               FMC_PFB1CR_B1DPE_MASK |
               FMC_PFB1CR_B1IPE_MASK |
               FMC_PFB1CR_B1SEBE_MASK;                       
  /* SIM_SCGC7: MPU=1 */
  SIM_SCGC7 |= SIM_SCGC7_MPU_MASK;                                                   
        /* Initialization of the MPU module */
  /* MPU_CESR: SPERR=0,VLD=0 */
  MPU_CESR &= (uint32_t)~(uint32_t)((MPU_CESR_SPERR(0x1F) | MPU_CESR_VLD_MASK));                                                   
        /* Initialization of the AXBS module */
  /* AXBS_PRS0: ??=0,??=1,??=1,??=1,??=0,??=1,??=1,??=0,??=0,M5=5,??=0,M4=4,??=0,M3=3,??=0,M2=2,??=0,M1=1,??=0,M0=0 */
  AXBS_PRS0 = AXBS_PRS_M5(0x05) |
              AXBS_PRS_M4(0x04) |
              AXBS_PRS_M3(0x03) |
              AXBS_PRS_M2(0x02) |
              AXBS_PRS_M1(0x01) |
              0x76000000U;                       
  /* AXBS_PRS1: ??=0,??=1,??=1,??=1,??=0,??=1,??=1,??=0,??=0,M5=5,??=0,M4=4,??=0,M3=3,??=0,M2=2,??=0,M1=1,??=0,M0=0 */
  AXBS_PRS1 = AXBS_PRS_M5(0x05) |
              AXBS_PRS_M4(0x04) |
              AXBS_PRS_M3(0x03) |
              AXBS_PRS_M2(0x02) |
              AXBS_PRS_M1(0x01) |
              0x76000000U;                       
  /* AXBS_PRS2: ??=0,??=1,??=1,??=1,??=0,??=1,??=1,??=0,??=0,M5=5,??=0,M4=4,??=0,M3=3,??=0,M2=2,??=0,M1=1,??=0,M0=0 */
  AXBS_PRS2 = AXBS_PRS_M5(0x05) |
              AXBS_PRS_M4(0x04) |
              AXBS_PRS_M3(0x03) |
              AXBS_PRS_M2(0x02) |
              AXBS_PRS_M1(0x01) |
              0x76000000U;                       
  /* AXBS_PRS3: ??=0,??=1,??=1,??=1,??=0,??=1,??=1,??=0,??=0,M5=5,??=0,M4=4,??=0,M3=3,??=0,M2=2,??=0,M1=1,??=0,M0=0 */
  AXBS_PRS3 = AXBS_PRS_M5(0x05) |
              AXBS_PRS_M4(0x04) |
              AXBS_PRS_M3(0x03) |
              AXBS_PRS_M2(0x02) |
              AXBS_PRS_M1(0x01) |
              0x76000000U;                       
  /* AXBS_PRS4: ??=0,??=1,??=1,??=1,??=0,??=1,??=1,??=0,??=0,M5=5,??=0,M4=4,??=0,M3=3,??=0,M2=2,??=0,M1=1,??=0,M0=0 */
  AXBS_PRS4 = AXBS_PRS_M5(0x05) |
              AXBS_PRS_M4(0x04) |
              AXBS_PRS_M3(0x03) |
              AXBS_PRS_M2(0x02) |
              AXBS_PRS_M1(0x01) |
              0x76000000U;                       
  /* AXBS_CRS0: RO=0,HLP=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ARB=0,??=0,??=0,PCTL=0,??=0,PARK=0 */
  AXBS_CRS0 = 0x00U;                                                   
  /* AXBS_CRS1: RO=0,HLP=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ARB=0,??=0,??=0,PCTL=0,??=0,PARK=0 */
  AXBS_CRS1 = 0x00U;                                                   
  /* AXBS_CRS2: RO=0,HLP=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ARB=0,??=0,??=0,PCTL=0,??=0,PARK=0 */
  AXBS_CRS2 = 0x00U;                                                   
  /* AXBS_CRS3: RO=0,HLP=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ARB=0,??=0,??=0,PCTL=0,??=0,PARK=0 */
  AXBS_CRS3 = 0x00U;                                                   
  /* AXBS_CRS4: RO=0,HLP=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ARB=0,??=0,??=0,PCTL=0,??=0,PARK=0 */
  AXBS_CRS4 = 0x00U;                                                   
  /* AXBS_MGPCR0: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,AULB=0 */
  AXBS_MGPCR0 = 0x00U;                                                   
  /* AXBS_MGPCR1: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,AULB=0 */
  AXBS_MGPCR1 = 0x00U;                                                   
  /* AXBS_MGPCR2: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,AULB=0 */
  AXBS_MGPCR2 = 0x00U;                                                   
  /* AXBS_MGPCR3: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,AULB=0 */
  AXBS_MGPCR3 = 0x00U;                                                   
  /* AXBS_MGPCR4: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,AULB=0 */
  AXBS_MGPCR4 = 0x00U;                                                   
  /* AXBS_MGPCR5: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,AULB=0 */
  AXBS_MGPCR5 = 0x00U;                                                   
        /* Initialization of the AIPS0 module */
  /* AIPS0_MPRA: MTR0=1,MTW0=1,MPL0=1,MTR1=1,MTW1=1,MPL1=1,MTR2=1,MTW2=1,MPL2=1,MTR3=0,MTW3=0,MPL3=0,MTR4=1,MTW4=1,MPL4=0,MTR5=0,MTW5=0,MPL5=0 */
  AIPS0_MPRA = (uint32_t)((AIPS0_MPRA & (uint32_t)~(uint32_t)(
                AIPS_MPRA_MTR3_MASK |
                AIPS_MPRA_MTW3_MASK |
                AIPS_MPRA_MPL3_MASK |
                AIPS_MPRA_MPL4_MASK |
                AIPS_MPRA_MTR5_MASK |
                AIPS_MPRA_MTW5_MASK |
                AIPS_MPRA_MPL5_MASK
               )) | (uint32_t)(
                AIPS_MPRA_MTR0_MASK |
                AIPS_MPRA_MTW0_MASK |
                AIPS_MPRA_MPL0_MASK |
                AIPS_MPRA_MTR1_MASK |
                AIPS_MPRA_MTW1_MASK |
                AIPS_MPRA_MPL1_MASK |
                AIPS_MPRA_MTR2_MASK |
                AIPS_MPRA_MTW2_MASK |
                AIPS_MPRA_MPL2_MASK |
                AIPS_MPRA_MTR4_MASK |
                AIPS_MPRA_MTW4_MASK
               ));                                                  
  /* AIPS0_PACRA: SP0=0,WP0=0,TP0=0,SP4=0,WP4=0,TP4=0 */
  AIPS0_PACRA &= (uint32_t)~(uint32_t)(
                  AIPS_PACRA_SP0_MASK |
                  AIPS_PACRA_WP0_MASK |
                  AIPS_PACRA_TP0_MASK |
                  AIPS_PACRA_SP4_MASK |
                  AIPS_PACRA_WP4_MASK |
                  AIPS_PACRA_TP4_MASK
                 );                                                   
  /* AIPS0_PACRB: SP0=0,WP0=0,TP0=0,SP1=0,WP1=0,TP1=0,SP4=0,WP4=0,TP4=0,SP5=0,WP5=0,TP5=0 */
  AIPS0_PACRB &= (uint32_t)~(uint32_t)(
                  AIPS_PACRB_SP0_MASK |
                  AIPS_PACRB_WP0_MASK |
                  AIPS_PACRB_TP0_MASK |
                  AIPS_PACRB_SP1_MASK |
                  AIPS_PACRB_WP1_MASK |
                  AIPS_PACRB_TP1_MASK |
                  AIPS_PACRB_SP4_MASK |
                  AIPS_PACRB_WP4_MASK |
                  AIPS_PACRB_TP4_MASK |
                  AIPS_PACRB_SP5_MASK |
                  AIPS_PACRB_WP5_MASK |
                  AIPS_PACRB_TP5_MASK
                 );                                                   
  /* AIPS0_PACRE: SP0=0,WP0=0,TP0=0,SP1=0,WP1=0,TP1=0,SP4=0,WP4=0,TP4=0 */
  AIPS0_PACRE &= (uint32_t)~(uint32_t)(
                  AIPS_PACRE_SP0_MASK |
                  AIPS_PACRE_WP0_MASK |
                  AIPS_PACRE_TP0_MASK |
                  AIPS_PACRE_SP1_MASK |
                  AIPS_PACRE_WP1_MASK |
                  AIPS_PACRE_TP1_MASK |
                  AIPS_PACRE_SP4_MASK |
                  AIPS_PACRE_WP4_MASK |
                  AIPS_PACRE_TP4_MASK
                 );                                                   
  /* AIPS0_PACRF: SP4=0,WP4=0,TP4=0,SP5=0,WP5=0,TP5=0,SP7=0,WP7=0,TP7=0 */
  AIPS0_PACRF &= (uint32_t)~(uint32_t)(
                  AIPS_PACRF_SP4_MASK |
                  AIPS_PACRF_WP4_MASK |
                  AIPS_PACRF_TP4_MASK |
                  AIPS_PACRF_SP5_MASK |
                  AIPS_PACRF_WP5_MASK |
                  AIPS_PACRF_TP5_MASK |
                  AIPS_PACRF_SP7_MASK |
                  AIPS_PACRF_WP7_MASK |
                  AIPS_PACRF_TP7_MASK
                 );                                                   
  /* AIPS0_PACRG: SP2=0,WP2=0,TP2=0,SP5=0,WP5=0,TP5=0,SP6=0,WP6=0,TP6=0,SP7=0,WP7=0,TP7=0 */
  AIPS0_PACRG &= (uint32_t)~(uint32_t)(
                  AIPS_PACRG_SP2_MASK |
                  AIPS_PACRG_WP2_MASK |
                  AIPS_PACRG_TP2_MASK |
                  AIPS_PACRG_SP5_MASK |
                  AIPS_PACRG_WP5_MASK |
                  AIPS_PACRG_TP5_MASK |
                  AIPS_PACRG_SP6_MASK |
                  AIPS_PACRG_WP6_MASK |
                  AIPS_PACRG_TP6_MASK |
                  AIPS_PACRG_SP7_MASK |
                  AIPS_PACRG_WP7_MASK |
                  AIPS_PACRG_TP7_MASK
                 );                                                   
  /* AIPS0_PACRH: SP0=0,WP0=0,TP0=0,SP1=0,WP1=0,TP1=0,SP3=0,WP3=0,TP3=0,SP5=0,WP5=0,TP5=0,SP6=0,WP6=0,TP6=0 */
  AIPS0_PACRH &= (uint32_t)~(uint32_t)(
                  AIPS_PACRH_SP0_MASK |
                  AIPS_PACRH_WP0_MASK |
                  AIPS_PACRH_TP0_MASK |
                  AIPS_PACRH_SP1_MASK |
                  AIPS_PACRH_WP1_MASK |
                  AIPS_PACRH_TP1_MASK |
                  AIPS_PACRH_SP3_MASK |
                  AIPS_PACRH_WP3_MASK |
                  AIPS_PACRH_TP3_MASK |
                  AIPS_PACRH_SP5_MASK |
                  AIPS_PACRH_WP5_MASK |
                  AIPS_PACRH_TP5_MASK |
                  AIPS_PACRH_SP6_MASK |
                  AIPS_PACRH_WP6_MASK |
                  AIPS_PACRH_TP6_MASK
                 );                                                   
  /* AIPS0_PACRI: SP0=0,WP0=0,TP0=0,SP1=0,WP1=0,TP1=0,SP5=0,WP5=0,TP5=0,SP7=0,WP7=0,TP7=0 */
  AIPS0_PACRI &= (uint32_t)~(uint32_t)(
                  AIPS_PACRI_SP0_MASK |
                  AIPS_PACRI_WP0_MASK |
                  AIPS_PACRI_TP0_MASK |
                  AIPS_PACRI_SP1_MASK |
                  AIPS_PACRI_WP1_MASK |
                  AIPS_PACRI_TP1_MASK |
                  AIPS_PACRI_SP5_MASK |
                  AIPS_PACRI_WP5_MASK |
                  AIPS_PACRI_TP5_MASK |
                  AIPS_PACRI_SP7_MASK |
                  AIPS_PACRI_WP7_MASK |
                  AIPS_PACRI_TP7_MASK
                 );                                                   
  /* AIPS0_PACRJ: SP0=0,WP0=0,TP0=0,SP1=0,WP1=0,TP1=0,SP2=0,WP2=0,TP2=0,SP3=0,WP3=0,TP3=0,SP4=0,WP4=0,TP4=0,SP5=0,WP5=0,TP5=0 */
  AIPS0_PACRJ &= (uint32_t)~(uint32_t)(
                  AIPS_PACRJ_SP0_MASK |
                  AIPS_PACRJ_WP0_MASK |
                  AIPS_PACRJ_TP0_MASK |
                  AIPS_PACRJ_SP1_MASK |
                  AIPS_PACRJ_WP1_MASK |
                  AIPS_PACRJ_TP1_MASK |
                  AIPS_PACRJ_SP2_MASK |
                  AIPS_PACRJ_WP2_MASK |
                  AIPS_PACRJ_TP2_MASK |
                  AIPS_PACRJ_SP3_MASK |
                  AIPS_PACRJ_WP3_MASK |
                  AIPS_PACRJ_TP3_MASK |
                  AIPS_PACRJ_SP4_MASK |
                  AIPS_PACRJ_WP4_MASK |
                  AIPS_PACRJ_TP4_MASK |
                  AIPS_PACRJ_SP5_MASK |
                  AIPS_PACRJ_WP5_MASK |
                  AIPS_PACRJ_TP5_MASK
                 );                                                   
  /* AIPS0_PACRK: SP2=0,WP2=0,TP2=0 */
  AIPS0_PACRK &= (uint32_t)~(uint32_t)(
                  AIPS_PACRK_SP2_MASK |
                  AIPS_PACRK_WP2_MASK |
                  AIPS_PACRK_TP2_MASK
                 );                                                   
  /* AIPS0_PACRM: SP1=0,WP1=0,TP1=0,SP2=0,WP2=0,TP2=0,SP4=0,WP4=0,TP4=0,SP5=0,WP5=0,TP5=0,SP6=0,WP6=0,TP6=0,SP7=0,WP7=0,TP7=0 */
  AIPS0_PACRM &= (uint32_t)~(uint32_t)(
                  AIPS_PACRM_SP1_MASK |
                  AIPS_PACRM_WP1_MASK |
                  AIPS_PACRM_TP1_MASK |
                  AIPS_PACRM_SP2_MASK |
                  AIPS_PACRM_WP2_MASK |
                  AIPS_PACRM_TP2_MASK |
                  AIPS_PACRM_SP4_MASK |
                  AIPS_PACRM_WP4_MASK |
                  AIPS_PACRM_TP4_MASK |
                  AIPS_PACRM_SP5_MASK |
                  AIPS_PACRM_WP5_MASK |
                  AIPS_PACRM_TP5_MASK |
                  AIPS_PACRM_SP6_MASK |
                  AIPS_PACRM_WP6_MASK |
                  AIPS_PACRM_TP6_MASK |
                  AIPS_PACRM_SP7_MASK |
                  AIPS_PACRM_WP7_MASK |
                  AIPS_PACRM_TP7_MASK
                 );                                                   
  /* AIPS0_PACRN: SP2=0,WP2=0,TP2=0,SP3=0,WP3=0,TP3=0,SP4=0,WP4=0,TP4=0,SP5=0,WP5=0,TP5=0 */
  AIPS0_PACRN &= (uint32_t)~(uint32_t)(
                  AIPS_PACRN_SP2_MASK |
                  AIPS_PACRN_WP2_MASK |
                  AIPS_PACRN_TP2_MASK |
                  AIPS_PACRN_SP3_MASK |
                  AIPS_PACRN_WP3_MASK |
                  AIPS_PACRN_TP3_MASK |
                  AIPS_PACRN_SP4_MASK |
                  AIPS_PACRN_WP4_MASK |
                  AIPS_PACRN_TP4_MASK |
                  AIPS_PACRN_SP5_MASK |
                  AIPS_PACRN_WP5_MASK |
                  AIPS_PACRN_TP5_MASK
                 );                                                   
  /* AIPS0_PACRO: SP2=0,WP2=0,TP2=0,SP3=0,WP3=0,TP3=0,SP4=0,WP4=0,TP4=0 */
  AIPS0_PACRO &= (uint32_t)~(uint32_t)(
                  AIPS_PACRO_SP2_MASK |
                  AIPS_PACRO_WP2_MASK |
                  AIPS_PACRO_TP2_MASK |
                  AIPS_PACRO_SP3_MASK |
                  AIPS_PACRO_WP3_MASK |
                  AIPS_PACRO_TP3_MASK |
                  AIPS_PACRO_SP4_MASK |
                  AIPS_PACRO_WP4_MASK |
                  AIPS_PACRO_TP4_MASK
                 );                                                   
  /* AIPS0_PACRP: SP4=0,WP4=0,TP4=0,SP5=0,WP5=0,TP5=0,SP6=0,WP6=0,TP6=0 */
  AIPS0_PACRP &= (uint32_t)~(uint32_t)(
                  AIPS_PACRP_SP4_MASK |
                  AIPS_PACRP_WP4_MASK |
                  AIPS_PACRP_TP4_MASK |
                  AIPS_PACRP_SP5_MASK |
                  AIPS_PACRP_WP5_MASK |
                  AIPS_PACRP_TP5_MASK |
                  AIPS_PACRP_SP6_MASK |
                  AIPS_PACRP_WP6_MASK |
                  AIPS_PACRP_TP6_MASK
                 );                                                   
        /* Initialization of the AIPS1 module */
  /* AIPS1_MPRA: MTR0=1,MTW0=1,MPL0=1,MTR1=1,MTW1=1,MPL1=1,MTR2=1,MTW2=1,MPL2=1,MTR3=0,MTW3=0,MPL3=0,MTR4=1,MTW4=1,MPL4=0,MTR5=0,MTW5=0,MPL5=0 */
  AIPS1_MPRA = (uint32_t)((AIPS1_MPRA & (uint32_t)~(uint32_t)(
                AIPS_MPRA_MTR3_MASK |
                AIPS_MPRA_MTW3_MASK |
                AIPS_MPRA_MPL3_MASK |
                AIPS_MPRA_MPL4_MASK |
                AIPS_MPRA_MTR5_MASK |
                AIPS_MPRA_MTW5_MASK |
                AIPS_MPRA_MPL5_MASK
               )) | (uint32_t)(
                AIPS_MPRA_MTR0_MASK |
                AIPS_MPRA_MTW0_MASK |
                AIPS_MPRA_MPL0_MASK |
                AIPS_MPRA_MTR1_MASK |
                AIPS_MPRA_MTW1_MASK |
                AIPS_MPRA_MPL1_MASK |
                AIPS_MPRA_MTR2_MASK |
                AIPS_MPRA_MTW2_MASK |
                AIPS_MPRA_MPL2_MASK |
                AIPS_MPRA_MTR4_MASK |
                AIPS_MPRA_MTW4_MASK
               ));                                                  
  /* AIPS1_PACRE: SP0=0,WP0=0,TP0=0,SP4=0,WP4=0,TP4=0 */
  AIPS1_PACRE &= (uint32_t)~(uint32_t)(
                  AIPS_PACRE_SP0_MASK |
                  AIPS_PACRE_WP0_MASK |
                  AIPS_PACRE_TP0_MASK |
                  AIPS_PACRE_SP4_MASK |
                  AIPS_PACRE_WP4_MASK |
                  AIPS_PACRE_TP4_MASK
                 );                                                   
  /* AIPS1_PACRF: SP4=0,WP4=0,TP4=0 */
  AIPS1_PACRF &= (uint32_t)~(uint32_t)(
                  AIPS_PACRF_SP4_MASK |
                  AIPS_PACRF_WP4_MASK |
                  AIPS_PACRF_TP4_MASK
                 );                                                   
  /* AIPS1_PACRG: SP1=0,WP1=0,TP1=0 */
  AIPS1_PACRG &= (uint32_t)~(uint32_t)(
                  AIPS_PACRG_SP1_MASK |
                  AIPS_PACRG_WP1_MASK |
                  AIPS_PACRG_TP1_MASK
                 );                                                   
  /* AIPS1_PACRH: SP0=0,WP0=0,TP0=0,SP3=0,WP3=0,TP3=0 */
  AIPS1_PACRH &= (uint32_t)~(uint32_t)(
                  AIPS_PACRH_SP0_MASK |
                  AIPS_PACRH_WP0_MASK |
                  AIPS_PACRH_TP0_MASK |
                  AIPS_PACRH_SP3_MASK |
                  AIPS_PACRH_WP3_MASK |
                  AIPS_PACRH_TP3_MASK
                 );                                                   
  /* AIPS1_PACRI: SP0=0,WP0=0,TP0=0 */
  AIPS1_PACRI &= (uint32_t)~(uint32_t)(
                  AIPS_PACRI_SP0_MASK |
                  AIPS_PACRI_WP0_MASK |
                  AIPS_PACRI_TP0_MASK
                 );                                                   
  /* AIPS1_PACRJ: SP4=0,WP4=0,TP4=0,SP5=0,WP5=0,TP5=0 */
  AIPS1_PACRJ &= (uint32_t)~(uint32_t)(
                  AIPS_PACRJ_SP4_MASK |
                  AIPS_PACRJ_WP4_MASK |
                  AIPS_PACRJ_TP4_MASK |
                  AIPS_PACRJ_SP5_MASK |
                  AIPS_PACRJ_WP5_MASK |
                  AIPS_PACRJ_TP5_MASK
                 );                                                   
  /* AIPS1_PACRN: SP2=0,WP2=0,TP2=0,SP3=0,WP3=0,TP3=0 */
  AIPS1_PACRN &= (uint32_t)~(uint32_t)(
                  AIPS_PACRN_SP2_MASK |
                  AIPS_PACRN_WP2_MASK |
                  AIPS_PACRN_TP2_MASK |
                  AIPS_PACRN_SP3_MASK |
                  AIPS_PACRN_WP3_MASK |
                  AIPS_PACRN_TP3_MASK
                 );                                                   
  /* AIPS1_PACRP: SP6=0,WP6=0,TP6=0 */
  AIPS1_PACRP &= (uint32_t)~(uint32_t)(
                  AIPS_PACRP_SP6_MASK |
                  AIPS_PACRP_WP6_MASK |
                  AIPS_PACRP_TP6_MASK
                 );                                                   
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
  /* NVICIP20: PRI20=0 */
  NVICIP20 = 0x00U;                                                   
  /* NVICISER0: SETENA|=0x00100000 */
  NVICISER0 |= NVIC_ISER_SETENA(0x00100000);                                                   
  /* ### GPIO_LDD "PTE26" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)PTE26_Init(NULL);
/* ### USB_OTG_STACK "usb_otg" init code ... */
/* Write code here ... */
  /* ### USB_HID_CLASS "usb_hid" init code ... */
  /* Write code here ... */
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
