/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : khci.h
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-12-27, 14:10, # CodeGen: 119
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __khci_h__
#define __khci_h__

#include "usbprv_host.h"

/* KHCI timeout for transfering data with device */
#define KHCI_TICK_WAIT          8000000
#define KHCI_RETRY_NUM          10
/* KHCI event bits */
#define KHCI_EVENT_ATTACH       1
#define KHCI_EVENT_RESET        2
#define KHCI_EVENT_TOK_DONE     4
#define KHCI_EVENT_SOF_TOK      8
#define KHCI_EVENT_MASK         0x0f

/* atom transaction error results */
#define KHCI_ATOM_TR_PID_ERROR  (-1)
#define KHCI_ATOM_TR_EOF_ERROR  (-2)
#define KHCI_ATOM_TR_CRC_ERROR  (-4)
#define KHCI_ATOM_TR_TO         (-16)
#define KHCI_ATOM_TR_DMA_ERROR  (-32)
#define KHCI_ATOM_TR_BTS_ERROR  (-128)
#define KHCI_ATOM_TR_NAK        (-256)
#define KHCI_ATOM_TR_DATA_ERROR (-512)
#define KHCI_ATOM_TR_STALL      (-1024)
#define KHCI_ATOM_TR_RESET      (-2048)

#define USBCFG_KHCI_TR_QUE_MSG_CNT              (10)
#define USBCFG_KHCI_MAX_INT_TR                  (10)

#define MSG_SIZE_IN_MAX_TYPE (1 + (sizeof(TR_MSG_STRUCT) - 1) / sizeof(_mqx_max_type))
typedef enum {
    TR_MSG_UNKNOWN,     /* unknow - not used   */
    TR_MSG_SETUP,       /* setup transaction   */
    TR_MSG_SEND,        /* send trnasaction    */
    TR_MSG_RECV         /* receive transaction */
} TR_MSG_TYPE;

/* atom transaction message */
typedef struct {
    TR_MSG_TYPE type;                       /* transaction type */
    PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc;   /* pointer to pipe descriptor */
    PIPE_TR_STRUCT_PTR pipe_tr;             /* pointer to transaction */
} TR_MSG_STRUCT, _PTR_ TR_MSG_STRUCT_PTR;

/* interrupt transaction */
typedef struct tr_int_que_itm_struct {
    uint_32     period;         /* period in [ms] for interrupt endpoint */
    TR_MSG_STRUCT msg;          /* atom transaction message */
} TR_INT_QUE_ITM_STRUCT, _PTR_ TR_INT_QUE_ITM_STRUCT_PTR;

/* endpoint data structure */
typedef struct {
    uint_8 rx_bd;
    uint_8 tx_bd;
} EP_STRUCT, _PTR_ EP_STRUCT_PTR;

typedef struct usb_host_callback_functions_struct
{
    /* The Host/Device init function */
    USB_STATUS (_CODE_PTR_ HOST_INIT)(_usb_host_handle);

    /* The function to shutdown the host/device */
    USB_STATUS (_CODE_PTR_ HOST_SHUTDOWN)(_usb_host_handle);

    /* The function to send data */
    USB_STATUS (_CODE_PTR_ HOST_SEND)(_usb_host_handle, struct pipe_descriptor_struct _PTR_, struct pipe_tr_struct _PTR_);

    /* The function to send setup data */
    USB_STATUS (_CODE_PTR_ HOST_SEND_SETUP)(_usb_host_handle, struct pipe_descriptor_struct _PTR_, struct pipe_tr_struct _PTR_);

    /* The function to receive data */
    USB_STATUS (_CODE_PTR_ HOST_RECV)(_usb_host_handle, struct pipe_descriptor_struct _PTR_, struct pipe_tr_struct _PTR_);

    /* The function to cancel the transfer */
    USB_STATUS (_CODE_PTR_ HOST_CANCEL)(_usb_host_handle, struct pipe_descriptor_struct _PTR_, struct pipe_tr_struct _PTR_);

    /* The function for USB bus control */
    USB_STATUS (_CODE_PTR_ HOST_BUS_CONTROL)(_usb_host_handle, uint_8);

    uint_32 (_CODE_PTR_ HOST_ALLOC_BANDWIDTH)(_usb_host_handle, struct pipe_descriptor_struct _PTR_);

    USB_STATUS (_CODE_PTR_ HOST_FREE_CONTROLLER_RESOURCE)(_usb_host_handle, struct pipe_descriptor_struct _PTR_);

    uint_32 (_CODE_PTR_ HOST_EHCI_GET_FRAME_NUM)(_usb_host_handle);

    uint_32 (_CODE_PTR_ HOST_EHCI_GET_MICRO_FRAME_NUM)(_usb_host_handle);

    USB_STATUS (_CODE_PTR_ HOST_OPEN_PIPE)(_usb_host_handle, struct pipe_descriptor_struct _PTR_);

    USB_STATUS (_CODE_PTR_ HOST_UPDATE_MAX_PACKET_SIZE)(_usb_host_handle, struct pipe_descriptor_struct _PTR_);

    USB_STATUS (_CODE_PTR_ HOST_UPDATE_DEVICE_ADDRESS)(_usb_host_handle, struct pipe_descriptor_struct _PTR_);

} USB_HOST_CALLBACK_FUNCTIONS_STRUCT,  _PTR_ USB_HOST_CALLBACK_FUNCTIONS_STRUCT_PTR;

extern const USB_HOST_CALLBACK_FUNCTIONS_STRUCT _bsp_usb_host_callback_table;
extern void _usb_khci_task(uint32_t task_init_data);

extern int_32 _bsp_usb_host_init(pointer);

/* scheduling based on time and packet length, not just SOF synchronizing */
#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/


