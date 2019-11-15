/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : khci.c
**     Project   : ProcessorExpert
**     Processor : MK53N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-03-04, 16:56, # CodeGen: 5
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

/******************************************************************************
* Includes
*****************************************************************************/
#include "usbmsgq.h"
#include "usbevent.h"
#include "khci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO_Map.h"
#include "poll.h"
#include "Events.h"
#include "usb_host.h"
#include "USB_LDD.h"
/*****************************************************************************
* Constant and Macro's - None
*****************************************************************************/

/*****************************************************************************
* Global Functions Prototypes
*****************************************************************************/
extern USB_HOST_STATE_STRUCT_PTR usb_host_state_struct_ptr;
USB_STATUS    _usb_khci_init(_usb_host_handle handle);
USB_STATUS    _usb_khci_shutdown(_usb_host_handle handle);
USB_STATUS    _usb_khci_send(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr, PIPE_TR_STRUCT_PTR pipe_tr_ptr);
USB_STATUS    _usb_khci_send_setup(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr, PIPE_TR_STRUCT_PTR pipe_tr_ptr);
USB_STATUS    _usb_khci_recv(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr, PIPE_TR_STRUCT_PTR pipe_tr_ptr);
USB_STATUS    _usb_khci_cancel(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr, PIPE_TR_STRUCT_PTR pipe_tr_ptr);
USB_STATUS    _usb_khci_bus_control(_usb_host_handle handle, uint_8 bus_control);
uint_32       _usb_khci_get_frame_number(_usb_host_handle handle);
USB_STATUS    _usb_khci_host_open_pipe(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr);
USB_STATUS    _usb_khci_host_close_pipe(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr);
USB_STATUS    _usb_khci_host_update_device(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr);
/****************************************************************************
* Global Variables - None
****************************************************************************/
/* KHCI events */
/* KHCI events */
USB_EVENT_STRUCT khci_event;
/* Transaction queue */
USBMSGQ_STRUCT tr_que;
/*****************************************************************************
* Local Types - None
*****************************************************************************/

/*****************************************************************************
* Local Functions Prototypes
*****************************************************************************/
static void   _usb_khci_process_tr_complete(_usb_host_handle handle, PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr, PIPE_TR_STRUCT_PTR pipe_tr_ptr, uint_32 remain, int_32 err);
static int_32 _usb_khci_get_hot_int_tr(TR_MSG_STRUCT *msg);
/*****************************************************************************
* Local Variables
*****************************************************************************/
static PIPE_DESCRIPTOR_STRUCT_PTR last_to_pipe = NULL;
static TR_INT_QUE_ITM_STRUCT TR_INT_QUE[USBCFG_KHCI_MAX_INT_TR];
static LDD_TDeviceData  *USB_LDD_DevDataPtr;
/*****************************************************************************
* Function implementation
*****************************************************************************/
/* Call interface table */
const USB_HOST_CALLBACK_FUNCTIONS_STRUCT _bsp_usb_host_callback_table = {
    /* The Host/Device init function */
    _usb_khci_init,
    /* The function to shutdown the host/device */
    _usb_khci_shutdown,
    /* The function to send data */
    _usb_khci_send,
    /* The function to send setup data */
    _usb_khci_send_setup,
    /* The function to receive data */
    _usb_khci_recv,
    /* The function to cancel the transfer */
    _usb_khci_cancel,
    /* The function for USB bus control */
    _usb_khci_bus_control,
    NULL,
    /* The function to close pipe */
    _usb_khci_host_close_pipe,
    /* Get frame number function */
    _usb_khci_get_frame_number,
    /* Get microframe number function - not applicable on FS */
    NULL,
    /* Open pipe function */
    _usb_khci_host_open_pipe,
    _usb_khci_host_update_device,
    _usb_khci_host_update_device
};
/*
** ===================================================================
**     Method      :  _usb_khci_init_int_tr (component USB_HOST_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void _usb_khci_init_int_tr(void)
{
    uint_32 i;
    TR_INT_QUE_ITM_STRUCT_PTR tr = TR_INT_QUE;

    for (i = 0; i < USBCFG_KHCI_MAX_INT_TR; i++, tr++)
    {
        tr->msg.type = TR_MSG_UNKNOWN;
    }
}

/*
** ===================================================================
**     Method      :  _usb_khci_add_int_tr (component USB_HOST_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static int_32 _usb_khci_add_int_tr
(
/* [IN] Pointer to message */
TR_MSG_STRUCT *msg,
/* Not use */
uint_32 period)
{
    int_32 i = 0;
    TR_INT_QUE_ITM_STRUCT_PTR tr = TR_INT_QUE;

    UNUSED(period)
    /* Find free position */
    for (i = 0; i < USBCFG_KHCI_MAX_INT_TR; i++, tr++)
    {
        if (tr->msg.type == TR_MSG_UNKNOWN)
        {
            memcpy(&tr->msg, msg,  sizeof(TR_MSG_STRUCT));
            break;
        }
    }
    return (i < USBCFG_KHCI_MAX_INT_TR) ? i : -1;
}

/*
** ===================================================================
**     Method      :  _usb_khci_process_tr_complete (component USB_HOST_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void _usb_khci_process_tr_complete
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descritor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr,
/* [IN] Pipe transfer pointer */
PIPE_TR_STRUCT_PTR pipe_tr_ptr,
/* [IN] remaining bytes */
uint_32 remaining_bytes,
/* [IN] error */
int_32 err
)
{
    uchar_ptr buffer_ptr = NULL;
    uint_32 total_req_bytes = 0;
    uint_32 status = 0;

    if (err == KHCI_ATOM_TR_STALL)
    status = USBERR_ENDPOINT_STALLED;
    else if ((err == KHCI_ATOM_TR_NAK) || (err >= 0)) {
        status = USB_OK;

        if ((remaining_bytes > 0) || (err == KHCI_ATOM_TR_NAK)) /* remaining bytes */
        status = USBERR_TR_FAILED;

        if (pipe_desc_ptr->PIPETYPE == USB_CONTROL_PIPE) {
            if (pipe_tr_ptr->SEND_PHASE) {
                total_req_bytes = pipe_tr_ptr->TX_LENGTH;
                buffer_ptr = pipe_tr_ptr->TX_BUFFER;
                pipe_tr_ptr->SEND_PHASE = FALSE;
            }
            else {
                total_req_bytes = pipe_tr_ptr->RX_LENGTH;
                buffer_ptr = pipe_tr_ptr->RX_BUFFER;
            }
        }
        else {
            if (pipe_desc_ptr->DIRECTION) {
                total_req_bytes = pipe_tr_ptr->TX_LENGTH;
                buffer_ptr = pipe_tr_ptr->TX_BUFFER;
            }
            else {
                total_req_bytes = pipe_tr_ptr->RX_LENGTH;
                buffer_ptr = pipe_tr_ptr->RX_BUFFER;
            }
        }
    }
    else if (err < 0)
    status = USBERR_TR_FAILED;

    pipe_tr_ptr->status = USB_STATUS_IDLE;
    pipe_tr_ptr->TR_INDEX = 0;

    if (pipe_tr_ptr->status == USB_STATUS_IDLE) {
        /* Transfer done. Call the callback function for this
        ** transaction if there is one (usually true).
        */
        if (pipe_tr_ptr->CALLBACK != NULL) {
            pipe_tr_ptr->CALLBACK((pointer)pipe_desc_ptr, pipe_tr_ptr->CALLBACK_PARAM,
            buffer_ptr, (total_req_bytes - remaining_bytes), status);

            /* If the application enqueued another request on this pipe
            ** in this callback context then it will be at the end of the list
            */
        }
    }
}

/*
** ===================================================================
**     Method      :  _usb_khci_rm_int_tr (component USB_HOST_STACK)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static int _usb_khci_rm_int_tr
(
/* [IN] Pointer to message */
TR_MSG_STRUCT *msg
)
{
    int_32 i = 0;
    TR_INT_QUE_ITM_STRUCT_PTR tr = TR_INT_QUE;

    /* find record */
    for (i = 0; i < USBCFG_KHCI_MAX_INT_TR; i++, tr++)
    {
        if ((tr->msg.pipe_desc == msg->pipe_desc) && (tr->msg.pipe_tr == msg->pipe_tr))
        {
            tr->msg.type = TR_MSG_UNKNOWN;
            return 0;
        }

    }

    return -1;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_init
*  Returned Value : error or USB_OK
*  Comments       :
*        Initialize the kirin HCI controller
*END*-----------------------------------------------------------------*/
USB_STATUS _usb_khci_init
(
/* [IN] the USB Host state structure */
_usb_host_handle handle
)
{
    USB_STATUS status = USB_OK;
    UNUSED(handle)
    USB_LDD_DevDataPtr = USB_LDD_Init(NULL);         /* Initialize Device LLD */
    USB_LDD_Enable(USB_LDD_DevDataPtr);
    if (_usb_msgq_init(USBCFG_KHCI_TR_QUE_MSG_CNT, sizeof(TR_MSG_STRUCT)/sizeof(uint_32)) != USB_MSGQ_OK)
    {
        /* usb_msgq_init failed */
        return USBERR_INIT_FAILED;
    }
    _usb_event_init(&khci_event);
    _usb_khci_init_int_tr();
    /* Register polling function */
    POLL_register((POLL_POINTER)_usb_khci_task);
    return status;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_shutdown - NOT IMPLEMENT YET
*  Returned Value : error or USB_OK
*  Comments       :
*        The function to shutdown the host
*END*-----------------------------------------------------------------*/
USB_STATUS _usb_khci_shutdown
(
/* [IN] the USB Host state structure */
_usb_host_handle handle
)
{
    UNUSED(handle)
    USB_LDD_Deinit(USB_LDD_DevDataPtr);
    return USB_OK;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_send
*  Returned Value : error or USB_OK
*  Comments       :
*        The function to send data
*END*-----------------------------------------------------------------*/
USB_STATUS _usb_khci_send
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descriptor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr,
/* [IN] Pipe transfer pointer */
PIPE_TR_STRUCT_PTR pipe_tr_ptr
)
{
    USB_STATUS status = USB_OK;
    TR_MSG_STRUCT msg;

    UNUSED(handle)

    msg.type = TR_MSG_SEND;
    msg.pipe_desc = pipe_desc_ptr;
    msg.pipe_tr = pipe_tr_ptr;
    _usb_msgq_send((int*)&msg);
    return status;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_cancel
*  Returned Value : error or USB_OK
*  Comments       :
*        The function to cancel the transfer
*END*-----------------------------------------------------------------*/
USB_STATUS _usb_khci_cancel
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descriptor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr,
/* [IN] pipe transfer pointer */
PIPE_TR_STRUCT_PTR pipe_tr_ptr
)
{
    TR_MSG_STRUCT msg;

    UNUSED(handle)
    UNUSED(pipe_desc_ptr)
    UNUSED(pipe_tr_ptr)

    /* remove messages from KHCI msg que */
    while (_usb_msgq_receive((int*)&msg) == USB_MSGQ_OK)
    { /* void */ };
    return USB_OK;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_recv
*  Returned Value : error or USB_OK
*  Comments       :
*        The function to receive data
*END*-----------------------------------------------------------------*/

USB_STATUS _usb_khci_recv
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descriptor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr,
/* [IN] pipe transfer pointer */
PIPE_TR_STRUCT_PTR pipe_tr_ptr
)
{
    USB_STATUS status = USB_OK;
    TR_MSG_STRUCT msg;

    msg.type = TR_MSG_RECV;
    msg.pipe_desc = pipe_desc_ptr;
    msg.pipe_tr = pipe_tr_ptr;
    _usb_msgq_send((int*)&msg);
    return status;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_bus_control
*  Returned Value : error or USB_OK
*  Comments       :
*        The function for USB bus control
*END*-----------------------------------------------------------------*/
USB_STATUS _usb_khci_bus_control
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] bus control */
uint_8 bus_control
)
{
    UNUSED(handle)
    UNUSED(bus_control)
    return USB_OK;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_get_frame_number
*  Returned Value : frame number
*  Comments       :
*        The function to get frame number
*END*-----------------------------------------------------------------*/
uint_32 _usb_khci_get_frame_number
(
/* [IN] the USB Host state structure */
_usb_host_handle handle
)
{
    UNUSED(handle)
    return USB_LDD_HostGetFrameNumber(USB_LDD_DevDataPtr);
}
/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_task
*  Returned Value : none
*  Comments       :
*        KHCI task
*END*-----------------------------------------------------------------*/
void _usb_khci_task(void)

{
    static uint_32 seq_ints = 10;
    static TR_MSG_STRUCT msg;
    static uint_32 remain = 0;
    static int_32 res;
    uint_32 tick = 0;

    USB_STATUS status = USB_OK;
    /* Host transfer handle */
    LDD_USB_Host_TTransferHandle  *TrHandle;
    /* Host transfer state */
    LDD_USB_TTransferState         volatile TrState;
    /* Host transfer transfer descriptor */
    LDD_USB_Host_TTD               TD;

    if (usb_host_state_struct_ptr->DEVICE_LIST_PTR) {

        msg.type = TR_MSG_UNKNOWN;
        /* look for interrupt transaction */
        if ((_usb_khci_get_hot_int_tr(&msg) != 0) || (!seq_ints--)) {
        seq_ints = 10;
        if (_usb_msgq_receive((int *)&msg) == USB_MSGQ_OK)

            if (msg.pipe_desc->PIPETYPE == USB_INTERRUPT_PIPE)
            _usb_khci_add_int_tr(&msg, msg.pipe_desc->INTERVAL);
        }
        if (msg.type != TR_MSG_UNKNOWN) {

            /* evaluate message */
            switch (msg.type) {
            case TR_MSG_SETUP:
                TD.CallbackFnPtr = NULL;
                TD.ParamPtr = msg.pipe_tr->CALLBACK_PARAM;
                TD.SDPPrt = (LDD_USB_TSDP*) malloc(sizeof(LDD_USB_TSDP));
                TD.SDPPrt->bmRequestType = msg.pipe_tr->setup_packet.BMREQUESTTYPE;
                if(TD.SDPPrt->bmRequestType & REQ_TYPE_IN)    {  /* get request */
                    TD.BufferPtr = msg.pipe_tr->RX_BUFFER;
                    TD.BufferSize = msg.pipe_tr->RX_LENGTH;
                } else {                                         /* set request */
                    TD.BufferPtr = msg.pipe_tr->TX_BUFFER;
                    TD.BufferSize = msg.pipe_tr->TX_LENGTH;
                }
                TD.SDPPrt->bRequest = msg.pipe_tr->setup_packet.BREQUEST;
                #ifdef MCU_MKL25Z4
                memcpy(&TD.SDPPrt->wIndex, &msg.pipe_tr->setup_packet.WINDEX[0],2);
                memcpy(&TD.SDPPrt->wLength, &msg.pipe_tr->setup_packet.WLENGTH[0],2);
                memcpy(&TD.SDPPrt->wValue, &msg.pipe_tr->setup_packet.WVALUE[0],2);
                #else
                TD.SDPPrt->wIndex = (uint_16)*(uint_16*)&(msg.pipe_tr->setup_packet.WINDEX[0]);
                TD.SDPPrt->wLength = (uint_16)*(uint_16*)&(msg.pipe_tr->setup_packet.WLENGTH[0]);
                TD.SDPPrt->wValue = (uint_16)*(uint_16*)&(msg.pipe_tr->setup_packet.WVALUE[0]);
                #endif
                /* call the USB LDD function */
                status = USB_LDD_HostSendSetup(USB_LDD_DevDataPtr, (LDD_USB_Host_TPipeHandle *)msg.pipe_desc->ep_ptr, &TD, &TrHandle);
                if (status != ERR_OK) {
                    res = KHCI_ATOM_TR_NAK;
                    remain = TD.BufferSize;
                    free(TD.SDPPrt);
                break;
                }
                do {
                    /* Wait for setup transfer done */
                    TrState = USB_LDD_HostGetTransferStatus(USB_LDD_DevDataPtr, TrHandle);
                    tick ++;
                } while ((TrState >= LDD_USB_TRANSFER_QUEUED)&&(tick <KHCI_TICK_WAIT));

                if(tick >= KHCI_TICK_WAIT){
                    res = KHCI_ATOM_TR_NAK;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_STALLED)
                {
                    res = KHCI_ATOM_TR_STALL;
                    remain = TD.BufferSize;
                }
                else if((TrState >= LDD_USB_TRANSFER_ERROR_PID) && (TrState <= LDD_USB_TRANSFER_ERROR))
                {
                    res = -TrState;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_DATA){
                    res = KHCI_ATOM_TR_DATA_ERROR;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_BUS_TIMEOUT){
                    res = KHCI_ATOM_TR_TO;
                    remain = TD.BufferSize;
                }
                else{
                    res = 0;
                    remain = 0;
                }
                free(TD.SDPPrt);
                tick = 0;
                break;

            case TR_MSG_RECV:

                TD.BufferPtr = msg.pipe_tr->RX_BUFFER;
                TD.BufferSize = msg.pipe_tr->RX_LENGTH;
                TD.CallbackFnPtr = NULL;
                TD.ParamPtr = msg.pipe_tr->CALLBACK_PARAM;
                TD.SDPPrt = NULL;
                /* call the USB LDD function */
                status = USB_LDD_HostRecvData(USB_LDD_DevDataPtr, (LDD_USB_Host_TPipeHandle *)msg.pipe_desc->ep_ptr, &TD, &TrHandle);
                if (status != ERR_OK) {
                    res = KHCI_ATOM_TR_NAK;
                    remain = TD.BufferSize;
                break;
                }
                do {
                    /* Wait for setup transfer done */
                    TrState = USB_LDD_HostGetTransferStatus(USB_LDD_DevDataPtr, TrHandle);
                    tick ++;
                } while ((TrState >= LDD_USB_TRANSFER_QUEUED)&&(tick <KHCI_TICK_WAIT));

                if(tick >= KHCI_TICK_WAIT){
                    res = KHCI_ATOM_TR_NAK;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_STALLED)
                {
                    res = KHCI_ATOM_TR_STALL;
                    remain = TD.BufferSize;
                }
                else if((TrState >= LDD_USB_TRANSFER_ERROR_PID) && (TrState <= LDD_USB_TRANSFER_ERROR))
                {
                    res = -TrState;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_DATA){
                    res = KHCI_ATOM_TR_DATA_ERROR;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_BUS_TIMEOUT){
                    res = KHCI_ATOM_TR_TO;
                    remain = TD.BufferSize;
                }
                else{
                    res = 0;
                    remain = 0;
                }
                tick = 0;
                break;

            case TR_MSG_SEND:
                TD.BufferPtr = msg.pipe_tr->TX_BUFFER;
                TD.BufferSize = msg.pipe_tr->TX_LENGTH;
                TD.CallbackFnPtr = NULL;
                TD.ParamPtr = msg.pipe_tr->CALLBACK_PARAM;
                TD.SDPPrt = NULL;
                /* call the USB LDD function */
                status = USB_LDD_HostSendData(USB_LDD_DevDataPtr, (LDD_USB_Host_TPipeHandle *)msg.pipe_desc->ep_ptr, &TD, &TrHandle);
                if (status != ERR_OK) {
                    res = KHCI_ATOM_TR_NAK;
                    remain = TD.BufferSize;
                break;
                }
                do {
                    /* Wait for setup transfer done */
                    TrState = USB_LDD_HostGetTransferStatus(USB_LDD_DevDataPtr, TrHandle);
                    tick ++;
                } while ((TrState >= LDD_USB_TRANSFER_QUEUED)&&(tick <KHCI_TICK_WAIT));

                if(tick >= KHCI_TICK_WAIT){
                    res = KHCI_ATOM_TR_NAK;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_STALLED)
                {
                    res = KHCI_ATOM_TR_STALL;
                    remain = TD.BufferSize;
                }
                else if((TrState >= LDD_USB_TRANSFER_ERROR_PID) && (TrState <= LDD_USB_TRANSFER_ERROR))
                {
                    res = -TrState;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_DATA){
                    res = KHCI_ATOM_TR_DATA_ERROR;
                    remain = TD.BufferSize;
                }
                else if(TrState == LDD_USB_TRANSFER_ERROR_BUS_TIMEOUT){
                    res = KHCI_ATOM_TR_TO;
                    remain = TD.BufferSize;
                }
                else{
                    res = 0;
                    remain = 0;
                }
                tick = 0;
                break;
            default:
                break;
            }
            if (res < 0) {
                if (msg.pipe_desc->PIPETYPE != USB_INTERRUPT_PIPE) {    /* TODO enhance condition for error (not NAK) in interrupt transaction */
                    _usb_khci_process_tr_complete((pointer)usb_host_state_struct_ptr, msg.pipe_desc, msg.pipe_tr, remain, res);
                }
            }
            else {
                _usb_khci_process_tr_complete((pointer)usb_host_state_struct_ptr, msg.pipe_desc, msg.pipe_tr, remain, res);

                if (msg.pipe_desc->PIPETYPE == USB_INTERRUPT_PIPE) {
                    _usb_khci_rm_int_tr(&msg);
                }
            }
        }
    }
    if ((khci_event.VALUE & KHCI_EVENT_MASK)) {
        /* some event occurred */
        if (khci_event.VALUE & KHCI_EVENT_ATTACH) {     /* device attached */
            /* speed check, set */
            usb_dev_list_attach_device((pointer)usb_host_state_struct_ptr, (uint_8)(usb_host_state_struct_ptr->speed), 0, 0);
            _usb_event_clear(&khci_event, KHCI_EVENT_ATTACH);
        }

        if (khci_event.VALUE & KHCI_EVENT_RESET) {   /* usb reset */
            /* device detached */
            usb_dev_list_detach_device((pointer)usb_host_state_struct_ptr, 0, 0);
            _usb_event_clear(&khci_event, KHCI_EVENT_RESET | KHCI_EVENT_TOK_DONE);
        }
    }
    return;

}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_send_setup
*  Returned Value :
*  Comments       : Send setup packet
*
*END*------------------------------------------------------------------*/
USB_STATUS _usb_khci_send_setup
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descriptor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr,
/* [IN] pipe transfer pointer */
PIPE_TR_STRUCT_PTR pipe_tr_ptr
)
{
    USB_STATUS status = USB_OK;
    TR_MSG_STRUCT msg;

    msg.type = TR_MSG_SETUP;
    msg.pipe_desc = pipe_desc_ptr;
    msg.pipe_tr = pipe_tr_ptr;
    status = _usb_msgq_send((int*)&msg);
    return status;
}
/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_host_open_pipe
*  Returned Value : error or USB_OK
*  Comments       :
*        The function to open pipe
*END*-----------------------------------------------------------------*/

USB_STATUS _usb_khci_host_open_pipe
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descriptor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr
)
{
    uint_8 res;
    LDD_USB_Host_TPipeDescr        PipeDescr;
    UNUSED(handle)
    /* prepare the Pipe Descriptor structure fields */
    switch(pipe_desc_ptr ->SPEED)
    {
    case USB_SPEED_LOW:
        PipeDescr.DevSpeed = LDD_USB_LOW_SPEED;
        break;
    case USB_SPEED_FULL:
        PipeDescr.DevSpeed = LDD_USB_FULL_SPEED;
        break;
    case USB_SPEED_HIGH:
        PipeDescr.DevSpeed = LDD_USB_HIGH_SPEED;
        break;
    default:
        PipeDescr.DevSpeed = LDD_USB_SPEED_UNKNOWN;
        break;
    }
    PipeDescr.DevAddress = pipe_desc_ptr ->DEVICE_ADDRESS;
    PipeDescr.EpDir = pipe_desc_ptr->DIRECTION;
    PipeDescr.EpNumber = pipe_desc_ptr->ENDPOINT_NUMBER;
    PipeDescr.Flags = pipe_desc_ptr->FLAGS;
    PipeDescr.Interval = pipe_desc_ptr->INTERVAL;
    PipeDescr.MaxPacketSize = pipe_desc_ptr->MAX_PACKET_SIZE;
    PipeDescr.NAKCount = pipe_desc_ptr->NAK_COUNT;
    PipeDescr.TrPerUFrame = pipe_desc_ptr->TRS_PER_UFRAME;
    PipeDescr.TransferType = pipe_desc_ptr->PIPETYPE;
    /* Call the USB LDD function */
    res = USB_LDD_HostOpenPipe(USB_LDD_DevDataPtr, &PipeDescr, (LDD_USB_Host_TPipeHandle **)&(pipe_desc_ptr->ep_ptr));
    return res;

}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_host_update_device
*  Returned Value : error or USB_OK
*  Comments       :
*        The function to reopen the pipe
*END*-----------------------------------------------------------------*/

USB_STATUS _usb_khci_host_update_device
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descriptor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr
)
{
    uint_8 res;
    /* Close current Pipe */
    res = _usb_khci_host_close_pipe(handle,pipe_desc_ptr);
    if (res != ERR_OK) {
        return res;
    }
    /* open new pipe */
    res = _usb_khci_host_open_pipe(handle,pipe_desc_ptr);
    if (res != ERR_OK) {
        return res;
    }
    return res;
}
/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_host_close_pipe
*  Returned Value : error or USB_OK
*  Comments       :
*        The function to close pipe
*END*-----------------------------------------------------------------*/
USB_STATUS _usb_khci_host_close_pipe
(
/* [IN] the USB Host state structure */
_usb_host_handle handle,
/* [IN] pipe descriptor pointer */
PIPE_DESCRIPTOR_STRUCT_PTR pipe_desc_ptr
)
{
    uint_8 res;
    UNUSED(handle);
    if (pipe_desc_ptr->PIPETYPE == USB_INTERRUPT_PIPE)
    {
        uint_16 i;
        TR_INT_QUE_ITM_STRUCT_PTR tr = TR_INT_QUE;

        /* find record */
        for (i = 0; i < USBCFG_KHCI_MAX_INT_TR; i++, tr++)
        {
            if (tr->msg.pipe_desc == pipe_desc_ptr)
            tr->msg.type = TR_MSG_UNKNOWN;
        }
    }
    /* Call the USB LDD function */
    res = USB_LDD_HostClosePipe(USB_LDD_DevDataPtr, (LDD_USB_Host_TPipeHandle *)(pipe_desc_ptr->ep_ptr));
    return res;
}

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : _usb_khci_get_hot_int_tr
*  Returned Value : 0 successful
*  Comments       :
*        Make a message copy for transaction which need evaluation
*END*-----------------------------------------------------------------*/
static int_32 _usb_khci_get_hot_int_tr
(
/* [IN] pointer to message */
TR_MSG_STRUCT *msg
)
{
    int_32 i, res = -1;
    TR_INT_QUE_ITM_STRUCT_PTR tr = TR_INT_QUE;
    TR_INT_QUE_ITM_STRUCT_PTR hot_tr = NULL;

    /* find hottest transaction */
    for (i = 0; i < USBCFG_KHCI_MAX_INT_TR; i++, tr++) {
        if (tr->msg.type != TR_MSG_UNKNOWN){
            hot_tr = tr;
        }
    }
    if (hot_tr) {
        /* test if hottest transaction was not the last one with timeout - if yes, don't allow to block USB transfers with timeouts */
        if (last_to_pipe == hot_tr->msg.pipe_desc) {
            last_to_pipe = NULL; /* it is allowed to perform this interupt next time */
            return res;
        }
        memcpy(msg, &hot_tr->msg,  sizeof(TR_MSG_STRUCT));
        res = 0;
    }
    return res;
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _bsp_usb_host_init
* Returned Value   : 0 for success
* Comments         :
*    This function performs BSP-specific initialization related to USB host
*
*END*----------------------------------------------------------------------*/
int_32 _bsp_usb_host_init(pointer param)
{
    return 0;
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

