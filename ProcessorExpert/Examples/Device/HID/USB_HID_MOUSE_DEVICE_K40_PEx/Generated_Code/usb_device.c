/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : usb_device.c
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVMD10
**     Component   : USB_DEVICE_STACK
**     Version     : Component 01.027, Driver 01.00, CPU db: 3.00.003
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 11:06, # CodeGen: 30
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         USB_Class_Init                 - uint_8 usb_device_USB_Class_Init(uint_8 controller_ID, USB_CLASS_CALLBACK...
**         USB_Class_DeInit               - uint_8 usb_device_USB_Class_DeInit(uint_8 controller_ID);
**         USB_Class_Send_Data            - uint_8 usb_device_USB_Class_Send_Data(uint_8 controller_ID, uint_8 ep_num,...
**         USB_Class_Periodic_Task        - void usb_device_USB_Class_Periodic_Task(void);
**         _usb_device_init               - uint_8 usb_device__usb_device_init(uint_8 device_number, _usb_device_handle...
**         _usb_device_deinit             - uint_8 usb_device__usb_device_deinit(void);
**         _usb_device_init_endpoint      - uint_8 usb_device__usb_device_init_endpoint(_usb_device_handle handle, uint_8...
**         _usb_device_deinit_endpoint    - uint_8 usb_device__usb_device_deinit_endpoint(_usb_device_handle handle,...
**         _usb_device_get_status         - uint_8 usb_device__usb_device_get_status(_usb_device_handle handle, uint_8...
**         _usb_device_set_status         - uint_8 usb_device__usb_device_set_status(_usb_device_handle handle, uint_8...
**         _usb_device_register_service   - uint_8 usb_device__usb_device_register_service(uint_8 controller_ID, uint_8...
**         _usb_device_unregister_service - uint_8 usb_device__usb_device_unregister_service(_usb_device_handle handle,...
**         USB_Device_Call_Service        - uint_8 usb_device_USB_Device_Call_Service(uint_8 type,...
**         USB_Framework_Init             - uint_8 usb_device_USB_Framework_Init(uint_8 controller_ID, USB_CLASS_CALLBACK...
**         USB_Framework_DeInit           - uint_8 usb_device_USB_Framework_DeInit(uint_8 controller_ID);
**         USB_Framework_Reset            - uint_8 usb_device_USB_Framework_Reset(uint_8 controller_ID);
**         USB_DCI_Bus_Reset_Handler      - void usb_device_USB_DCI_Bus_Reset_Handler(void);
**         USB_DCI_Init                   - uint_8 usb_device_USB_DCI_Init(uint_8 controller_ID);
**         USB_DCI_DeInit                 - void usb_device_USB_DCI_DeInit(void);
**         USB_DCI_Init_EndPoint          - uint_8 usb_device_USB_DCI_Init_EndPoint(uint_8 controller_ID,...
**         USB_DCI_Deinit_EndPoint        - uint_8 usb_device_USB_DCI_Deinit_EndPoint(uint_8 controller_ID, uint_8...
**         USB_DCI_Cancel_Transfer        - uint_8 usb_device_USB_DCI_Cancel_Transfer(_usb_device_handle handle, uint_8...
**         USB_DCI_Stall_EndPoint         - void usb_device_USB_DCI_Stall_EndPoint(_usb_device_handle handle, uint_8...
**         USB_DCI_Unstall_EndPoint       - void usb_device_USB_DCI_Unstall_EndPoint(_usb_device_handle handle, uint_8...
**         USB_DCI_Get_Setup_Data         - void usb_device_USB_DCI_Get_Setup_Data(_usb_device_handle handle, uint_8...
**         USB_DCI_Get_Transfer_Status    - uint_8 usb_device_USB_DCI_Get_Transfer_Status(_usb_device_handle handle,...
**         USB_DCI_Recv_Data              - uint_8 usb_device_USB_DCI_Recv_Data(_usb_device_handle handle, uint_8...
**         USB_DCI_Send_Data              - uint_8 usb_device_USB_DCI_Send_Data(_usb_device_handle handle, uint_8...
**         USB_DCI_Assert_Resume          - void usb_device_USB_DCI_Assert_Resume(_usb_device_handle handle);
**         USB_DCI_Set_Address            - void usb_device_USB_DCI_Set_Address(_usb_device_handle handle, uint_8 address);
**         USB_DCI_OnDeviceSpeedDetect    - void usb_device_USB_DCI_OnDeviceSpeedDetect(LDD_TUserData *UserDataPtr,...
**         USB_DCI_OnDeviceSuspend        - void usb_device_USB_DCI_OnDeviceSuspend(LDD_TUserData *UserDataPtr);
**         USB_DCI_OnDeviceResume         - void usb_device_USB_DCI_OnDeviceResume(LDD_TUserData *UserDataPtr);
**         USB_DCI_OnDeviceSetupPacket    - void usb_device_USB_DCI_OnDeviceSetupPacket(LDD_TUserData *UserDataPtr,...
**         USB_DCI_OnDeviceError          - void usb_device_USB_DCI_OnDeviceError(LDD_TUserData *UserDataPtr, uint8_t...
**         Clear_Mem                      - void usb_device_Clear_Mem(uint_8_ptr start_addr, uint_32 count, uint_8 val);
**         USB_Desc_Get_Descriptor        - uint_8 usb_device_USB_Desc_Get_Descriptor(uint_8 controller_ID, uint_8 type,...
**         USB_Desc_Get_Interface         - uint_8 usb_device_USB_Desc_Get_Interface(uint_8 controller_ID, uint_8...
**         USB_Desc_Set_Interface         - uint_8 usb_device_USB_Desc_Set_Interface(uint_8 controller_ID, uint_8...
**         USB_Desc_Valid_Configation     - bool usb_device_USB_Desc_Valid_Configation(uint_8 controller_ID, uint_16...
**         USB_Desc_Valid_Interface       - bool usb_device_USB_Desc_Valid_Interface(uint_8 controller_ID, uint_8...
**         USB_Desc_Remote_Wakeup         - bool usb_device_USB_Desc_Remote_Wakeup(uint_8 controller_ID);
**         USB_Desc_Get_Endpoints         - void* usb_device_USB_Desc_Get_Endpoints(uint_8 controller_ID);
**
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

/* MODULE usb_device. */
#include "usb_dci.h"

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDeviceReset (component USB_DEVICE_STACK)
**
**     Description :
**         Called after the reset signal is detected on the USB bus, 
**         OnDeviceReset() event is enabled and USB module is enabled. 
**         See SetEventMask() and GetEventMask() methods. All pending 
**         transfers are cancelled and all EPs are disabled before this 
**         event is called.  Device address is set to "0".  The event 
**         services the event of the inherited component and eventually 
**         invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDeviceReset(LDD_TUserData *UserDataPtr)
{
    USB_DCI_Bus_Reset_Handler();
}

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDeviceSpeedDetect (component USB_DEVICE_STACK)
**
**     Description :
**         Called after the device detects bus speed, OnBusSpedDetect() 
**         event is enabled and USB module is enabled. See SetEventMask() 
**         and GetEventMask() methods. EP 0 should be enabled and 
**         configured after the USB speed is known. The event services 
**         the event of the inherited component and eventually invokes 
**         other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDeviceSpeedDetect(LDD_TUserData *UserDataPtr, LDD_USB_TBusSpeed CurrentSpeed)
{
    USB_DCI_OnDeviceSpeedDetect(UserDataPtr,CurrentSpeed);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDeviceSuspend (component USB_DEVICE_STACK)
**
**     Description :
**         Called after the suspend condition is met, OnDeviceSuspend() 
**         event is enabled and USB module is enabled. See SetEventMask() 
**         and GetEventMask() methods. The event services the event of 
**         the inherited component and eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDeviceSuspend(LDD_TUserData *UserDataPtr)
{
    USB_DCI_OnDeviceSuspend(UserDataPtr);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDeviceResume (component USB_DEVICE_STACK)
**
**     Description :
**         Called after the resume signaling is done, OnDeviceResume() 
**         event is enabled and USB module is enabled. See SetEventMask() 
**         and GetEventMask() methods. The event services the event of 
**         the inherited component and eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDeviceResume(LDD_TUserData *UserDataPtr)
{
    USB_DCI_OnDeviceResume(UserDataPtr);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDeviceSetupPacket (component USB_DEVICE_STACK)
**
**     Description :
**         Called after the setup packet is received into the internal 
**         buffer, OnSetupPacket() event is enabled and USB module is 
**         enabled. See SetEventMask() and GetEventMask() methods. Use 
**         the method GetSetupPacket() to copy setup packet to the user 
**         buffer. The event services the event of the inherited 
**         component and eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDeviceSetupPacket(LDD_TUserData *UserDataPtr, uint8_t EpNum)
{
    USB_DCI_OnDeviceSetupPacket(UserDataPtr,EpNum);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDeviceSof (component USB_DEVICE_STACK)
**
**     Description :
**         Called after the Sof is received, OnSof() event is enabled and 
**         USB module is enabled. See SetEventMask() and GetEventMask() 
**         methods. The event services the event of the inherited 
**         component and eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDeviceSof(LDD_TUserData *UserDataPtr, uint16_t FrameNumber)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDeviceError (component USB_DEVICE_STACK)
**
**     Description :
**         Called after the Error is detected, OnError() event is enabled 
**         and USB module is enabled. See SetEventMask() and 
**         GetEventMask() methods. The event services the event of the 
**         inherited component and eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDeviceError(LDD_TUserData *UserDataPtr, uint8_t ErrorSource, uint8_t ErrorCode)
{
    USB_DCI_OnDeviceError(UserDataPtr,ErrorSource,ErrorCode);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_LDD_OnDevice1msTimer (component USB_DEVICE_STACK)
**
**     Description :
**         Called each 1 ms, On1msTimer() event is enabled and USB module 
**         is enabled. See SetEventMask() and GetEventMask() methods. The 
**         event services the event of the inherited component and 
**         eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnDevice1msTimer(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}



/* END usb_device. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
