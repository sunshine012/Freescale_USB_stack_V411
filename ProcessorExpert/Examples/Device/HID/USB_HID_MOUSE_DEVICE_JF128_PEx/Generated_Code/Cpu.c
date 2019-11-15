/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JF128VLH
**     Component   : MCF51JF128_64
**     Version     : Component 01.004, Driver 01.02, CPU db: 3.00.000
**     Datasheet   : MCF51JF128RM Rev. 3, 5/2011
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2012-11-19, 11:05, # CodeGen: 12
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
#include "usb_hid.h"
#include "usb_device.h"
#include "USB_LDD.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"

/* Global variables */
volatile uint16_t SR_reg;              /* Current value of the FAULTMASK register */
volatile uint8_t SR_lock = 0x00U;      /* Lock */

/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component MCF51JF128_64)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU bean property "Build Options / Unhandled int code" */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm (HALT);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

/*
** ===================================================================
**     Method      :  __initialize_hardware (component MCF51JF128_64)
**
**     Description :
**         Initializes the whole system like timing, external bus, etc.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab. !!! ***/

extern uint32_t ___VECTOR_RAM[];

/*lint -esym(765,__initialize_hardware) Disable MISRA rule (8.10) checking for symbols (__initialize_hardware). The function is linked to the EWL library */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cpu_Interrupt). */
void __initialize_hardware(void)
{

  /*** !!! Here you can place your own code before PE initialization using property "User code before PE initialization" on the build options tab. !!! ***/

  /*** ### MCF51JF128VLH "Cpu" init code ... ***/
  /*** PE initialization code after reset ***/
  /* Disable the WDOG module */
  /* SIM_COPC: ??=0,??=0,??=0,??=0,COPT=0,COPCLKS=0,COPW=0 */
  SIM_COPC = (uint8_t)0x00U;                          
  /* System clock initialization */
  if ( *((uint8_t*) 0x03FFU) != 0xFFU) {
    MCG_C3 = *((uint8_t*) 0x03FFU);
    MCG_C4 = (MCG_C4 & 0xFEU) | ((*((uint8_t*) 0x03FEU)) & 0x01U);
  }
  /* Enable Drive Strength for BDM pin to ensure correct communication with high bus clock frequencies */
  /* SIM_SCGC6: PORTB=1 */
  SIM_SCGC6 |= (uint8_t)0x02U;                            
  /* PCTLB_DS: PTDS|=0x10 */
  PCTLB_DS |= (uint8_t)0x10U;                            
  /* SIM_CLKDIV0: ??=0,??=0,??=0,??=0,OUTDIV=0 */
  SIM_CLKDIV0 = (uint8_t)0x00U;        /* Update system prescaler */
  /* SIM_CLKDIV1: USBDIV=0,USBFRAC=0,??=0,??=0,USBSRC=1 */
  SIM_CLKDIV1 = (uint8_t)0x01U;        /* Update USB clock prescalers */
  /* SIM_SCGC5: MCG=1 */
  SIM_SCGC5 |= (uint8_t)0x01U;                            
  /* Switch to FEI Mode */
  /* MCG_C1: CLKS=0,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = (uint8_t)0x06U;                          
  /* MCG_C2: ??=0,??=0,RANGE=0,HGO=0,EREFS=0,LP=0,IRCS=0 */
  MCG_C2 = (uint8_t)0x00U;                          
  /* MCG_C4: DMX32=1,DRST_DRS=1 */
  MCG_C4 = (uint8_t)((MCG_C4 & (uint8_t)~(uint8_t)0x40U) | (uint8_t)0xA0U);
  /* OSC2_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC2_CR = (uint8_t)0x80U;                          
  /* MCG_C5: ??=0,PLLCLKEN=0,PLLSTEN=0,PRDIV=0 */
  MCG_C5 = (uint8_t)0x00U;                          
  /* MCG_C6: LOLIE=0,PLLS=0,CME=0,VDIV=0 */
  MCG_C6 = (uint8_t)0x00U;                          
  while((MCG_S & MCG_S_IREFST_MASK) == 0x00U) { /* Check that the source of the FLL reference clock is the internal reference clock. */
  }
  while((MCG_S & 0x0CU) != 0x00U) {    /* Wait until output of the FLL is selected */
  }
  /* SIM_SCGC6: PORTC=1,PORTB=1 */
  SIM_SCGC6 |= (uint8_t)0x06U;         /* Enable clock gate for ports to enable pin routing */
  /* Initialization of CPU registers */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm {
    /* CPUCR: ARD=0,IRD=0,IAE=0,IME=0,BWD=0,HAE=1,FSD=0,CBRR=0,FHP=0,FCDIS=0,FDCEN=0,FICDIS=0,FCCLR=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    move #0x04000000, d0
    movec d0,CPUCR
  };
  /*lint -restore Enable MISRA rule (1.1) checking. */
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code after PE initialization using property "User code after PE initialization" on the build options tab. !!! ***/

}



/*
** ===================================================================
**     Method      :  PE_low_level_init (component MCF51JF128_64)
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
      /* Initialization of the SIM module */
  /* SIM_CLKOUT: CS=0 */
  SIM_CLKOUT &= (uint8_t)~(uint8_t)0x70U;                           
        /* Initialization of the RCM module */
  /* RCM_RPFW: RSTFLTSEL=0 */
  RCM_RPFW &= (uint8_t)~(uint8_t)0x1FU;                           
  /* RCM_RPFC: RSTFLTSS=0,RSTFLTSRW=0 */
  RCM_RPFC &= (uint8_t)~(uint8_t)0x07U;                           
      /* Initialization of the PMC module */
  /* PMC_LVDSC1: LVDACK=1,LVDIE=0,LVDRE=1,LVDV=0 */
  PMC_LVDSC1 = (uint8_t)((PMC_LVDSC1 & (uint8_t)~(uint8_t)0x23U) | (uint8_t)0x50U);
  /* PMC_LVDSC2: LVWACK=1,LVWIE=0,LVWV=0 */
  PMC_LVDSC2 = (uint8_t)((PMC_LVDSC2 & (uint8_t)~(uint8_t)0x23U) | (uint8_t)0x40U);
  /* PMC_REGSC: BGEN=0,ACKISO=0,BGBE=0 */
  PMC_REGSC &= (uint8_t)~(uint8_t)0x19U;                           
  /* SMC_PMPROT: ??=0,??=0,AVLP=0,??=0,ALLS=0,??=0,AVLLS=0,??=0 */
  SMC_PMPROT = (uint8_t)0x00U;         /* Setup Power mode protection register */
  /* INTC_WCR: ENB=1,??=0,??=0,??=0,??=0,MASK=0 */
  INTC_WCR = (uint8_t)0x80U;                          
  /* Common initialization of the CPU registers */
  /* MXC_PTBPF2: B4=2 */
  MXC_PTBPF2 = (uint8_t)((MXC_PTBPF2 & (uint8_t)~(uint8_t)0x0DU) | (uint8_t)0x02U);
  /* MXC_PTCPF4: C1=2 */
  MXC_PTCPF4 = (uint8_t)((MXC_PTCPF4 & (uint8_t)~(uint8_t)0xD0U) | (uint8_t)0x20U);
  /* INTC_IMRL: IMR1=0 */
  INTC_IMRL &= (uint32_t)~0x02UL;                      
  /* ### USB_DEVICE_STACK "usb_device" init code ... */
  /* Write code here ... */
  /* ### USB_HID_CLASS "usb_hid" init code ... */
  /* Write code here ... */

  /* Enable interrupts of the given priority level */
  /* Set initial interrupt priority 0 */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm {
    move.w SR,D0;
    andi.l #0xF8FF,D0;
    move.w D0,SR;
  }
  /*lint -restore Enable MISRA rule (1.1) checking. */
}
/* Initialization of the CPU registers in FLASH */

/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
