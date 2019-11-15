/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TimerIntLdd1.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Component   : TimerInt_LDD
**     Version     : Component 01.012, Driver 01.00, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-18, 16:00, # CodeGen: 38
**     Abstract    :
**          This TimerInt component implements a periodic interrupt.
**          When the component and its events are enabled, the "OnInterrupt"
**          event is called periodically with the period that you specify.
**          TimerInt supports also changing the period in runtime.
**          This TimerInt component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : TimerIntLdd1
**          Periodic interrupt source                      : PIT_LDVAL0
**          Counter                                        : PIT_CVAL0
**          Linked TimerUnit                               : TU1
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PIT0
**            Interrupt priority                           : medium priority
**          Interrupt period                               : 125 �s
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnInterrupt                                : Enabled
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
**         Init    - LDD_TDeviceData* TimerIntLdd1_Init(LDD_TUserData *UserDataPtr);
**         Deinit  - void TimerIntLdd1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable  - LDD_TError TimerIntLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - LDD_TError TimerIntLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TimerIntLdd1_H
#define __TimerIntLdd1_H

/* MODULE TimerIntLdd1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "TU1.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TimerIntLdd1_PRPH_BASE_ADDRESS  0x40037000U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define TimerIntLdd1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_TimerIntLdd1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define TimerIntLdd1_Init_METHOD_ENABLED
#define TimerIntLdd1_Deinit_METHOD_ENABLED
#define TimerIntLdd1_Enable_METHOD_ENABLED
#define TimerIntLdd1_Disable_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define TimerIntLdd1_OnInterrupt_EVENT_ENABLED



LDD_TDeviceData* TimerIntLdd1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  TimerIntLdd1_Init (component TimerInt_LDD)
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

void TimerIntLdd1_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TimerIntLdd1_Deinit (component TimerInt_LDD)
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

LDD_TError TimerIntLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TimerIntLdd1_Enable (component TimerInt_LDD)
**
**     Description :
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask).
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

LDD_TError TimerIntLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TimerIntLdd1_Disable (component TimerInt_LDD)
**
**     Description :
**         Disables the component - it stops signal generation and
**         events calling.
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

void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  TU1_OnCounterRestart (component TimerInt_LDD)
**
**     Description :
**         The method services the event of the linked component TU1 and 
**         eventually invokes event TimerIntLdd1_OnInterrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END TimerIntLdd1. */

#endif
/* ifndef __TimerIntLdd1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
