/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : usb_cdc.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : USB_CDC_CLASS
**     Version     : Component 01.000, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-11-19, 14:45, # CodeGen: 15
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         usb_class_cdc_init_ipipe             - USB_STATUS usb_cdc_usb_class_cdc_init_ipipe(void* acm_instance);
**         usb_class_cdc_install_driver         - USB_STATUS usb_cdc_usb_class_cdc_install_driver(void* data_instance, void*...
**         _io_cdc_serial_open                  - int_32 usb_cdc__io_cdc_serial_open(FILE_CDC_PTR fd_ptr, char *open_name_ptr,...
**         _io_cdc_serial_read                  - int_32 usb_cdc__io_cdc_serial_read(FILE_CDC_PTR fd_ptr, void* data_ptr, void*...
**         _io_cdc_serial_write                 - int_32 usb_cdc__io_cdc_serial_write(FILE_CDC_PTR fd_ptr, void* data_ptr,...
**         usb_class_cdc_get_ctrl_interface     - CLASS_CALL_STRUCT_PTR usb_cdc_usb_class_cdc_get_ctrl_interface(void*...
**         usb_class_cdc_get_acm_descriptors    - USB_STATUS usb_cdc_usb_class_cdc_get_acm_descriptors(void* dev_handle, void*...
**         usb_class_cdc_set_acm_descriptors    - USB_STATUS usb_cdc_usb_class_cdc_set_acm_descriptors(void* ccs_ptr,...
**         usb_class_cdc_get_ctrl_descriptor    - USB_STATUS usb_cdc_usb_class_cdc_get_ctrl_descriptor(void* dev_handle, void*...
**         usb_class_cdc_bind_data_interfaces   - USB_STATUS usb_cdc_usb_class_cdc_bind_data_interfaces(void* dev_handle, void*...
**         usb_class_cdc_unbind_data_interfaces - USB_STATUS usb_cdc_usb_class_cdc_unbind_data_interfaces(void* ccs_ptr);
**         usb_class_cdc_bind_acm_interface     - USB_STATUS usb_cdc_usb_class_cdc_bind_acm_interface(void* ccs_ptr, void*...
**         usb_class_cdc_unbind_acm_interface   - USB_STATUS usb_cdc_usb_class_cdc_unbind_acm_interface(void* ccs_ptr);
**         usb_class_cdc_get_data_interface     - CLASS_CALL_STRUCT_PTR usb_cdc_usb_class_cdc_get_data_interface(void*...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE usb_cdc. */

#include "usb_cdc.h"