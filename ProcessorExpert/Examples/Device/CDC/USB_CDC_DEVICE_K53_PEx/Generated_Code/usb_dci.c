/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_dci.c
**     Project   : ProcessorExpert
**     Processor : MK53N512MD100
**     Component : USB_DEVICE_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 09:54, # CodeGen: 14
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include <string.h>
#include <stdlib.h>
#include "usb_dciapi.h" /* USB DCI API Header File */
#include "usb_devapi.h" /* USB Device API Header File */
#include "usb_dci.h"    /* USB DCI Header File */
#include "usb_device.h"

/*****************************************************************************
 * Constant and Macro's - None
 *****************************************************************************/
/****************************************************************************
 * Global Variables
 ****************************************************************************/
uint_8 g_dci_controller_Id;
LDD_USB_Device_TTD              EPDataTDPtr[USB_SERVICE_MAX_EP];
LDD_TDeviceData                 *USBDevDataPtr;
LDD_USB_TSDP                    pSDP;

extern uint_8 g_device_descriptor[18];
/*****************************************************************************
 * Static Variables
 *****************************************************************************/
static BDT_ELEM  g_bdt_elem[MAX_BDT_INDEX >> 1];

/*****************************************************************************
 * Local Types - None
 *****************************************************************************/
/* Internal method prototypes */
static void USB_DCI_SetAddressCallback(LDD_TDeviceData *USBDevDataPtr, LDD_USB_Device_TTD *pTD);
static void USB_DCI_CallBack(LDD_TDeviceData *TDevDataPtr, LDD_USB_Device_TTD *pTD);
static uint_8 USB_DCI_Get_BDT_Index(uint_8 ep_num, uint_8 direction, boolean odd);
static uint_8 USB_DCI_Validate_Param(uint_8 ep_num, uint_8 direction, boolean odd);

/*
** ===================================================================
**     Method      :  USB_DCI_CallBack (component USB_DEVICE_STACK)
**
**     Description :
**         This function is callback function of endpoints
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_DCI_CallBack(LDD_TDeviceData *TDevDataPtr, LDD_USB_Device_TTD *pTD)
{
    if(pTD->Head.EpNum != 0)
    {
        USB_DEV_EVENT_STRUCT      event;
        event.len                 = pTD->TransmittedDataSize;
        event.controller_ID       = g_dci_controller_Id;
        event.setup               = TRUE;
        event.buffer_ptr          = pTD->Head.BufferPtr;
        event.errors              = NO_ERRORS;
        event.ep_num              = pTD->Head.EpNum;
        /* Call service */
        (void)USB_Device_Call_Service(event.ep_num, &event);
    }
}

/*
** ===================================================================
**     Method      :  USB_DCI_SetAddressCallback (component USB_DEVICE_STACK)
**
**     Description :
**         This function is callback function of set address request
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void USB_DCI_SetAddressCallback(LDD_TDeviceData *USBDevDataPtr, LDD_USB_Device_TTD *pTD)
{
    USB_LDD_DeviceSetAddress(USBDevDataPtr,(uint8_t )pTD->ParamPtr);
}

/*
** ===================================================================
**     Method      :  USB_DCI_Get_BDT_Index (component USB_DEVICE_STACK)
**
**     Description :
**         This function returns BDT Index from Endpoint number, 
**         direction, odd/even buffer
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_DCI_Get_BDT_Index (uint_8 ep_num, uint_8 direction, boolean odd)
{
    uint_8 bdt_index = INVALID_BDT_INDEX;

    if(ep_num < MAX_SUPPORTED_ENDPOINTS)
    {
        /* per endpoint 4 bdt_index -- 2 for recv 2 for send */
        bdt_index=(uint_8)((ep_num * 4) + (uint_8)odd);

        if(direction == USB_SEND)
        {
            bdt_index += 2;
        }
    }
    return bdt_index;
}

/*
** ===================================================================
**     Method      :  USB_DCI_Validate_Param (component USB_DEVICE_STACK)
**
**     Description :
**         This function validates endpoint parameters and returns bdt 
**         index
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static uint_8 USB_DCI_Validate_Param (uint_8 ep_num, uint_8 direction, boolean odd)
{
    /* Get bdt index mapped to endpoint number-direction and odd/even buffer */
    uint_8 bdt_index = USB_DCI_Get_BDT_Index(ep_num, direction, odd);

    if((bdt_index  != INVALID_BDT_INDEX) &&
        (g_bdt_elem[TRANSFER_INDEX(bdt_index)].len ==
        (uint_16)UNINITIALISED_VAL))
    {
        /* Incase length in bdt_elem is uninitialised return invalid index */
        bdt_index = INVALID_BDT_INDEX;
    }
    return bdt_index;
}

 /*****************************************************************************
 * Local Functions
 *****************************************************************************/
/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Bus_Reset_Handler (component USB_DEVICE_STACK)
**
**     Description :
**         This functions is called when USB Bus Reset event is
**         received on USB Bus.This function clears all the errors
**         conditions and reinit Global data structures. Also resets
**         USB device controller.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void USB_DCI_Bus_Reset_Handler(void)
{

}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_OnDeviceSpeedDetect (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called after the device detects bus speed
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - User data pointer. This
**                           pointer is passed as the parameter of init
**                           method
**         CurrentSpeed    - Current device speed
**     Returns     : Nothing
** ===================================================================
*/
void USB_DCI_OnDeviceSpeedDetect(LDD_TUserData *UserDataPtr, LDD_USB_TBusSpeed CurrentSpeed)
{
    USB_DEV_EVENT_STRUCT event;
    /* initialize event structure */
    event.controller_ID      = g_dci_controller_Id;
    event.setup              = FALSE;
    event.buffer_ptr         = NULL;
    event.len                = 0;
    event.errors             = NO_ERRORS;
    event.ep_num             = (uint_8)UNINITIALISED_VAL;
    /* call service */
    USB_Device_Call_Service(USB_SERVICE_BUS_RESET, &event);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_OnDeviceSuspend (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called after the suspend condition is met
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - User data pointer. This
**                           pointer is passed as the parameter of init
**                           method
**     Returns     : Nothing
** ===================================================================
*/
void USB_DCI_OnDeviceSuspend(LDD_TUserData *UserDataPtr)
{
    USB_DEV_EVENT_STRUCT event;
    /* initialize event structure */
    event.controller_ID      = g_dci_controller_Id;
    event.setup              = FALSE;
    event.buffer_ptr         = NULL;
    event.len                = 0;
    event.errors             = NO_ERRORS;
    event.ep_num             = (uint_8)UNINITIALISED_VAL;
    /* call service */
    (void)USB_Device_Call_Service(USB_SERVICE_SLEEP, &event);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_OnDeviceResume (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called after the resume signaling is done
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - User data pointer. This
**                           pointer is passed as the parameter of init
**                           method
**     Returns     : Nothing
** ===================================================================
*/
void USB_DCI_OnDeviceResume(LDD_TUserData *UserDataPtr)
{
    USB_DEV_EVENT_STRUCT event;
    /* initialize event structure */
    event.controller_ID      = g_dci_controller_Id;
    event.setup              = FALSE;
    event.buffer_ptr         = NULL;
    event.len                = 0;
    event.errors             = NO_ERRORS;
    event.ep_num             = (uint_8)UNINITIALISED_VAL;
    /* call service */
    (void)USB_Device_Call_Service(USB_SERVICE_RESUME, &event);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_OnDeviceSetupPacket (component USB_DEVICE_STACK)
**
**     Description :
**         This function called after the setup packet is received into
**         the internal buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - User data pointer. This
**                           pointer is passed as the parameter of init
**                           method
**         EpNum           - Endpoint number
**     Returns     : Nothing
** ===================================================================
*/
void USB_DCI_OnDeviceSetupPacket(LDD_TUserData *UserDataPtr, uint8_t EpNum)
{
    USB_DEV_EVENT_STRUCT event;
    USB_LDD_DeviceReadSetupData(USBDevDataPtr, EpNum,&pSDP);
    /* initialize event structure */
    event.controller_ID      = g_dci_controller_Id;
    event.buffer_ptr         = (uint_8 *)&pSDP;
    event.len                = pSDP.wLength;
    event.errors             = NO_ERRORS;
    event.ep_num             = EpNum;
    event.direction          = USB_RECV;
    switch ((pSDP.bRequest << 8U) | pSDP.bmRequestType)
    {
        case STD_SET_ADDRESS:
            EPDataTDPtr[EpNum].Head.Flags         = LDD_USB_DEVICE_TRANSFER_FLAG_EXT_PARAM;
            EPDataTDPtr[EpNum].CallbackFnPtr      = &USB_DCI_SetAddressCallback;
            EPDataTDPtr[EpNum].ParamPtr           = (uint8_t*)(pSDP.wValue);
            event.setup = TRUE;
            /* call service */
            (void)USB_Device_Call_Service(EpNum, &event);
            event.setup = FALSE;
            /* call service */
            (void)USB_Device_Call_Service(EpNum, &event);
            break;
        default:
            if((pSDP.bmRequestType == USB_DCI_SET_REQUEST_ITF)||
               (pSDP.bmRequestType == USB_DCI_SET_REQUEST_EP))
            {
                    event.setup = TRUE;
                (void)USB_Device_Call_Service(EpNum, &event);
                if(pSDP.wLength > 0)
                {
                        event.setup = FALSE;
                        (void)USB_Device_Call_Service(EpNum, &event);
                }
            }
            else
            {
                event.setup = TRUE;
                /* call service */
                (void)USB_Device_Call_Service(EpNum, &event);
            }
            break;
    }
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_OnDeviceError (component USB_DEVICE_STACK)
**
**     Description :
**         This function is called after the Error is detected
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - User data pointer. This
**                           pointer is passed as the parameter of init
**                           method
**         ErrorSource     - Error code. HW specific
**         ErrorCode       - Error code
**     Returns     : Nothing
** ===================================================================
*/
void USB_DCI_OnDeviceError(LDD_TUserData *UserDataPtr, uint8_t ErrorSource, uint8_t ErrorCode)
{
    USB_DEV_EVENT_STRUCT event;
    /* initialize event structure */
    event.controller_ID      = g_dci_controller_Id;
    event.setup              = FALSE;
    event.buffer_ptr         = NULL;
    event.len                = 0;
    event.errors             = ErrorCode;
    event.ep_num             = (uint_8)UNINITIALISED_VAL;
    /* call service */
    (void)USB_Device_Call_Service(USB_SERVICE_ERROR, &event);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Init (component USB_DEVICE_STACK)
**
**     Description :
**         This function initializes the Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_DCI_Init(uint_8 controller_ID)
{
    /* save the controller_ID for future use*/
    g_dci_controller_Id = controller_ID;
    /* USB LDD init */
    USBDevDataPtr = USB_LDD_Init(NULL);
    (void)USB_LDD_Enable(USBDevDataPtr);
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_DeInit (component USB_DEVICE_STACK)
**
**     Description :
**         This function de-initializes the Controller layer
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
uint_8  USB_DCI_DeInit(void)
{
    USB_LDD_Deinit(USBDevDataPtr);
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Init_EndPoint (component USB_DEVICE_STACK)
**
**     Description :
**         This function initializes an endpoint and the Bufffer
**         Descriptor Table entry associated with it. Incase the input
**         parameters are invalid it will return USBERR_EP_INIT_FAILED
**         error.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         ep_ptr          - [IN] Pointer to Endpoint structure
**         flag            - [IN] Zero Termination
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_DCI_Init_EndPoint(uint_8 controller_ID, USB_EP_STRUCT_PTR ep_ptr, boolean flag)
{
    if(ep_ptr->ep_num == CONTROL_ENDPOINT)
    {
        if(ERR_OK != USB_LDD_DeviceInitEndpoint(USBDevDataPtr,(LDD_USB_TEpDescriptor *)&g_device_descriptor, (uint8_t)0))
            return USBERR_EP_INIT_FAILED;
    }
    else
    {
        uint_8 bdtmap_index;
        uint_8 bdtelem_index;
        P_BDT_ELEM bdt_elem;
        LDD_USB_TEpDescriptor EpDescriptorPtr;
        /* Get the bdt index correspoding to the endpoint */
        bdtmap_index = USB_DCI_Get_BDT_Index(ep_ptr->ep_num, ep_ptr->direction,USB_RAM_EVEN_BUFFER);
        bdtelem_index = (uint_8)TRANSFER_INDEX(bdtmap_index);
        bdt_elem = &g_bdt_elem[bdtelem_index];

        /* update bdt element structure */
        bdt_elem->len = (uint_16)ep_ptr->size;
        bdt_elem->app_buffer = (uint_8*)malloc(ep_ptr->size);

        EpDescriptorPtr.wMaxPacketSize = ep_ptr->size;
        EpDescriptorPtr.bmAttributes   = ep_ptr->type;
        EpDescriptorPtr.bEndpointAddress = (ep_ptr->direction)<<7|ep_ptr->ep_num;
        if(ERR_OK != USB_LDD_DeviceInitEndpoint(USBDevDataPtr,&EpDescriptorPtr,0x00U))
        return USBERR_EP_INIT_FAILED;
        EPDataTDPtr[ep_ptr->ep_num].CallbackFnPtr          = USB_DCI_CallBack;
        if(ep_ptr->direction == USB_RECV)
        {
            EPDataTDPtr[ep_ptr->ep_num].Head.EpNum         = ep_ptr->ep_num;
            EPDataTDPtr[ep_ptr->ep_num].Head.BufferPtr     = bdt_elem->app_buffer;
            EPDataTDPtr[ep_ptr->ep_num].Head.BufferSize    = ep_ptr->size;
            EPDataTDPtr[ep_ptr->ep_num].Head.Flags         = LDD_USB_DEVICE_TRANSFER_FLAG_EXT_PARAM;
            EPDataTDPtr[ep_ptr->ep_num].TransferState      = LDD_USB_TRANSFER_NONE;
            USB_LDD_DeviceRecvData(USBDevDataPtr,&EPDataTDPtr[ep_ptr->ep_num]);
        }
    }
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Cancel_Transfer (component USB_DEVICE_STACK)
**
**     Description :
**         This function cancels any pending Transfers which ahve not
**         been sent
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number
**         direction       - [IN] Endpoint direction
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8  USB_DCI_Cancel_Transfer(_usb_device_handle handle, uint_8 endpoint_number, uint_8 direction)
{
    if(ERR_OK != USB_LDD_DeviceCancelTransfer(USBDevDataPtr, endpoint_number, direction<<7))
                return USBERR_NOT_SUPPORTED;
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Deinit_EndPoint (component USB_DEVICE_STACK)
**
**     Description :
**         This function un-intializes the endpoint by clearing the
**         corresponding endpoint control register and then clearing
**         the bdt elem.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         ep_num          - [IN] Endpoint number
**         direction       - [IN] Endpoint direction
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_DCI_Deinit_EndPoint(uint_8 controller_ID, uint_8 ep_num, uint_8 direction)
{
    if(ERR_OK != USB_LDD_DeviceDeinitEndpoint(USBDevDataPtr,ep_num,direction<<7))
        return USBERR_EP_DEINIT_FAILED;
    return USB_OK;
}


/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Stall_EndPoint (component USB_DEVICE_STACK)
**
**     Description :
**         This function stalls the endpoint by setting Endpoint BDT
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number to stall
**         direction       - [IN] Direction to stall
**     Returns     : Nothing
** ===================================================================
*/
void  USB_DCI_Stall_EndPoint(_usb_device_handle handle, uint_8 endpoint_number, uint_8 direction)
{
    USB_LDD_DeviceStallEndpoint(USBDevDataPtr, endpoint_number, direction<<7);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Unstall_EndPoint (component USB_DEVICE_STACK)
**
**     Description :
**         This function unstalls the endpoint by clearing Endpoint
**         Control Register and BDT
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number to unstall
**         direction       - [IN] Direction to unstall
**     Returns     : Nothing
** ===================================================================
*/
void  USB_DCI_Unstall_EndPoint(_usb_device_handle handle, uint_8 endpoint_number, uint_8 direction)
{
    USB_LDD_DeviceUnstallEndpoint(USBDevDataPtr, endpoint_number, direction<<7);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Get_Setup_Data (component USB_DEVICE_STACK)
**
**     Description :
**         This function copies Setup Packet from USB RAM to
**         application buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number for the transaction
**         buffer_ptr      - [IN] Pointer to the buffer
**                           into which to read data
**     Returns     : Nothing
** ===================================================================
*/
void  USB_DCI_Get_Setup_Data(_usb_device_handle handle, uint_8 endpoint_number, uint_8_ptr buffer_ptr)
{
    USB_LDD_DeviceReadSetupData(USBDevDataPtr,endpoint_number,&pSDP);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Get_Transfer_Status (component USB_DEVICE_STACK)
**
**     Description :
**         This function retrieves the transfer status of the endpoint
**         by checking the BDT as well as the endpoint control register
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number for the transaction
**         buffer_ptr      - [IN] Endpoint direction
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_DCI_Get_Transfer_Status(_usb_device_handle handle, uint_8 endpoint_number, uint_8 direction)
{
  return USB_LDD_DeviceGetTransferStatus(USBDevDataPtr,endpoint_number,direction<<7);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Recv_Data (component USB_DEVICE_STACK)
**
**     Description :
**         This function retrieves data received data on a RECV
**         endpoint by copying it from USB RAM to application buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number for the transaction 
**         buffer_ptr      - [OUT] Pointer to the buffer
**                           into which to receive data
**         size            - [IN] Number of bytes to receive
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_DCI_Recv_Data(_usb_device_handle handle, uint_8 endpoint_number, uchar_ptr buffer_ptr, uint_32 size)
{
    /* Size is zero */
    if(size == 0)
    {
        uint_8 bdt_index = USB_DCI_Validate_Param (endpoint_number, USB_RECV,
                USB_RAM_EVEN_BUFFER);
        P_BDT_ELEM bdt_elem = &g_bdt_elem[TRANSFER_INDEX(bdt_index)];

        EPDataTDPtr[endpoint_number].Head.Flags       = LDD_USB_DEVICE_TRANSFER_FLAG_EXT_PARAM;
        EPDataTDPtr[endpoint_number].TransferState    = LDD_USB_TRANSFER_NONE;
        EPDataTDPtr[endpoint_number].Head.EpNum       = endpoint_number;
        EPDataTDPtr[endpoint_number].Head.BufferPtr   = bdt_elem->app_buffer;
        EPDataTDPtr[endpoint_number].Head.BufferSize  = bdt_elem->len;
        if(ERR_OK != USB_LDD_DeviceRecvData(USBDevDataPtr,&EPDataTDPtr[endpoint_number]))
            return USBERR_RX_FAILED;
        return USB_OK;
    }

    /* Size is not zero */
    EPDataTDPtr[endpoint_number].Head.Flags           = LDD_USB_DEVICE_TRANSFER_FLAG_EXT_PARAM;
    EPDataTDPtr[endpoint_number].TransferState        = LDD_USB_TRANSFER_NONE;
    EPDataTDPtr[endpoint_number].Head.EpNum           = endpoint_number;
    EPDataTDPtr[endpoint_number].Head.BufferPtr       = buffer_ptr;
    EPDataTDPtr[endpoint_number].Head.BufferSize      = size;
    if(ERR_OK != USB_LDD_DeviceRecvData(USBDevDataPtr,&EPDataTDPtr[endpoint_number]))
        return USBERR_RX_FAILED;
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Send_Data (component USB_DEVICE_STACK)
**
**     Description :
**         This function configures Controller to send data on an SEND
**         endpoint by setting the BDT to send data.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         endpoint_number - [IN] Endpoint
**                           number
**         buffer_ptr      - [IN] Application buffer
**                           pointer
**         size            - [IN] Size of the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 USB_DCI_Send_Data(_usb_device_handle handle, uint_8 endpoint_number, uchar_ptr buffer_ptr, uint_32 size)
{
    EPDataTDPtr[endpoint_number].Head.EpNum      = endpoint_number;
    EPDataTDPtr[endpoint_number].Head.BufferSize = size;
    EPDataTDPtr[endpoint_number].Head.BufferPtr  = buffer_ptr;
    EPDataTDPtr[endpoint_number].Head.Flags = LDD_USB_DEVICE_TRANSFER_FLAG_EXT_PARAM;
    if(ERR_OK !=USB_LDD_DeviceSendData(USBDevDataPtr,&EPDataTDPtr[endpoint_number]))
        return USBERR_TX_FAILED;
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Set_Address (component USB_DEVICE_STACK)
**
**     Description :
**         This function configures Controller to send data on an SEND
**         endpoint
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**         address         - [IN] Address of the USB device
**     Returns     : Nothing
** ===================================================================
*/
void  USB_DCI_Set_Address(_usb_device_handle handle, uint_8 address)
{
    UNUSED(handle);
    _usb_device_set_status(&g_dci_controller_Id, USB_STATUS_DEVICE_STATE,
        USB_STATE_ADDRESS);
}

/*
** ===================================================================
**     Method      :  usb_device_USB_DCI_Assert_Resume (component USB_DEVICE_STACK)
**
**     Description :
**         This function starts RESUME signalling and then stops it
**         after some delay. In this delay make sure that COP is reset.
**     Parameters  :
**         NAME            - DESCRIPTION
**         handle          - [IN] USB Device handle
**     Returns     : Nothing
** ===================================================================
*/
void USB_DCI_Assert_Resume(_usb_device_handle handle)
{
    (void)USB_LDD_DeviceAssertResume(USBDevDataPtr);
}

/*
** ===================================================================
**     Method      :  usb_device_Clear_Mem (component USB_DEVICE_STACK)
**
**     Description :
**         This function clears memory starting from start_addr till
**         count bytes
**     Parameters  :
**         NAME            - DESCRIPTION
**         start_addr      - [OUT] Buffer Start address
**         count           - [IN] Count of Bytes
**         val             - [IN] Value to be set
**     Returns     : Nothing
** ===================================================================
*/
void Clear_Mem(uint_8_ptr start_addr, uint_32 count, uint_8 val)
{
    (void)memset(start_addr, val, count);
    return;
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

