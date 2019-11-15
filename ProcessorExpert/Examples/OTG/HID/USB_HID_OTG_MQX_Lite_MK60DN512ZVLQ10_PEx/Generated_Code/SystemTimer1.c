/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SystemTimer1.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-16, 09:27, # CodeGen: 67
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

/* MODULE SystemTimer1. */

#include "MQX1.h"
#include "SystemTimer1.h"
/* MQX Lite include files */
#include "mqxlite.h"
#include "mqxlite_prv.h"
#include "IO_Map.h"


typedef struct {
  LDD_RTOS_TISRVectorSettings SavedISRSettings_TUInterrupt; /* {MQXLite RTOS Adapter} Saved settings of allocated interrupt vector */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} SystemTimer1_TDeviceData;

typedef SystemTimer1_TDeviceData *SystemTimer1_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {MQXLite RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static SystemTimer1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERUNIT_ON_COUNTER_RESTART)

/* Internal method prototypes */
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
LDD_TDeviceData* SystemTimer1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  SystemTimer1_TDeviceData *DeviceDataPrv;
  /* {MQXLite RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {MQXLite RTOS Adapter} Save old and set new interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not saved, because it is not modified */
  DeviceDataPrv->SavedISRSettings_TUInterrupt.isrData = _int_get_isr_data(LDD_ivIndex_INT_SysTick);
  DeviceDataPrv->SavedISRSettings_TUInterrupt.isrFunction = _int_install_isr(LDD_ivIndex_INT_SysTick, SystemTimer1_Interrupt, DeviceDataPrv);
  /* SYST_CSR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNTFLAG=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CLKSOURCE=0,TICKINT=0,ENABLE=0 */
  SYST_CSR = 0x00U;                    /* Clear control register */
  /* SYST_RVR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,RELOAD=0x0003A97F */
  SYST_RVR = SysTick_RVR_RELOAD(0x0003A97F); /* Setup reload value */
  /* SYST_CVR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CURRENT=0 */
  SYST_CVR = 0x00U;                    /* Clear current value */
  /* SCB_SHPR3: PRI_15=0x80 */
  SCB_SHPR3 = (uint32_t)((SCB_SHPR3 & (uint32_t)~(uint32_t)(
               SCB_SHPR3_PRI_15(0x7F)
              )) | (uint32_t)(
               SCB_SHPR3_PRI_15(0x80)
              ));                                                  
  /* SYST_CSR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNTFLAG=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CLKSOURCE=1,TICKINT=1,ENABLE=0 */
  SYST_CSR = (SysTick_CSR_CLKSOURCE_MASK | SysTick_CSR_TICKINT_MASK); /* Set up control register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_SystemTimer1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

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
void SystemTimer1_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  SystemTimer1_TDeviceData *DeviceDataPrv = (SystemTimer1_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPrv;
  SysTick_PDD_EnableDevice(SysTick_BASE_PTR, PDD_DISABLE);
  /* Interrupt vector(s) deallocation */
  /* {MQXLite RTOS Adapter} Restore interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not restored, because it was not modified */
  (void)_int_install_isr(LDD_ivIndex_INT_SysTick, ((SystemTimer1_TDeviceDataPtr)DeviceDataPrv)->SavedISRSettings_TUInterrupt.isrFunction, ((SystemTimer1_TDeviceDataPtr)DeviceDataPrv)->SavedISRSettings_TUInterrupt.isrData);
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_SystemTimer1_ID);
  /* Deallocation of the device structure */
  /* {MQXLite RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

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
LDD_TError SystemTimer1_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  SysTick_PDD_EnableDevice(SysTick_BASE_PTR, PDD_ENABLE); /* Enable the device */
  return ERR_OK;
}

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
uint32_t SystemTimer1_GetInputFrequency(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  return SystemTimer1_CNT_INP_FREQ_U_0;
}

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
LDD_TError SystemTimer1_SetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, SystemTimer1_TValueType Ticks)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Ticks > 16777215U) {             /* Is the given value out of range? */
    return ERR_PARAM_TICKS;            /* If yes then error */
  }
  SysTick_PDD_WriteReloadValueReg(SysTick_BASE_PTR, (uint32_t)(--Ticks));
  return ERR_OK;                       /* OK */
}

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
LDD_TError SystemTimer1_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, SystemTimer1_TValueType *TicksPtr)
{
  uint32_t tmp;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  tmp = (SystemTimer1_TValueType)(SysTick_PDD_ReadReloadValueReg(SysTick_BASE_PTR));
  *TicksPtr = (SystemTimer1_TValueType)++tmp;
  *TicksPtr &= 0x00FFFFFFUL;
  return ERR_OK;                       /* OK */
}

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
LDD_TError SystemTimer1_ResetCounter(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* {MQXLite RTOS Adapter} Critical section begin (RTOS function call is defined by MQXLite RTOS Adapter property) */
  _int_disable();
  if ((SysTick_PDD_GetEnableDeviceStatus(SysTick_BASE_PTR)) != 0U) {
    SysTick_PDD_EnableDevice(SysTick_BASE_PTR, PDD_DISABLE);
    SysTick_PDD_EnableDevice(SysTick_BASE_PTR, PDD_ENABLE);
  }
  /* {MQXLite RTOS Adapter} Critical section ends (RTOS function call is defined by MQXLite RTOS Adapter property) */
  _int_enable();
  return ERR_OK;                       /* OK */
}

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
SystemTimer1_TValueType SystemTimer1_GetCounterValue(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  return (SystemTimer1_TValueType)SysTick_PDD_ReadCurrentValueReg(SysTick_BASE_PTR);
}

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
void SystemTimer1_Interrupt(LDD_RTOS_TISRParameter _isrParameter)
{
  /* {MQXLite RTOS Adapter} ISR parameter is passed as parameter from RTOS interrupt dispatcher */
  SystemTimer1_TDeviceDataPtr DeviceDataPrv = (SystemTimer1_TDeviceDataPtr)_isrParameter;

  SysTick_PDD_ClearInterruptFlag(SysTick_BASE_PTR); /* Clear interrupt flag */
  SystemTimer1_OnCounterRestart(DeviceDataPrv->UserDataPtr); /* Invoke OnCounterRestart event */
}

/* END SystemTimer1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
