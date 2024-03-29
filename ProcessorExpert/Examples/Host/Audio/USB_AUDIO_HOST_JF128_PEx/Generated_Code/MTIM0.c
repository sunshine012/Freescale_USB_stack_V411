/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MTIM0.c
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

/* MODULE MTIM0. */

#include "Events.h"
#include "MTIM0.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"


typedef struct {
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} MTIM0_TDeviceData;

typedef MTIM0_TDeviceData *MTIM0_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static MTIM0_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static MTIM0_TDeviceDataPtr Vmtim0__DEFAULT_RTOS_ISRPARAM;

#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERUNIT_ON_COUNTER_RESTART)

/* Internal method prototypes */
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
LDD_TDeviceData* MTIM0_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  MTIM0_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  Vmtim0__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* SIM_SCGC3: MTIM=1 */
  SIM_SCGC3 |= (uint8_t)0x10U;                            
  /* MTIM0_SC: TOF=0,TOIE=0,TRST=1,TSTP=1,??=0,??=0,??=0,??=0 */
  MTIM0_SC = (uint8_t)0x30U;           /* Reset and disable timer */
  /* MTIM0_MOD: MOD=0x0177 */
  MTIM0_MOD = (uint16_t)0x0177U;       /* Set up modulo register */
  /* MTIM0_CLK: ??=0,??=0,CLKS=0,PS=3 */
  MTIM0_CLK = (uint8_t)0x03U;          /* Set up clock confuguration register */
  /* INTC_IMRH: IMR39=0 */
  INTC_IMRH &= (uint32_t)~0x80UL;                      
  /* MTIM0_SC: TOF=0,TOIE=1,TRST=1,TSTP=0,??=0,??=0,??=0,??=0 */
  MTIM0_SC = (uint8_t)0x60U;           /* Set up control register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_MTIM0_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

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
void MTIM0_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  MTIM0_TDeviceData *DeviceDataPrv = (MTIM0_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPrv;
  MTIM_PDD_EnableDevice(MTIM0_BASE_PTR, PDD_DISABLE);
  /* Interrupt vector(s) deallocation */
  /* {Default RTOS Adapter} Restore interrupt vector: IVT is static, no code is generated */
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_MTIM0_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

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
LDD_TError MTIM0_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  MTIM_PDD_EnableDevice(MTIM0_BASE_PTR, PDD_ENABLE);
  return ERR_OK;
}

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
LDD_TError MTIM0_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  MTIM_PDD_EnableDevice(MTIM0_BASE_PTR, PDD_DISABLE);
  return ERR_OK;
}

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
LDD_TDriverState MTIM0_GetDriverState(LDD_TDeviceData *DeviceDataPtr)
{
  LDD_TDriverState DriverState = 0x00U;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  DriverState |= (MTIM_PDD_GetEnableDeviceStatus(MTIM0_BASE_PTR))? 0x00U : PE_LDD_DRIVER_DISABLED_BY_USER; /* Driver disabled by the user? */
  return DriverState;
}

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
PE_ISR(MTIM0_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  MTIM0_TDeviceDataPtr DeviceDataPrv = Vmtim0__DEFAULT_RTOS_ISRPARAM;
  MTIM_PDD_ClearInterruptFlag(MTIM0_BASE_PTR); /* Clear interrupt flag */
  MTIM0_OnCounterRestart(DeviceDataPrv->UserDataPtr); /* Invoke OnCounterRestart event */
}

/* END MTIM0. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.02]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
