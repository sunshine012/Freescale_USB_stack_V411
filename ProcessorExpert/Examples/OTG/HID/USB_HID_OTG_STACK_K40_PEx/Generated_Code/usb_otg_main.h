/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_otg_main.h
**     Project   : ProcessorExpert
**     Processor : MK40N512MD100
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.003
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef USB_OTG_MAIN_H_
#define USB_OTG_MAIN_H_
#include "USB_LDD.h"
/* Number of available USB device controllers */
#define USB_OTG_DEV_CNT                        1

#if (USB_OTG_DEV_CNT == 0)
#error "USB_OTG_DEV_CNT (number of USB controllers) cannot be configured to 0"
#endif

/* B state machine indications */
#define OTG_B_IDLE                          ERR_USB_OTG_B_IDLE           /* B idle state */
#define OTG_B_IDLE_SRP_READY                ((uint_32)0x0002)     /* B idle, SRP ready to start */
#define OTG_B_SRP_INIT                      ERR_USB_OTG_B_SRP_INIT      /* B srp init state */
#define OTG_B_SRP_FAIL                      ((uint_32)0x0008)     /* B srp failed to get a response */
#define OTG_B_PERIPHERAL                    ERR_USB_OTG_B_PERIPHERAL     /* B peripheral state */
#define OTG_B_PERIPHERAL_LOAD_ERROR         ((uint_32)0x0020)     /* B peripheral state (peripheral stack could not be loaded) */
#define OTG_B_PERIPHERAL_HNP_READY          ((uint_32)0x0040)     /* B peripheral, HNP ready to be performed */
#define OTG_B_PERIPHERAL_HNP_START          ((uint_32)0x0080)     /* B peripheral, HNP start */
#define OTG_B_PERIPHERAL_HNP_FAIL           ((uint_32)0x0100)     /* B peripheral, HNP failed */
#define OTG_B_HOST                          ERR_USB_OTG_B_HOST        /* B host state */
#define OTG_B_HOST_LOAD_ERROR               ((uint_32)0x0400)     /* B host state (host stack could not be loaded) */
#define OTG_B_A_HNP_REQ                     ((uint_32)0x0800)

/* A state machine indications */
#define OTG_A_IDLE                          ERR_USB_OTG_A_IDLE
#define OTG_A_WAIT_VRISE                    ERR_USB_OTG_A_WAIT_VRISE
#define OTG_A_WAIT_BCON                     ERR_USB_OTG_A_WAIT_BCON
#define OTG_A_HOST                          ERR_USB_OTG_A_HOST
#define OTG_A_SUSPEND                       ERR_USB_OTG_A_SUSPEND
#define OTG_A_PERIPHERAL                    ERR_USB_OTG_A_PERIPHERAL
#define OTG_A_WAIT_VFALL                    ERR_USB_OTG_A_WAIT_VFALL
#define OTG_A_VBUS_ERR                      ERR_USB_OTG_A_VBUS_ERROR

#define OTG_A_WAIT_VRISE_TMOUT              ((uint_32)0x01000000)
#define OTG_A_WAIT_BCON_TMOUT               ((uint_32)0x02000000)
#define OTG_A_B_HNP_REQ                     ((uint_32)0x04000000)
#define OTG_A_BIDL_ADIS_TMOUT               ((uint_32)0x08000000)

#define OTG_A_ID_TRUE                       ((uint_32)0x10000000)
#define OTG_A_HOST_LOAD_ERROR               ((uint_32)0x20000000)
#define OTG_A_PERIPHERAL_LOAD_ERROR         ((uint_32)0x40000000)
#define OTG_A_AIDL_BDIS_TMOUT               ((uint_32)0x80000000)

#define OTG_CTRL_PDOWN_DP                   ((uint_8)0x01)
#define OTG_CTRL_PDOWN_DM                   ((uint_8)0x02)

#define OTG_ATTR_SRP_SUPPORT                ((uint_8)0x01)
#define OTG_ATTR_HNP_SUPPORT                ((uint_8)0x02)
/* Public types */
typedef uint_32 OTG_EVENT;
typedef void*   _usb_otg_handle;

/**** Function types for interfacing an external OTG circuit ****/

/* Function for enabling / disabling the external circuit */
typedef void (*otg_ext_enable_disable)(boolean enable);

/* Function for enabling / disabling the VBUS generator*/
typedef void (*otg_ext_set_VBUS)(boolean a_device);

/* Function for getting the status from the external circuit */
typedef uint_8 (*otg_ext_get_status)(void);

/* Function for getting the active interrupts from the external circuit */
typedef uint_8 (*otg_ext_get_interrupts)(void);

/* Function for getting the active interrupts from the external circuit */
typedef void (*otg_ext_set_pdowns)(uint_8 bitfield);

/* Function for getting the active interrupts from the external circuit */
typedef uint_32 (*otg_load_usb_stack)(void);
typedef void (*otg_unload_usb_stack)(void);

/* OTG initialization structure type */
#ifdef __CC_ARM
#pragma push
#pragma pack(1)
#endif
#ifdef __GNUC__
#pragma pack(1)
#endif
typedef struct otg_init_struct
{
    boolean                    ext_circuit_use;
    otg_ext_enable_disable     ext_enable_disable_func;
    otg_ext_get_status         ext_get_status_func;
    otg_ext_get_interrupts     ext_get_interrupts_func;
    otg_ext_set_VBUS           ext_set_VBUS;
    otg_ext_set_pdowns         ext_set_pdowns;
    otg_load_usb_stack         load_usb_host;
    otg_load_usb_stack         load_usb_device;
    otg_unload_usb_stack       unload_usb_host;
    otg_unload_usb_stack       unload_usb_device;
    otg_unload_usb_stack       unload_usb_active;
}OTG_INIT_STRUCT;

typedef void    (*otg_event_callback)(_usb_otg_handle handle, OTG_EVENT event);

/* Internal method prototypes */
/* Public functions */
extern uint_32    _usb_otg_init( uint_8 otg_device_number, OTG_INIT_STRUCT *init_struct, _usb_otg_handle *otg_handle);
extern uint_32    _usb_otg_register_callback(_usb_otg_handle handle, otg_event_callback callback);
extern uint_32    _usb_otg_session_request(_usb_otg_handle handle);
extern uint_32    _usb_otg_bus_request(_usb_otg_handle handle);
extern uint_32    _usb_otg_bus_release(_usb_otg_handle handle);
extern uint_32    _usb_otg_hnp_enable(uint_8 otg_device_number, uint_8 enable);
extern void       _usb_otg_task(void);
extern void       _usb_otg_ext_isr(uint_8 otg_device_number);
extern uint_32    _usb_otg_set_a_bus_req(_usb_otg_handle otg_handle , boolean a_bus_req );
extern uint_32    _usb_otg_set_a_bus_drop(_usb_otg_handle otg_handle , boolean a_bus_drop );
extern uint_32    _usb_otg_set_a_clear_err( _usb_otg_handle otg_handle );
extern uint_32    _usb_otg_a_set_b_hnp_en(void* dev_handle , boolean b_hnp_en);
extern uint_32    _usb_otg_on_interface_event(void*  dev_handle) ;
extern uint_32    _usb_otg_hnp_poll_req (_usb_otg_handle handle) ;
extern uint_32    _usb_otg_on_detach_event(void*  dev_handle) ;
extern uint_32    _usb_otg_get_otg_attribute(void*  dev_handle , uint_8 bm_attributes);
extern uint_8     _usb_otg_set_feature_required(void*  dev_handle );
void MAX3353_GetUsbInputSignal(void);
/*
** ===================================================================
**     Method      :  MAX3353_GetUsbInputSignal (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void MAX3353_SetUsbOutputSignal(LDD_TPinMask SignalMask, LDD_TPinMask SignalValue);
/*
** ===================================================================
**     Method      :  MAX3353_SetUsbOutputSignal (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         SignalMask      - 
**         SignalValue     - 
**     Returns     : Nothing
** ===================================================================
*/

#endif /* USB_OTG_FS_MAIN_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
