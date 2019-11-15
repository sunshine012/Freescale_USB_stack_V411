/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : USB_LDD.h
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : USB_LDD
**     Version     : Component 01.306, Driver 01.08, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-23, 10:14, # CodeGen: 1
**     Abstract    :
**         This component implements an low level USB API.
**     Settings    :
**          Component name                                 : USB_LDD
**          USB module (SIE)                               : USB0
**          Input clock frequency [MHz]                    : 48 MHz
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_USB0
**            Interrupt priority                           : medium priority
**          Mode                                           : HOST
**            Transceiver type                             : Internal
**              Transceiver module                         : USB0_FS
**              Transceiver weak pull-downs                : Enabled
**              USB revision                               : USB 2.0
**              Host data rates                            : 
**                Low speed                                : yes
**                Full speed                               : yes
**                High speed                               : no
**              Pin/signal setting                         : 
**                Clock pin                                : Disabled
**                USB data pins                            : 
**                  Data plus                              : 
**                    Pin                                  : USB0_DP
**                    Pin signal                           : 
**                  Data minus                             : 
**                    Pin                                  : USB0_DM
**                    Pin signal                           : 
**                VBUS pins                                : 
**                  VBUS enable                            : Disabled
**                  VBUS overcurrent                       : Disabled
**                Pullup/Pulldown pins                     : 
**                  DP pulldown                            : Enabled
**                    Pin                                  : USB0_Internal_DP_PD
**                    Pin signal                           : 
**                    Polarity                             : Activ high
**                  DM pulldown                            : Enabled
**                    Pin                                  : USB0_Internal_DM_PD
**                    Pin signal                           : 
**                    Polarity                             : Activ high
**            Host mode setting                            : 
**              Max. pipes                                 : 5
**              Max. transfers                             : 5
**              Asynchronous transfers                     : yes
**                Control transfers                        : yes
**                Bulk transfers                           : no
**              Periodic transfers                         : yes
**                Interrupt transfers                      : yes
**                Isochronous transfers                    : no
**            Initialization                               : 
**              Enabled in init. code                      : no
**              Auto initialization                        : no
**              Event mask                                 : 
**                OnHostDeviceDeattach                     : Enabled
**                OnHostResetRecovery                      : Enabled
**                OnHostResumeRecovery                     : Enabled
**                OnHostError                              : Enabled
**                OnHost1msTimer                           : Disabled
**                OnSignalChange                           : Enabled
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
**         Init                    - LDD_TDeviceData * USB_LDD_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void USB_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetEventMask            - LDD_TError USB_LDD_SetEventMask(LDD_TDeviceData *DeviceDataPtr,...
**         GetEventMask            - LDD_TEventMask USB_LDD_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
**         Enable                  - LDD_TError USB_LDD_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable                 - LDD_TError USB_LDD_Disable(LDD_TDeviceData *DeviceDataPtr);
**         HostGetPortState        - LDD_USB_Host_TState USB_LDD_HostGetPortState(LDD_TDeviceData *DeviceDataPtr);
**         HostSetPortState        - LDD_TError USB_LDD_HostSetPortState(LDD_TDeviceData *DeviceDataPtr,...
**         HostGetFrameNumber      - uint16_t USB_LDD_HostGetFrameNumber(LDD_TDeviceData *DeviceDataPtr);
**         HostGetMicroFrameNumber - uint8_t USB_LDD_HostGetMicroFrameNumber(LDD_TDeviceData *DeviceDataPtr);
**         HostOpenPipe            - LDD_TError USB_LDD_HostOpenPipe(LDD_TDeviceData *DeviceDataPtr,...
**         HostClosePipe           - LDD_TError USB_LDD_HostClosePipe(LDD_TDeviceData *DeviceDataPtr,...
**         HostSendSetup           - LDD_TError USB_LDD_HostSendSetup(LDD_TDeviceData *DeviceDataPtr,...
**         HostSendData            - LDD_TError USB_LDD_HostSendData(LDD_TDeviceData *DeviceDataPtr,...
**         HostRecvData            - LDD_TError USB_LDD_HostRecvData(LDD_TDeviceData *DeviceDataPtr,...
**         HostGetTransferStatus   - LDD_USB_TTransferState USB_LDD_HostGetTransferStatus(LDD_TDeviceData...
**         HostCancelTransfer      - LDD_TError USB_LDD_HostCancelTransfer(LDD_TDeviceData *DeviceDataPtr,...
**         SetOperationMode        - LDD_TError USB_LDD_SetOperationMode(LDD_TDeviceData *DeviceDataPtr,...
**         GetDriverState          - LDD_TDriverState USB_LDD_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __USB_LDD_H
#define __USB_LDD_H

/* MODULE USB_LDD. */
#include "PE_LDD.h"

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define USB_LDD_PRPH_BASE_ADDRESS  0x40072000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define USB_LDD_Init_METHOD_ENABLED
#define USB_LDD_Deinit_METHOD_ENABLED
#define USB_LDD_SetEventMask_METHOD_ENABLED
#define USB_LDD_GetEventMask_METHOD_ENABLED
#define USB_LDD_Enable_METHOD_ENABLED
#define USB_LDD_Disable_METHOD_ENABLED
#define USB_LDD_HostGetPortState_METHOD_ENABLED
#define USB_LDD_HostSetPortState_METHOD_ENABLED
#define USB_LDD_HostGetFrameNumber_METHOD_ENABLED
#define USB_LDD_HostGetMicroFrameNumber_METHOD_ENABLED
#define USB_LDD_HostOpenPipe_METHOD_ENABLED
#define USB_LDD_HostClosePipe_METHOD_ENABLED
#define USB_LDD_HostSendSetup_METHOD_ENABLED
#define USB_LDD_HostSendData_METHOD_ENABLED
#define USB_LDD_HostRecvData_METHOD_ENABLED
#define USB_LDD_HostGetTransferStatus_METHOD_ENABLED
#define USB_LDD_HostCancelTransfer_METHOD_ENABLED
#define USB_LDD_SetOperationMode_METHOD_ENABLED
#define USB_LDD_GetDriverState_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define USB_LDD_OnHostDeviceDeattach_EVENT_ENABLED
#define USB_LDD_OnHostResetRecovery_EVENT_ENABLED
#define USB_LDD_OnHostResumeRecovery_EVENT_ENABLED
#define USB_LDD_OnHostError_EVENT_ENABLED

/* Driver mode */
#define USB_LDD_MODE_HOST

LDD_TDeviceData * USB_LDD_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_Init (component USB_LDD)
**
**     Description :
**         Initializes USB device. Allocates memory for the device data
**         structure, interrupts, pins, etc. This method doesn't enable
**         device pull-up. Use Enable() method to enable device pull-up.
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

void USB_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_Deinit (component USB_LDD)
**
**     Description :
**         Disables and deinitializes the device and frees the device
**         data structure memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError USB_LDD_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask);
/*
** ===================================================================
**     Method      :  USB_LDD_SetEventMask (component USB_LDD)
**
**     Description :
**         Enables/disables event(s). The events contained within the
**         mask are enabled. Events not contained within the mask are
**         disabled. Pair method to GetEventMask().
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         EventMask       - Mask of events to enable.
**     Returns     :
**         ---             - Return value:
**                           ERR_OK
**                           ERR_PARAM_MASK - Invalid mask.
**                           ERR_DISABLED - Device is disabled.
** ===================================================================
*/

LDD_TEventMask USB_LDD_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_GetEventMask (component USB_LDD)
**
**     Description :
**         Returns current events mask. Pair method to SetEventMask().
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Current event mask.
** ===================================================================
*/

LDD_TError USB_LDD_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_Enable (component USB_LDD)
**
**     Description :
**         Enables the USB device (PHY, SIE). Enables device's DP(DM)
**         pull-up.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - 
** ===================================================================
*/

LDD_TError USB_LDD_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_Disable (component USB_LDD)
**
**     Description :
**         Disabled device's DP(DM) pull-up. Disables PHY, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - 
** ===================================================================
*/

LDD_USB_Host_TState USB_LDD_HostGetPortState(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostGetPortState (component USB_LDD)
**
**     Description :
**         Returns port <state>.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Returned value:
**                           LDD_USB_HOST_DISABLED - Host mode is
**                           disabled (by the user or by the clock
**                           configuration).
**                           LDD_USB_HOST_DISABLED_BY_OTG - Host mode is
**                           disabled by the OTG driver.
**                           LDD_USB_HOST_PORT_POWERED_OFF - Port is
**                           powered-off.
**                           LDD_USB_HOST_PORT_DISCONNECTED -  No device
**                           is connected.
**                           LDD_USB_HOST_PORT_DISABLED - Device is
**                           connected to the port.
**                           LDD_USB_HOST_PORT_RESETING - Port generates
**                           reset signaling.
**                           LDD_USB_HOST_PORT_RESET_RECOVERING - Port
**                           waits 10 ms for reset recovery.
**                           LDD_USB_HOST_PORT_ENABLED - Device is
**                           connected, reset and ready to use.
**                           LDD_USB_HOST_PORT_SUSPENDED - Port is
**                           suspended.
**                           LDD_USB_HOST_PORT_RESUME_READY - Port is
**                           ready to generate resume signaling.
**                           LDD_USB_HOST_PORT_RESUMING - Port generates
**                           resume signaling.
**                           LDD_USB_HOST_PORT_RESUME_RECOVERING - Port
**                           waits 10 ms for resume recovery.
** ===================================================================
*/

LDD_TError USB_LDD_HostSetPortState(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TPortControlCmd Cmd);
/*
** ===================================================================
**     Method      :  USB_LDD_HostSetPortState (component USB_LDD)
**
**     Description :
**         This method sets root port (bus) states. Supported commands
**         are:
**         [LDD_USB_HOST_PORT_CMD_POWER_OFF]
**         Deactivates VBUS enable signal and sets the port to the
**         POWER_OFF state, closes all pipes and discards all pending
**         transfers.
**         [LDD_USB_HOST_PORT_CMD_POWER_ON]
**         Activates VBUS enable signal and sets the port to the
**         DISCONNECTED state.
**         Port must be in the POWERED_OFF state to be power on.
**         [LDD_USB_HOST_PORT_CMD_RESET]
**         Sets the port to the RESETING state, starts the reset
**         signaling and closes all pipes and discards all pending
**         transfers. As soon as the reset interval is elapsed the
**         reset signaling will be stopped, the port state will be
**         change to the RESET_RECOVERING, and the reset recovery
**         interval will begin. After the reset recovery interval is
**         elapsed, the port state will be changed to the ENABLED state.
**         In the ENABLED state the port can used to transfer data.
**         Device must be connected (ports state > DISCONNECTED) before
**         reset can be started.
**         [LDD_USB_HOST_PORT_CMD_DISABLE]
**         Sets the port to the DISABLED state and closes all pipes and
**         discards all pending transfers. This state can be changed
**         only by performing the bus reset(transfer to the ENABLED
**         state), by disconnecting the device (transfer to the
**         DISCONNECT state) or by the powering-off the bus (transfer
**         to the POWERED_OFF state).
**         [LDD_USB_HOST_PORT_CMD_SUSPEND]
**         Suspends port (state = SUSPENDED). No transaction should be
**         pending before this method is called.
**         Port must be in the LDD_USB_HOST_PORT_ENABLED state to be
**         suspend.
**         [LDD_USB_HOST_PORT_CMD_RESUME]
**         Sets the port to the RESUMING state and starts the resume
**         signaling. After the resume interval is elapsed, the port
**         state will be changed to the ENABLED state. In the ENABLED
**         state the port can used to transfer data.
**         Port must be in the LDD_USB_HOST_PORT_RESUME_READY state
**         before resume can start.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Cmd             - Command
**     Returns     :
**         ---             - Return value: ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component is disabled.
**                           ERR_PARAM_COMMAND - Unknown command.
**                           ERR_USB_HOST_XXX where XXX is name of the
**                           state - Requested operation cannot be is
**                           done in current <state>.
** ===================================================================
*/

uint16_t USB_LDD_HostGetFrameNumber(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostGetFrameNumber (component USB_LDD)
**
**     Description :
**         This method returns current frame number.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Frame number.
** ===================================================================
*/

uint8_t USB_LDD_HostGetMicroFrameNumber(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostGetMicroFrameNumber (component USB_LDD)
**
**     Description :
**         This method returns current microframe number.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Microframe number.
** ===================================================================
*/

LDD_TError USB_LDD_HostOpenPipe(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TPipeDescr *PipeInitParamsPtr, LDD_USB_Host_TPipeHandle **PipeHandlePtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostOpenPipe (component USB_LDD)
**
**     Description :
**         Initializes pipe according to the values in the endpoint
**         descriptor and in the flags parameter. Allocate bandwidth
**         for periodic transfer types.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * PipeInitParamsPtr - Pointer to the
**                           structure containing pipe configuration
**                           data.
**       * PipeHandlePtr   - Pointer to pipe handle
**                           variable.
**     Returns     :
**         ---             - Return value:
**                           ERR_DISABLED - Device is disabled.
**                           ERR_PARAM_ID - Requested transfer is not
**                           supported by the HW .
**                           ERR_OVERFLOW - Not enough frame time for
**                           periodic transfer type.
**                           ERR_OK - OK
** ===================================================================
*/

LDD_TError USB_LDD_HostClosePipe(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TPipeHandle *PipeHandlePtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostClosePipe (component USB_LDD)
**
**     Description :
**         Deinitializes EP and disables it in the HW. For control EP
**         both directions are deinitialized. All pending transfers are
**         aborted and callback functions are called, if enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * PipeHandlePtr   - Pipe handle
**     Returns     :
**         ---             - Return value:
**                           ERR_DISABLED - Device is disabled.
**                           ERR_OK - OK
** ===================================================================
*/

LDD_TError USB_LDD_HostSendSetup(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TPipeHandle *PipeHandlePtr, LDD_USB_Host_TTD *TransferDescriptorPtr, LDD_USB_Host_TTransferHandle **TransferHandlePtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostSendSetup (component USB_LDD)
**
**     Description :
**         This method prepares control transfer. All transfer phases
**         are handled by this method.
**         Note: On some MCUs (e.g. Kinetis) must be the address of the
**         data buffer 4 bytes aligned.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * PipeHandlePtr   - Pipe handle.
**       * TransferDescriptorPtr -
**                           Pointer to transfer descriptor.
**       * TransferHandlePtr - Pointer to
**                           transfer handle variable.
**     Returns     :
**         ---             - Return value: ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component is disabled.
**                           ERR_PARAM_ADDRESS - Transfer descriptor
**                           pointer or Pipe descriptor pointer is NULL.
**                           ERR_PARAM_DATA - Pointer to the Setup data
**                           packet is NULL.
**                           ERR_FAILED - Pipe is closed.
**                           ERR_USB_HOST_XXX where XXX is name of the
**                           state - Port is not in enabled <state>.
** ===================================================================
*/

LDD_TError USB_LDD_HostSendData(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TPipeHandle *PipeHandlePtr, LDD_USB_Host_TTD *TransferDescriptorPtr, LDD_USB_Host_TTransferHandle **TransferHandlePtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostSendData (component USB_LDD)
**
**     Description :
**         This method prepares data to be sent to the device.
**         Note: On some MCUs (e.g. Kinetis) must be the address of the
**         data buffer 4 bytes aligned.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * PipeHandlePtr   - Pipe handle.
**       * TransferDescriptorPtr -
**                           Pointer to transfer descriptor.
**       * TransferHandlePtr - Pointer to
**                           transfer handle variable.
**     Returns     :
**         ---             - Return value: ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component is disabled.
**                           ERR_PARAM_ADDRESS - Transfer descriptor
**                           pointer or Pipe handle is NULL.
**                           ERR_FAILED - Pipe is closed.
**                           ERR_USB_HOST_XXX where XXX is name of the
**                           state - Port is not in enabled <state>.
** ===================================================================
*/

LDD_TError USB_LDD_HostRecvData(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TPipeHandle *PipeHandlePtr, LDD_USB_Host_TTD *TransferDescriptorPtr, LDD_USB_Host_TTransferHandle **TransferHandlePtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostRecvData (component USB_LDD)
**
**     Description :
**         This method prepares buffer for data sent by the device.
**         Note: On some MCUs (e.g. Kinetis) must be the address of the
**         data buffer 4 bytes aligned.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * PipeHandlePtr   - Pipe handle.
**       * TransferDescriptorPtr -
**                           Pointer to transfer descriptor.
**       * TransferHandlePtr - Pointer to
**                           transfer handle variable.
**     Returns     :
**         ---             - Return value: ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component is disabled.
**                           ERR_PARAM_ADDRESS - Transfer descriptor
**                           pointer or Pipe handle is NULL.
**                           ERR_FAILED - Pipe is closed.
**                           ERR_USB_HOST_XXX where XXX is name of the
**                           state - Port is not in enabled <state>.
** ===================================================================
*/

LDD_USB_TTransferState USB_LDD_HostGetTransferStatus(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TTransferHandle *TransferHandlePtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostGetTransferStatus (component USB_LDD)
**
**     Description :
**         This method returns transfer status.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * TransferHandlePtr - Pointer to
**                           transfer handle return by Send/Recv methods
**                           in the 'TransferDescriptorPtr' variable.
**     Returns     :
**         ---             - Transfer status.
** ===================================================================
*/

LDD_TError USB_LDD_HostCancelTransfer(LDD_TDeviceData *DeviceDataPtr, LDD_USB_Host_TPipeDescr *PipeHandlePtr);
/*
** ===================================================================
**     Method      :  USB_LDD_HostCancelTransfer (component USB_LDD)
**
**     Description :
**         This method cancels all pending transfer requests in the
**         given EP queue. Callback function is called ( if enabled)
**         for each cancelled transfer request.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * PipeHandlePtr   - Pipe handle
**     Returns     :
**         ---             - Return value: ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component is disabled.
**                           ERR_PARAM_ADDRESS - Transfer descriptor
**                           pointer or Pipe handle is NULL.
**                           ERR_FAILED - Pipe is closed.
**                           ERR_USB_HOST_XXX where XXX is name of the
**                           state - Port is not in enabled <state>.
** ===================================================================
*/

LDD_TError USB_LDD_SetOperationMode(LDD_TDeviceData *DeviceDataPtr, LDD_TDriverOperationMode OperationMode, LDD_TCallback ModeChangeCallback, LDD_TCallbackParam *ModeChangeCallbackParamPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_SetOperationMode (component USB_LDD)
**
**     Description :
**         This method requests to change the component's operation
**         mode. Upon a request to change the operation mode, the
**         component will finish a pending job first and then notify a
**         caller that an operation mode has been changed. When no job
**         is pending (ERR_OK), the component changes an operation mode
**         immediately and notify a caller about this change. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         OperationMode   - Requested driver
**                           operation mode.
**         ModeChangeCallback - Callback to
**                           notify the upper layer once a mode has been
**                           changed.
**       * ModeChangeCallbackParamPtr 
**                           - Pointer to callback parameter to notify
**                           the upper layer once a mode has been
**                           changed.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - This component is disabled
**                           by user.
**                           ERR_PARAM_MODE - Invalid operation mode.
**                           ERR_BUSY - A job is pending.
** ===================================================================
*/

LDD_TDriverState USB_LDD_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  USB_LDD_GetDriverState (component USB_LDD)
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
**                           PE_LDD_DRIVER_DISABLED_IN_CLOCK_CONFIGURATIO
**                           N - 1 - Driver is disabled in the current
**                           mode; 0 - Driver is enabled in the current
**                           mode.  
**                           PE_LDD_DRIVER_DISABLED_BY_USER - 1 - Driver
**                           is disabled by the user; 0 - Driver is
**                           enabled by the user.        
**                           PE_LDD_DRIVER_BUSY - 1 - Driver is the BUSY
**                           state; 0 - Driver is in the IDLE state.
** ===================================================================
*/

/* {MQXLite RTOS Adapter} ISR function prototype */
void USB_LDD_USB_Interrupt(LDD_RTOS_TISRParameter _isrParameter);
/*
** ===================================================================
**     Method      :  USB_LDD_USB_Interrupt (component USB_LDD)
**
**     Description :
**         USB interrupt handler
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END USB_LDD. */

#endif
/* ifndef __USB_LDD_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
