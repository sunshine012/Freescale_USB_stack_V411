/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : usb_host.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : USB_HOST_STACK
**     Version     : Component 01.027, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 11:51, # CodeGen: 16
**     Abstract    :
**
**     Settings    :
**          Component name                                 : usb_host
**     Contents    :
**         usb_class_hub_init               - void usb_host_usb_class_hub_init(PIPE_BUNDLE_STRUCT_PTR pbs_ptr,...
**         usb_class_hub_cntrl_callback     - void usb_host_usb_class_hub_cntrl_callback(void* pipe, void* param, uchar_ptr...
**         usb_class_hub_cntrl_common       - USB_STATUS usb_host_usb_class_hub_cntrl_common(HUB_COMMAND_PTR com_ptr,...
**         usb_class_hub_get_descriptor     - USB_STATUS usb_host_usb_class_hub_get_descriptor(HUB_COMMAND_PTR com_ptr,...
**         usb_class_hub_set_port_feature   - USB_STATUS usb_host_usb_class_hub_set_port_feature(HUB_COMMAND_PTR com_ptr,...
**         usb_class_hub_clear_port_feature - USB_STATUS usb_host_usb_class_hub_clear_port_feature(HUB_COMMAND_PTR com_ptr,...
**         usb_class_hub_get_port_status    - USB_STATUS usb_host_usb_class_hub_get_port_status(HUB_COMMAND_PTR com_ptr,...
**         usb_host_hub_device_event        - void usb_host_usb_host_hub_device_event(_usb_device_instance_handle...
**         _usb_khci_task                   - void usb_host__usb_khci_task(void);
**         _usb_event_init                  - uint_16 usb_host__usb_event_init(USB_EVENT_STRUCT_PTR event);
**         _usb_event_clear                 - uint_16 usb_host__usb_event_clear(USB_EVENT_STRUCT_PTR event, uint_32 bitmask);
**         _usb_event_wait_ticks            - uint_16 usb_host__usb_event_wait_ticks(USB_EVENT_STRUCT_PTR event, uint_32...
**         _usb_host_register_ch9_callback  - USB_STATUS usb_host__usb_host_register_...
**         _usb_host_ch9_clear_feature      - USB_STATUS usb_host__usb_host_ch9_clear_feature(_usb_device_instance_handle...
**         _usb_host_ch9_get_configuration  - USB_STATUS usb_host__usb_host_ch9_get_c...
**         _usb_host_ch9_get_descriptor     - USB_STATUS usb_host__usb_host_ch9_get_descriptor(_usb_device_instance_handle...
**         _usb_host_ch9_get_interface      - USB_STATUS usb_host__usb_host_ch9_get_interface(_usb_device_instance_handle...
**         _usb_host_ch9_get_status         - USB_STATUS usb_host__usb_host_ch9_get_status(_usb_device_instance_handle...
**         _usb_host_ch9_set_address        - USB_STATUS usb_host__usb_host_ch9_set_address(_usb_device_instance_handle...
**         _usb_host_ch9_set_descriptor     - USB_STATUS usb_host__usb_host_ch9_set_descriptor(_usb_device_instance_handle...
**         _usb_host_ch9_set_interface      - USB_STATUS usb_host__usb_host_ch9_set_interface(_usb_device_instance_handle...
**         _usb_host_ch9_synch_frame        - USB_STATUS usb_host__usb_host_ch9_synch_frame(_usb_device_instance_handle...
**         _usb_hostdev_cntrl_request       - USB_STATUS usb_host__usb_hostdev_cntrl_request(_usb_device_instance_handle...
**         _usb_host_close_pipe             - USB_STATUS usb_host__usb_host_close_pipe(_usb_host_handle hci_handle,...
**         _usb_host_close_all_pipes        - void usb_host__usb_host_close_all_pipes(_usb_host_handle hci_handle);
**         _usb_host_cancel_transfer        - USB_STATUS usb_host__usb_host_cancel_transfer(_usb_host_handle hci_handle,...
**         usb_hostdev_validate             - USB_STATUS usb_host_usb_hostdev_validate(_usb_device_instance_handle...
**         _usb_hostdev_get_buffer          - USB_STATUS usb_host__usb_hostdev_get_buffer(_usb_device_instance_handle...
**         _usb_hostdev_get_descriptor      - USB_STATUS usb_host__usb_hostdev_get_descriptor(_usb_device_instance_handle...
**         _usb_hostdev_find_pipe_handle    - _usb_pipe_handle usb_host__usb_hostdev_...
**         usb_hostdev_get_pipe_handle      - _usb_pipe_handle usb_host_usb_hostdev_get_pipe_handle(PIPE_BUNDLE_STRUCT_PTR...
**         usb_host_class_intf_init         - USB_STATUS usb_host_usb_host_class_intf_init(PIPE_BUNDLE_STRUCT_PTR pbs_ptr,...
**         usb_host_class_intf_validate     - uint_32 usb_host_usb_host_class_intf_validate(void* class_intf_handle);
**         _usb_host_driver_info_register   - USB_STATUS usb_host__usb_host_driver_info_register(_usb_host_handle...
**         _usb_hostdev_select_config       - USB_STATUS usb_host__usb_hostdev_select_config(_usb_device_instance_handle...
**         _usb_hostdev_select_interface    - USB_STATUS usb_host__usb_hostdev_select_interface(_usb_device_instance_handle...
**         usb_dev_list_attach_device       - USB_STATUS usb_host_usb_dev_list_attach_device(_usb_host_handle handle,...
**         usb_hostdev_tr_init              - void usb_host_usb_hostdev_tr_init(TR_INIT_PARAM_STRUCT_PTR tr_ptr,...
**         _usb_host_init                   - USB_STATUS usb_host__usb_host_init(uint_8 devnum, uint_32 frame_list_size,...
**         _usb_host_register_service       - uint_32 usb_host__usb_host_register_service(_usb_host_handle hci_handle,...
**         _usb_host_unregister_service     - uint_32 usb_host__usb_host_unregister_service(_usb_host_handle hci_handle,...
**         _usb_host_open_pipe              - USB_STATUS usb_host__usb_host_open_pipe(_usb_host_handle hci_handle,...
**         _usb_host_send_setup             - uint_32 usb_host__usb_host_send_setup(_usb_host_handle hci_handle,...
**         _usb_host_get_transfer_status    - uint_32 usb_host__usb_host_get_transfer_status(_usb_pipe_handle pipe_handle,...
**         _usb_host_recv_data              - uint_32 usb_host__usb_host_recv_data(_usb_host_handle hci_handle,...
**         _usb_host_shutdown               - void usb_host__usb_host_shutdown(_usb_host_handle hci_handle);
**         _usb_host_get_frame_number       - uint_32 usb_host__usb_host_get_frame_number(_usb_host_handle hci_handle);
**         _usb_host_get_micro_frame_number - uint_32 usb_host__usb_host_get_micro_frame_number(_usb_host_handle hci_handle);
**         _usb_host_send_data              - uint_32 usb_host__usb_host_send_data(_usb_host_handle hci_handle,...
**
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "khci.h"
#include "usbevent.h"
/* MODULE usb_host. */
#include "usb_host.h"
#include "usb_host_hub.h"

extern USB_EVENT_STRUCT khci_event;
/*
** ===================================================================
**     Method      :  usb_host_USB_LDD_OnHostDeviceDeattach (component USB_HOST_STACK)
**
**     Description :
**         Called after the device has been successfully attached (see 
**         OnResetRecovery() event) and the deattach condition is 
**         detected,  OnDeattach() event is enabled and USB module is 
**         enabled. See SetEventMask() and GetEventMask() methods. The 
**         event services the event of the inherited component and 
**         eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnHostDeviceDeattach(LDD_TUserData *UserDataPtr)
{
    _usb_event_set(&khci_event, KHCI_EVENT_RESET);
}

/*
** ===================================================================
**     Method      :  usb_host_USB_LDD_OnHostResetRecovery (component USB_HOST_STACK)
**
**     Description :
**         Called 10 ms later (reset recovery time) after the reset 
**         signaling is stopped, OnResetRecovery() event is enabled and 
**         USB module is enabled. See SetEventMask() and GetEventMask() 
**         methods. As soon as this event is invoked attached device can 
**         be accessed by the SendXX()/RecvXX() methods. The event 
**         services the event of the inherited component and eventually 
**         invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnHostResetRecovery(LDD_TUserData *UserDataPtr, LDD_USB_TBusSpeed CurrentSpeed)
{
    _usb_event_set(&khci_event, KHCI_EVENT_ATTACH);
}

/*
** ===================================================================
**     Method      :  usb_host_USB_LDD_OnHostResumeRecovery (component USB_HOST_STACK)
**
**     Description :
**         Called 10 ms later (resume recovery time) after the resume 
**         signaling is stopped, OnResumeRecovery() event is enabled and 
**         USB module is enabled. See SetEventMask() and GetEventMask() 
**         methods. As soon as this event is invoked attached device can 
**         be accessed by the SendXX()/RecvXX() methods. The event 
**         services the event of the inherited component and eventually 
**         invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnHostResumeRecovery(LDD_TUserData *UserDataPtr)
{
    _usb_event_set(&khci_event, KHCI_EVENT_ATTACH);
}

/*
** ===================================================================
**     Method      :  usb_host_USB_LDD_OnHostError (component USB_HOST_STACK)
**
**     Description :
**         Called after the Error is detected, OnError() event is enabled 
**         and USB module is enabled. See SetEventMask() and 
**         GetEventMask() methods. The event services the event of the 
**         inherited component and eventually invokes other events.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void USB_LDD_OnHostError(LDD_TUserData *UserDataPtr, uint8_t ErrorSource, uint8_t ErrorCode)
{
    /* Write your code here ... */
}

/* END */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
