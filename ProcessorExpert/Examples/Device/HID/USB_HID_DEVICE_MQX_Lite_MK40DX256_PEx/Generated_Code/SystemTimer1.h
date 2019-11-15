/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SystemTimer1.h
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-20, 22:25, # CodeGen: 1
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : SystemTimer1
**          Module name                                    : SysTick
**          Counter                                        : SYST_CVR
**          Counter direction                              : Down
**          Counter width                                  : 24 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : Auto select
**          Counter restart                                : On-match
**            Period device                                : SYST_RVR
**            Period                                       : 5 ms
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_SysTick
**              Interrupt priority                         : medium priority
**          Channel list                                   : 0
**          Initialization                                 : 
**            Enabled in init. code                        : no
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
**            Clock configuration 1                        : This component enabled
**            Clock configuration 2                        : This component enabled
**            Clock configuration 3                        : This component enabled
**            Clock configuration 4                        : This component enabled
**            Clock configuration 5                        : This component enabled
**            Clock configuration 6                        : This component enabled
**            Clock configuration 7                        : This component enabled
**     Contents    :
**         Init              - LDD_TDeviceData* SystemTimer1_Init(LDD_TUserData *UserDataPtr);
**         Deinit            - void SystemTimer1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable            - LDD_TError SystemTimer1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         GetInputFrequency - uint32_t SystemTimer1_GetInputFrequency(LDD_TDeviceData *DeviceDataPtr);
**         SetPeriodTicks    - LDD_TError SystemTimer1_SetPeriodTicks(LDD_TDeviceData *DeviceDataPtr,...
**         GetPeriodTicks    - LDD_TError SystemTimer1_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr,...
**         ResetCounter      - LDD_TError SystemTimer1_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
**         GetCounterValue   - SystemTimer1_TValueType SystemTimer1_GetCounterValue(LDD_TDeviceData...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __SystemTimer1_H
#define __SystemTimer1_H

/* MODULE SystemTimer1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "SysTick_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_SystemTimer1_TValueType
#define __BWUserType_SystemTimer1_TValueType
  typedef uint32_t SystemTimer1_TValueType ; /* Type for data parameters of methods */
#endif
#define SystemTimer1_CNT_INP_FREQ_U_0 0x02DC6C00UL /* Counter input frequency in Hz */
#define SystemTimer1_CNT_INP_FREQ_R_0 48000768.0122882F /* Counter input frequency in Hz */
#define SystemTimer1_CNT_INP_FREQ_COUNT 0U /* Count of predefined counter input frequencies */
#define SystemTimer1_PERIOD_TICKS 0x0003A980UL /* Initialization value of period in 'counter ticks' */
#define SystemTimer1_NUMBER_OF_CHANNELS 0x00U /* Count of predefined channels */
#define SystemTimer1_COUNTER_WIDTH 0x18U /* Counter width in bits  */
#define SystemTimer1_COUNTER_DIR DIR_DOWN /* Direction of counting */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define SystemTimer1_PRPH_BASE_ADDRESS  0xE000E010U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define SystemTimer1_Init_METHOD_ENABLED
#define SystemTimer1_Deinit_METHOD_ENABLED
#define SystemTimer1_Enable_METHOD_ENABLED
#define SystemTimer1_GetInputFrequency_METHOD_ENABLED
#define SystemTimer1_SetPeriodTicks_METHOD_ENABLED
#define SystemTimer1_GetPeriodTicks_METHOD_ENABLED
#define SystemTimer1_ResetCounter_METHOD_ENABLED
#define SystemTimer1_GetCounterValue_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define SystemTimer1_OnCounterRestart_EVENT_ENABLED



LDD_TDeviceData* SystemTimer1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  SystemTimer1_Init (component TimerUnit_LDD)
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

void SystemTimer1_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SystemTimer1_Deinit (component TimerUnit_LDD)
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

LDD_TError SystemTimer1_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SystemTimer1_Enable (component TimerUnit_LDD)
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

uint32_t SystemTimer1_GetInputFrequency(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SystemTimer1_GetInputFrequency (component TimerUnit_LDD)
**
**     Description :
**         Returns current input frequency of the counter in Hz as
**         32-bit unsigned integer number. This method can be used only
**         if <"Input clock source"> property is set to "internal".
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Input frequency
** ===================================================================
*/

LDD_TError SystemTimer1_SetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, SystemTimer1_TValueType Ticks);
/*
** ===================================================================
**     Method      :  SystemTimer1_SetPeriodTicks (component TimerUnit_LDD)
**
**     Description :
**         The method sets timer re-initialization period (in timer
**         ticks). This method is available only if the property
**         <"Counter restart"> is switched to 'on-match' value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Ticks           - Number of counter ticks before counter
**                           re-initialization. Value 0 means maximal
**                           period value the same as "free-running
**                           mode", e.g. counter overflow or underflow
**                           without any explicit re-initialization.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_TICKS - Ticks parameter is out of
**                           possible range.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError SystemTimer1_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, SystemTimer1_TValueType *TicksPtr);
/*
** ===================================================================
**     Method      :  SystemTimer1_GetPeriodTicks (component TimerUnit_LDD)
**
**     Description :
**         Returns the number of counter ticks before re-initialization.
**         See also method <SetPeriodTicks>. This method is available
**         only if the property <"Counter restart"> is switched to
**         'on-match' value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * TicksPtr        - Pointer to return value of the
**                           number of counter ticks before
**                           re-initialization
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError SystemTimer1_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SystemTimer1_ResetCounter (component TimerUnit_LDD)
**
**     Description :
**         Resets counter. If counter is counting up then it is set to
**         zero. If counter is counting down then counter is updated to
**         the reload value.
**         The method is not available if HW doesn't allow resetting of
**         the counter.
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

SystemTimer1_TValueType SystemTimer1_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SystemTimer1_GetCounterValue (component TimerUnit_LDD)
**
**     Description :
**         Returns the content of counter register. This method can be
**         used both if counter is enabled and if counter is disabled.
**         The method is not available if HW doesn't allow reading of
**         the counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Counter value (number of counted ticks).
** ===================================================================
*/

/* {MQXLite RTOS Adapter} ISR function prototype */
void SystemTimer1_Interrupt(LDD_RTOS_TISRParameter _isrParameter);
/*
** ===================================================================
**     Method      :  SystemTimer1_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END SystemTimer1. */

#endif
/* ifndef __SystemTimer1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
