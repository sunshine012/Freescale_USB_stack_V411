/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWM.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Init_TPM
**     Version     : Component 01.000, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-11-19, 14:42, # CodeGen: 23
**     Abstract    :
**          This file implements the TPM (TPM0) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PWM
**          Device                                         : TPM0
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Clock settings                               : 
**              Clock source                               : Counter clock
**              Prescaler                                  : divide by 1
**              Modulo counter                             : 255
**              Period                                     : (1 * 256) / External Clock Source
**            BDM mode                                     : TPM counter stopped; output pins remain the same
**            Global time base                             : Disabled
**            Counter reload on trigger                    : Disabled
**            Counter start on trigger                     : Disabled
**            Counter stop on overflow                     : Disabled
**          Channels                                       : 
**            Channel 0                                    : Enabled
**              Channel mode                               : Edge-aligned PWM
**                PWM polarity                             : High-true
**                Channel value register                   : 0
**              Pin                                        : Enabled
**                Pin                                      : PTE24/TPM0_CH0/I2C0_SCL
**                Pin signal                               : 
**              Interrupt/DMA                              : 
**                Interrupt                                : INT_TPM0
**                Channel interrupt                        : Disabled
**                DMA request                              : Disabled
**            Channel 1                                    : Disabled
**            Channel 2                                    : Disabled
**            Channel 3                                    : Disabled
**            Channel 4                                    : Disabled
**            Channel 5                                    : Disabled
**          Pins                                           : 
**            External clock pin                           : Disabled
**            HW Synchronization trigger                   : Disabled
**          Interrupts                                     : 
**            Channels / Timer overflow / Fault            : 
**              Interrupt                                  : INT_TPM0
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**              Channels interrupt/DMA                     : See the respective Channel settings
**              Timer overflow interrupt                   : Disabled
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void PWM_Init(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef PWM_H_
#define PWM_H_

/* MODULE PWM. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


void PWM_Init(void);
/*
** ===================================================================
**     Method      :  PWM_Init (component Init_TPM)
**
**     Description :
**         This method initializes registers of the TPM module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


/* END PWM. */
#endif /* #ifndef __PWM_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/