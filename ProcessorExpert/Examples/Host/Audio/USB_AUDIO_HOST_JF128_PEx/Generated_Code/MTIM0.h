/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MTIM0.h
**     Project     : ProcessorExpert
**     Processor   : MCF51JF128VLH
**     Component   : TimerUnit_LDD
**     Version     : Component 01.134, Driver 01.03, CPU db: 3.00.000
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2012-11-20, 11:36, # CodeGen: 101
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : MTIM0
**          Module name                                    : MTIM0
**          Counter                                        : MTIM0_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : 2.998272 MHz
**          Counter restart                                : On-match
**            Period device                                : MTIM0_MOD
**            Period                                       : 125 �s
**            Interrupt                                    : Enabled
**              Interrupt                                  : Vmtim0
**              Interrupt priority                         : medium priority
**          Channel list                                   : 0
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
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
**     Contents    :
**         Init           - LDD_TDeviceData* MTIM0_Init(LDD_TUserData *UserDataPtr);
**         Deinit         - void MTIM0_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable         - LDD_TError MTIM0_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable        - LDD_TError MTIM0_Disable(LDD_TDeviceData *DeviceDataPtr);
**         GetDriverState - LDD_TDriverState MTIM0_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __MTIM0_H
#define __MTIM0_H

/* MODULE MTIM0. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "MTIM_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_MTIM0_TValueType
#define __BWUserType_MTIM0_TValueType
  typedef uint32_t MTIM0_TValueType ;  /* Type for data parameters of methods */
#endif
#define MTIM0_CNT_INP_FREQ_U_0 0x002DC000UL /* Counter input frequency in Hz */
#define MTIM0_CNT_INP_FREQ_R_0 2998275.991305F /* Counter input frequency in Hz */
#define MTIM0_CNT_INP_FREQ_COUNT 0U    /* Count of predefined counter input frequencies */
#define MTIM0_PERIOD_TICKS 0x0177UL    /* Initialization value of period in 'counter ticks' */
#define MTIM0_NUMBER_OF_CHANNELS 0x00U /* Count of predefined channels */
#define MTIM0_COUNTER_WIDTH 0x10U      /* Counter width in bits  */
#define MTIM0_COUNTER_DIR  DIR_UP      /* Direction of counting */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define MTIM0_PRPH_BASE_ADDRESS  0xFFFF8410U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define MTIM0_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_MTIM0_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define MTIM0_Init_METHOD_ENABLED
#define MTIM0_Deinit_METHOD_ENABLED
#define MTIM0_Enable_METHOD_ENABLED
#define MTIM0_Disable_METHOD_ENABLED
#define MTIM0_GetDriverState_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define MTIM0_OnCounterRestart_EVENT_ENABLED



LDD_TDeviceData* MTIM0_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  MTIM0_Init (component TimerUnit_LDD)
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

void MTIM0_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  MTIM0_Deinit (component TimerUnit_LDD)
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

LDD_TError MTIM0_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  MTIM0_Enable (component TimerUnit_LDD)
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

LDD_TError MTIM0_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  MTIM0_Disable (component TimerUnit_LDD)
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

LDD_TDriverState MTIM0_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  MTIM0_GetDriverState (component TimerUnit_LDD)
**
**     Description :
**         This method returns the current driver status.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - The current driver status mask.
**                           Following status masks defined in PE_LDD.h
**                           can be used to check the current driver
**                           status.
**                           PE_LDD_DRIVER_DISABLED_IN_CLOCK_CONFIGURATION - 1 -
**                           Driver is disabled in the current mode; 0 -
**                           Driver is enabled in the current mode.  
**                           PE_LDD_DRIVER_DISABLED_BY_USER - 1 - Driver
**                           is disabled by the user; 0 - Driver is
**                           enabled by the user.        
**                           PE_LDD_DRIVER_BUSY - 1 - Driver is the BUSY
**                           state; 0 - Driver is in the IDLE state.
** ===================================================================
*/

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(MTIM0_Interrupt);
/*
** ===================================================================
**     Method      :  MTIM0_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END MTIM0. */

#endif
/* ifndef __MTIM0_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.02]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/