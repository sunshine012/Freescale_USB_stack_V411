/** ###################################################################
**     THIS USER MODULE IS GENERATED BY THE TOOL. MODIFY IT FOLLOW COMMENTS BELOW.
**     Filename  : usb_classes.h
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-02, 13:43, # CodeGen: 119
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef __usb_classes_h__
#define __usb_classes_h__
/* End of header definition, DO NOT MODIFY LINES ABOVE */
/* Write your own includes here ...*/

/* DO NOT MODIFY LINES BELOW */
typedef struct {
    GENERAL_CLASS                             G;
/* End <struct_begin_1>, DO NOT MODIFY LINES ABOVE */
/* Write your own fields of struct 1 below */
/* Only 1 command can be issued at one time */
   boolean                                   IN_SETUP;

   /* Here we store callback and parameter from higher level */
   tr_callback                               USER_CALLBACK;
   pointer                                   USER_PARAM;
/* Begin of <struct_end_1>, DO NOT MODIFY LINES BELOW */
} USB_CLASS_HID_MOUSE_INTF_STRUCT, _PTR_ USB_CLASS_HID_MOUSE_INTF_STRUCT_PTR;
/* DO NOT MODIFY LINES ABOVE*/

/* Begin of <fuction_prototype>, DO NOT MODIFY LINES BELOW */
extern void usb_class_hid_mouse_init(PIPE_BUNDLE_STRUCT_PTR, CLASS_CALL_STRUCT_PTR);
/* End <fuction_prototype>, DO NOT MODIFY LINES ABOVE */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

