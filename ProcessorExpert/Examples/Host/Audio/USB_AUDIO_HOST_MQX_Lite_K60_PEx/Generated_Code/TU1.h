/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TU1.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-18, 16:00, # CodeGen: 38
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU1
**          Module name                                    : PIT
**          Counter                                        : PIT_CVAL0
**          Counter direction                              : Down
**          Counter width                                  : 32 bits
**          Value type                                     : uint32_t
**          Input clock source                             : Internal
**            Counter frequency                            : 48 MHz
**          Counter restart                                : On-match
**            Period device                                : PIT_LDVAL0
**            Period                                       : 125 �s
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_PIT0
**              Interrupt priority                         : medium priority
**          Channel list                                   : 0
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Enabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component enabled
**            Clock configuration 4                        : This component enabled
**            Clock configuration 5                        : This component enabled
**            Clock configuration 6                        : This component enabled
**            Clock configuration 7                        : This component enabled
**     Contents    :
**         Init    - LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr);
**         Deinit  - void TU1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable  - LDD_TError TU1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - LDD_TError TU1_Disable(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TU1_H
#define __TU1_H

/* MODULE TU1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "PIT_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_TU1_TValueType
#define __BWUserType_TU1_TValueType
  typedef uint32_t TU1_TValueType ;    /* Type for data parameters of methods */
#endif
#define TU1_CNT_INP_FREQ_U_0 0x02DC6C00UL /* Counter input frequency in Hz */
#define TU1_CNT_INP_FREQ_R_0 48000768.0122882F /* Counter input frequency in Hz */
#define TU1_CNT_INP_FREQ_COUNT 0U      /* Count of predefined counter input frequencies */
#define TU1_PERIOD_TICKS   0x1770UL    /* Initialization value of period in 'counter ticks' */
#define TU1_NUMBER_OF_CHANNELS 0x00U   /* Count of predefined channels */
#define TU1_COUNTER_WIDTH  0x20U       /* Counter width in bits  */
#define TU1_COUNTER_DIR    DIR_DOWN    /* Direction of counting */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TU1_PRPH_BASE_ADDRESS  0x40037000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define TU1_Init_METHOD_ENABLED
#define TU1_Deinit_METHOD_ENABLED
#define TU1_Enable_METHOD_ENABLED
#define TU1_Disable_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define TU1_OnCounterRestart_EVENT_ENABLED



LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  TU1_Init (component TimerUnit_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void TU1_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU1_Deinit (component TimerUnit_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError TU1_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU1_Enable (component TimerUnit_LDD)
**
**     Description :
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask). The method is
**         not available if the counter can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError TU1_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU1_Disable (component TimerUnit_LDD)
**
**     Description :
**         Disables the component - it stops signal generation and
**         events calling. The method is not available if the counter
**         can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

/* {MQXLite RTOS Adapter} ISR function prototype */
void TU1_Interrupt(LDD_RTOS_TISRParameter _isrParameter);
/*
** ===================================================================
**     Method      :  TU1_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END TU1. */

#endif
/* ifndef __TU1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/