/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : usb_msc.h
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : USB_MSD_CLASS
**     Version     : Component 01.027, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 11:34, # CodeGen: 25
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         USB_Service_Bulk_In              - void usb_msc_USB_Service_Bulk_In(PTR_USB_DEV_EVENT_STRUCT event);
**         USB_Service_Bulk_Out             - void usb_msc_USB_Service_Bulk_Out(PTR_USB_DEV_EVENT_STRUCT event);
**         USB_Class_MSC_Event              - void usb_msc_USB_Class_MSC_Event(uint_8 controller_ID, uint_8 event, void* val);
**         USB_BYTE_SWAP4                   - void usb_msc_USB_BYTE_SWAP4(uint_32 a, uint_32 *b);
**         USB_memzero                      - void usb_msc_USB_memzero(void* ptr, uint_32 size);
**         USB_memcopy                      - void usb_msc_USB_memcopy(void* src, void* dst, uint_32 size);
**         USB_Class_MSC_Init               - uint_8 usb_msc_USB_Class_MSC_Init(uint_8 controller_ID, USB_CLASS_CALLBACK...
**         USB_Class_MSC_DeInit             - uint_8 usb_msc_USB_Class_MSC_DeInit(uint_8 controller_ID);
**         USB_MSC_LBA_Transfer             - uint_8 usb_msc_USB_MSC_LBA_Transfer(uint_8 controller_ID, bool direction,...
**         USB_Class_MSC_Send_Data          - uint_8 usb_msc_USB_Class_MSC_Send_Data(uint_8 controller_ID, uint_8 ep_num,...
**         USB_MSC_SCSI_Init                - uint_8 usb_msc_USB_MSC_SCSI_Init(uint_8 controller_ID, USB_CLASS_CALLBACK...
**         msc_request_sense_command        - uint_8 usb_msc_msc_request_sense_command(uint_8 controller_ID, PTR_CBW...
**         msc_inquiry_command              - uint_8 usb_msc_msc_inquiry_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**         msc_read_command                 - uint_8 usb_msc_msc_read_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**         msc_write_command                - uint_8 usb_msc_msc_write_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**         msc_test_unit_ready_command      - uint_8 usb_msc_msc_test_unit_ready_command(uint_8 controller_ID, PTR_CBW...
**         msc_verify_command               - uint_8 usb_msc_msc_verify_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**         msc_mode_sense_command           - uint_8 usb_msc_msc_mode_sense_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**         msc_mode_select_command          - uint_8 usb_msc_msc_mode_select_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**         msc_read_capacity_command        - uint_8 usb_msc_msc_read_capacity_command(uint_8 controller_ID, PTR_CBW...
**         msc_read_format_capacity_command - uint_8 usb_msc_msc_read_format_capacity_command(uint_8 controller_ID, PTR_CBW...
**         msc_format_unit_command          - uint_8 usb_msc_msc_format_unit_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**         msc_prevent_allow_medium_removal - uint_8 usb_msc_msc_prevent_allow_medium_removal(uint_8 controller_ID, PTR_CBW...
**         msc_start_stop_unit_command      - uint_8 usb_msc_msc_start_stop_unit_command(uint_8 controller_ID, PTR_CBW...
**         msc_send_diagnostic_command      - uint_8 usb_msc_msc_send_diagnostic_command(uint_8 controller_ID, PTR_CBW...
**         msc_unsupported_command          - uint_8 usb_msc_msc_unsupported_command(uint_8 controller_ID, PTR_CBW cbw_ptr,...
**
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef _USB_MSC_H
#define _USB_MSC_H 1

/* MODULE usb_msc. */
#include "usb_devapi.h"
#include "usb_descriptor.h"
#include "usb_class.h"
#include "usb_framework.h"

/******************************************************************************
 * Macro's
 *****************************************************************************/
#define COMPONENT_PREPARE_SHIFT             (0x07)

#define USB_MSC_DEVICE_READ_REQUEST         (0x81)
#define USB_MSC_DEVICE_WRITE_REQUEST        (0x82)
#define USB_MSC_DEVICE_FORMAT_COMPLETE      (0x83)
#define USB_MSC_DEVICE_REMOVAL_REQUEST      (0x84)
#define USB_MSC_DEVICE_GET_INFO             (0x85)
#define USB_MSC_START_STOP_EJECT_MEDIA      (0x86)

/* Class specific request Codes */
#define BULK_ONLY_MASS_STORAGE_RESET        (0xFF)
#define GET_MAX_LUN                         (0xFE)
#define PUT_REQUESTS                        (0xFD)
#define GET_REQUESTS                        (0xFC)

/* Events to the Application */ /* 0 to 4 are reserved for class events */

/* other macros */
#define  USB_DCBWSIGNATURE                  (0x43425355) /*little endian : 0x43425355 */
#define  USB_DCSWSIGNATURE                  (0x53425355) /*little endian : 0x53425355 */

#define  USB_CBW_DIRECTION_BIT              (0x80)
#define  USB_CBW_DIRECTION_SHIFT            (7)
#define  MSC_CBW_LENGTH                     (31)
#define  MSC_CSW_LENGTH                     (13)

#define  MSC_RECV_DATA_BUFF_SIZE            (512)
#define  MSC_SEND_DATA_BUFF_SIZE            (512)

#define COMMAND_PASSED                      (0x00)
#define COMMAND_FAILED                      (0x01)
#define PHASE_ERROR                         (0x02)
/* macros for queuing */
 #define MAX_QUEUE_ELEMS                    (4)

/* MACROS FOR COMMANDS SUPPORTED */
 #define INQUIRY_COMMAND                    (0x12)
 #define READ_10_COMMAND                    (0x28)
 #define READ_12_COMMAND                    (0xA8)
 #define REQUEST_SENSE_COMMAND              (0x03)
 #define TEST_UNIT_READY_COMMAND            (0x00)
 #define WRITE_10_COMMAND                   (0x2A)
 #define WRITE_12_COMMAND                   (0xAA)
 #define PREVENT_ALLOW_MEDIUM_REM_COMMAND   (0x1E)
 #define FORMAT_UNIT_COMMAND                (0x04)
 #define READ_CAPACITY_10_COMMAND           (0x25)
 #define READ_FORMAT_CAPACITIES_COMMAND     (0x23)
 #define MODE_SENSE_10_COMMAND              (0x5A)
 #define MODE_SENSE_6_COMMAND               (0x1A)
 #define MODE_SELECT_10_COMMAND             (0x55)
 #define MODE_SELECT_6_COMMAND              (0x15)
 #define SEND_DIAGNOSTIC_COMMAND            (0x1D)
 #define VERIFY_COMMAND                     (0x2F)
 #define START_STOP_UNIT_COMMAND            (0x1B)
/*****************************************************************************
 * Local Functions
 *****************************************************************************/
void USB_Service_Bulk_In(PTR_USB_DEV_EVENT_STRUCT event);
/*
** ===================================================================
**     Method      :  USB_Service_Bulk_In (component USB_MSD_CLASS)
**     Description :
**         The function is callback function of DIC Bulk In Endpoint
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           -
**     Returns     : Nothing
** ===================================================================
*/

void USB_Service_Bulk_Out(PTR_USB_DEV_EVENT_STRUCT event);
/*
** ===================================================================
**     Method      :  USB_Service_Bulk_Out (component USB_MSD_CLASS)
**     Description :
**         The function is callback function of DIC Bulk Out Endpoint
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           -
**     Returns     : Nothing
** ===================================================================
*/

void USB_Class_MSC_Event(uint_8 controller_ID, uint_8 event, void* val);
/*
** ===================================================================
**     Method      :  USB_Class_MSC_Event (component USB_MSD_CLASS)
**     Description :
**         The function initializes MSC endpoints
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         event           - pointer to event structure
**       * val             - gives the configuration value
**     Returns     : Nothing
** ===================================================================
*/

/******************************************************************************
 * Types
 *****************************************************************************/
#pragma pack(1)

typedef struct _app_data_struct
{
    uint_8_ptr      data_ptr;     /* pointer to buffer       */
    uint_32 data_size;            /* buffer size of endpoint */
}APP_DATA_STRUCT;

/* structure to hold a request in the endpoint queue */
typedef struct _usb_class_msc_queue
{
    uint_8 controller_ID;
    uint_8 channel;
    APP_DATA_STRUCT app_data;
}USB_CLASS_MSC_QUEUE, *PTR_USB_CLASS_MSC_QUEUE;

/* USB class msc endpoint data */
typedef struct _usb_class_msc_endpoint
{
    uint_8 endpoint;              /* endpoint num */
    uint_8 type;                  /* type of endpoint (interrupt, bulk or isochronous) */
    uint_8 bin_consumer;          /* the num of queued elements */
    uint_8 bin_producer;          /* the num of de-queued elements */
    USB_CLASS_MSC_QUEUE queue[MAX_QUEUE_ELEMS]; /* queue data */
}USB_CLASS_MSC_ENDPOINT;

typedef struct _usb_msc_cbw   /* Command Block Wrapper -- 31 bytes */
{
    uint_32 signature;            /*0-3  : dCBWSignature*/
    uint_32 tag;                  /*4-7  : dCBWTag*/
    uint_32 data_length;          /*8-11 : dCBWDataTransferLength*/
    uint_8  flag;                 /*12   : bmCBWFlags*/
    uint_8  lun;                  /*13   : bCBWLUN(bits 3 to 0)*/
    uint_8  cb_length;            /*14   : bCBWCBLength*/
    uint_8  command_block[16];    /*15-30 : CBWCB*/
}CBW, *PTR_CBW ;

typedef struct _usb_msc_csw   /* Command Status Wrapper -- 13 bytes */
{
    uint_32 signature;            /*0-3  : dCSWSignature*/
    uint_32 tag;                  /*4-7 : dCSWTag*/
    uint_32 residue;              /*8-11 : dCSWDataResidue*/
    uint_8 csw_status;            /*12 : bCSWStatus*/
}CSW, *PTR_CSW;

typedef struct _lba_info_struct
{
    uint_32 starting_lba;         /* LBA to start transfering with */
    uint_32 lba_transfer_num;     /* number of LBAs to transfer */
}LBA_INFO_STRUCT, * PTR_LBA_INFO_STRUCT;

typedef struct _lba_app_struct
{
    uint_32 offset;
    uint_32 size;
    uint_8_ptr buff_ptr;
}LBA_APP_STRUCT, * PTR_LBA_APP_STRUCT;

typedef struct _device_lba_info_struct
{
    uint_32 total_lba_device_supports; /* lba : LOGICAL BLOCK ADDRESS */
    uint_32 length_of_each_lba_of_device;
    uint_8 num_lun_supported;
}DEVICE_LBA_INFO_STRUCT, * PTR_DEVICE_LBA_INFO_STRUCT;

typedef struct _msc_thirteen_case_check
{
    uint_8 controller_ID;
    uint_32 host_expected_data_len;
    uint_8 host_expected_direction;
    uint_32 device_expected_data_len;
    uint_8 device_expected_direction;
    uint_8_ptr csw_status_ptr;
    uint_32_ptr csw_residue_ptr;
    uint_8_ptr buffer_ptr;
    boolean lba_txrx_select;
    LBA_INFO_STRUCT lba_info;
}MSC_THIRTEEN_CASE_STRUCT, *PTR_MSC_THIRTEEN_CASE_STRUCT;

typedef struct _msc_variable_struct
{
    USB_CLASS_CALLBACK msc_callback;
    USB_REQ_FUNC       vendor_callback;
    USB_CLASS_CALLBACK param_callback;
    uint_8 msc_lba_send_buff[MSC_SEND_DATA_BUFF_SIZE];
    uint_8 msc_lba_recv_buff[MSC_RECV_DATA_BUFF_SIZE];
    /* contains the endpoint info */
    USB_CLASS_MSC_ENDPOINT ep[2];
    /* macro configuired by user*/
    /* LUN can have value only from 0 to 15 decimal */
    uint_8 lun;
    /* flag to track bulk out data processing after CBW if needed*/
    boolean out_flag;
    /* flag to track bulk in data processing before CSW if needed*/
    boolean in_flag;
    /* flag to track if there is need to stall BULK IN ENDPOINT
    because of BULK COMMAND*/
    boolean in_stall_flag;
    /* global structure for command block wrapper */
    CBW cbw_struct;
    /* global structure for command status wrapper */
    CSW csw_struct;
    /* flag to track if there is need to stall BULK OUT ENDPOINT
    because of BULK COMMAND */
    boolean out_stall_flag;
    /* flag to validate CBW */
    boolean cbw_valid_flag;
    boolean re_stall_flag;
    DEVICE_LBA_INFO_STRUCT device_info;
}MSC_GLOBAL_VARIABLE_STRUCT, * PTR_MSC_GLOBAL_VARIABLE_STRUCT;

#pragma options align=reset

uint_8 USB_Class_MSC_Init(uint_8 controller_ID, USB_CLASS_CALLBACK msc_class_callback, USB_REQ_FUNC vendor_req_callback, USB_CLASS_CALLBACK param_callback);
/*
** ===================================================================
**     Method      :  USB_Class_MSC_Init (component USB_MSD_CLASS)
**     Description :
**         This function initializes the MSC Class layer and layers it
**         is dependent on
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To Identify the
**                           controller
**         msc_class_callback - event
**                           callback
**         vendor_req_callback - vendor
**                           specific class request callback
**         param_callback  - application params
**                           callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_MSC_DeInit(uint_8 controller_ID);
/*
** ===================================================================
**     Method      :  USB_Class_MSC_DeInit (component USB_MSD_CLASS)
**     Description :
**         The function de-initializes the Device and Controller layer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - Controller ID
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_MSC_SCSI_Init(uint_8 controller_ID, USB_CLASS_CALLBACK callback);
/*
** ===================================================================
**     Method      :  usb_msc_USB_MSC_SCSI_Init (component USB_MSD_CLASS)
**
**     Description :
**         The function initializes the SCSI parameters and callbacks
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         callback        - event callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_MSC_LBA_Transfer(uint_8 controller_ID, boolean direction, PTR_LBA_INFO_STRUCT lba_info_ptr);
/*
** ===================================================================
**     Method      :  USB_MSC_LBA_Transfer (component USB_MSD_CLASS)
**     Description :
**
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         direction       - transfer direction
**         lba_info_ptr    - buffer to send
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_MSC_Send_Data(uint_8 controller_ID, uint_8 ep_num, uint_8_ptr app_buff, uint_32 size);
/*
** ===================================================================
**     Method      :  USB_Class_MSC_Send_Data (component USB_MSD_CLASS)
**     Description :
**
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         ep_num          - endpoint num
**         app_buff        - buffer to send
**         size            - length of the transfer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

#define USB_MSC_Bulk_Send_Data(a,b,c)  USB_Class_MSC_Send_Data(a,BULK_IN_ENDPOINT,b,c)
#define USB_MSC_Bulk_Recv_Data(a,b,c)  _usb_device_recv_data(a,BULK_OUT_ENDPOINT,b,c)

#define USB_MSC_Periodic_Task USB_Class_Periodic_Task
uint_8 msc_inquiry_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_inquiry_command (component USB_MSD_CLASS)
**     Description :
**         It requests that information regarding parameters of the
**         Device be sent to the Host Computer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_read_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_read_command (component USB_MSD_CLASS)
**     Description :
**         command requests that device transfer data to the host
**         computer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_request_sense_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_request_sense_command (component USB_MSD_CLASS)
**     Description :
**         command instructs the Device to transfer sense data to host
**         computer
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_write_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_write_command (component USB_MSD_CLASS)
**     Description :
**         command requests that the Device write the data transferred
**         by the Host Computer to the medium.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_test_unit_ready_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_test_unit_ready_command (component USB_MSD_CLASS)
**     Description :
**         It provides a means to check if the device is ready
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_verify_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_verify_command (component USB_MSD_CLASS)
**     Description :
**         command requests that device verifies the data on medium
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         -  pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_mode_sense_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_mode_sense_command (component USB_MSD_CLASS)
**     Description :
**         command provides a means for a Device to report parameters
**         to Host Computer.It is a complementary command to the MODE
**         SELECT command.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_mode_select_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_mode_select_command (component USB_MSD_CLASS)
**     Description :
**         command provides a means for a Device to report parameters
**         to Host Computer.It is a complementary command to the MODE
**         SENSE command.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_read_capacity_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_read_capacity_command (component USB_MSD_CLASS)
**     Description :
**         command provides a means for the host computer to request
**         information regarding the capacity of the installed medium
**         of the device.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_read_format_capacity_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_read_format_capacity_command (component USB_MSD_CLASS)
**     Description :
**         command allows the host to request a list of the possible
**         capacities that can be formatted on the currently installed
**         medium
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint_8 msc_format_unit_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_format_unit_command (component USB_MSD_CLASS)
**     Description :
**         host sends the FORMAT UNIT command to physically format a
**         floppy disk according to selected options
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_prevent_allow_medium_removal(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_prevent_allow_medium_removal (component USB_MSD_CLASS)
**     Description :
**         command tells the UFI device to enable or disable the
**         removal of the medium in the logical unit.
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_start_stop_unit_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_start_stop_unit_command (component USB_MSD_CLASS)
**     Description :
**         command instructs device to enable or disable media access
**         operations
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_send_diagnostic_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_send_diagnostic_command (component USB_MSD_CLASS)
**     Description :
**         requests the device to perform self test
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  - pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 msc_unsupported_command(uint_8 controller_ID, PTR_CBW cbw_ptr, uint_32 *csw_residue_ptr, uint_8 *csw_status_ptr);
/*
** ===================================================================
**     Method      :  msc_unsupported_command (component USB_MSD_CLASS)
**     Description :
**         Responds appropriately to unsupported commands
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - To identify the
**                           controller
**         cbw_ptr         - pointer to Command Block Wrapper
**                           sent by host
**       * csw_residue_ptr - pointer to
**                           dCSWDataResidue of Command Status Wrapper
**       * csw_status_ptr  -  pointer to
**                           bCSWStatus  of Command Status Wrapper
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void USB_BYTE_SWAP4(uint_32 a, uint_32 *b);
/*
** ===================================================================
**     Method      :  USB_BYTE_SWAP4 (component USB_MSD_CLASS)
**     Description :
**         SWAP four consecutive bytes to correct the endianness of
**         data received
**     Parameters  :
**         NAME            - DESCRIPTION
**         a               -
**       * b               - Pointer to
**     Returns     : Nothing
** ===================================================================
*/

void USB_memzero(void* ptr, uint_32 size);
/*
** ===================================================================
**     Method      :  USB_memzero (component USB_MSD_CLASS)
**     Description :
**         To clear the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * ptr             -
**         size            -
**     Returns     : Nothing
** ===================================================================
*/

void USB_memcopy(void *src, void *dst, uint_32 size);
/*
** ===================================================================
**     Method      :  USB_memcopy (component USB_MSD_CLASS)
**     Description :
**         To copy data from one memory location to another
**     Parameters  :
**         NAME            - DESCRIPTION
**       * src             -
**       * dst             -
**         size            -
**     Returns     : Nothing
** ===================================================================
*/

/* END usb_msc. */

#endif
/* ifndef __usb_msc_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
