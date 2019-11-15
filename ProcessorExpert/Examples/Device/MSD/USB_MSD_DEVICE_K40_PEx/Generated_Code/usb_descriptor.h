/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_descriptor.h
**     Project   : ProcessorExpert
**     Processor : MK40N512MD100
**     Component : USB_MSD_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.003
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef _USB_DESCRIPTOR_H
#define _USB_DESCRIPTOR_H
#include "usb_class.h"
#include "usb_framework.h"
/******************************************************************************
 * Macro's
 *****************************************************************************/
#define BCD_USB_VERSION                  (0x0200)
#define REMOTE_WAKEUP_SUPPORT            (0)/*1: TRUE, 0: FALSE*/
#define REMOTE_WAKEUP_SHIFT              (5)

/* Implementation Specific Macros */
#define MSC_DESC_ENDPOINT_COUNT         (2)
#define BULK_IN_ENDPOINT             (1)
#define BULK_IN_ENDP_PACKET_SIZE     (32)/* max supported is 64 for FS and 512 for HS*/
#define BULK_OUT_ENDPOINT            (2)
#define BULK_OUT_ENDP_PACKET_SIZE    (32)/* max supported is 64 and 512 for HS*/
/* Various descriptor sizes */
#define DEVICE_DESCRIPTOR_SIZE            (18)
#define CONFIG_ONLY_DESC_SIZE             (9)
#define IFACE_ONLY_DESC_SIZE              (9)
#define ENDP_ONLY_DESC_SIZE               (7)
#define CONFIG_DESC_SIZE        (CONFIG_ONLY_DESC_SIZE + \
    IFACE_ONLY_DESC_SIZE + \
    ENDP_ONLY_DESC_SIZE * MSC_DESC_ENDPOINT_COUNT)

/* Max descriptors provided by the Application */
#define USB_MAX_STD_DESCRIPTORS               (7)
/* Max configuration supported by the Application */
#define USB_MAX_CONFIG_SUPPORTED          (1)

/* Max string descriptors supported by the Application */
#define USB_MAX_STRING_DESCRIPTORS        (5)

/* Max language codes supported by the USB */
#define USB_MAX_LANGUAGES_SUPPORTED       (1)

/* string descriptors sizes */
#define USB_STR_DESC_SIZE (2)
#define USB_STR_0_SIZE  (2)
#define USB_STR_1_SIZE  (56)
#define USB_STR_2_SIZE  (46)
#define USB_STR_3_SIZE  (32)
#define USB_STR_n_SIZE  (32)

/* descriptors codes */
#define USB_DEVICE_DESCRIPTOR     (1)
#define USB_CONFIG_DESCRIPTOR     (2)
#define USB_STRING_DESCRIPTOR     (3)
#define USB_IFACE_DESCRIPTOR      (4)
#define USB_ENDPOINT_DESCRIPTOR   (5)
#define USB_DEVQUAL_DESCRIPTOR    (6)

#define USB_MAX_SUPPORTED_INTERFACES     (1)
/* mass storage specific macros */
#define MASS_STORAGE_CLASS           (0x08)
#define SCSI_TRANSPARENT_COMMAND_SET (0x06)
#define BULK_ONLY_PROTOCOL           (0x50)
#define PERIPHERAL_DEVICE_TYPE       (0x00)
/* Direct Access Block Device : Magnetic and Flash Drives*/
#define PERIPHERAL_QUALIFIER_SHIFT   (5)
#define PERIPHERAL_QUALIFIER         (0)
#define SPC_VERSION                  (4)/*SPC3 is 5; SPC2 is 4*/
#define REMOVABLE_MEDIUM_BIT         (1)
#define REMOVABLE_MEDIUM_BIT_SHIFT   (7)
#define ADDITIONAL_LENGTH            (0x20)
#define SUPPORT_DISK_LOCKING_MECHANISM  (0) /*1: TRUE; 0:FALSE*/
#define IMPLEMENTING_DISK_DRIVE         (0) /*1: TRUE; 0:FALSE*/
/* Add your custom macro here*/

/******************************************************************************
 * Types
 *****************************************************************************/
typedef const struct _USB_LANGUAGE
{
    uint_16 const language_id;      /* Language ID */
    uint_8 const ** lang_desc;      /* Language Descriptor String */
    uint_8 const * lang_desc_size;  /* Language Descriptor Size */
} USB_LANGUAGE;

typedef const struct _USB_ALL_LANGUAGES
{
    /* Pointer to Supported Language String */
    uint_8 const *languages_supported_string;
    /* Size of Supported Language String */
    uint_8 const languages_supported_size;
    /* Array of Supported Languages */
    USB_LANGUAGE usb_language[USB_MAX_SUPPORTED_INTERFACES];
}USB_ALL_LANGUAGES;

typedef const struct _USB_ENDPOINTS
{
    /* Number of non control Endpoints */
    uint_8 count;
    /* Array of Endpoints Structures */
    USB_EP_STRUCT ep[MSC_DESC_ENDPOINT_COUNT];
}USB_ENDPOINTS;

/******************************************************************************
* Global Functions
*****************************************************************************/
uint_8 USB_Desc_Get_Descriptor(uint_8 controller_ID, uint_8 type, uint_8 str_num, uint_16 index, uint_8_ptr *descriptor, USB_PACKET_SIZE *size);
/*
** ===================================================================
**     Method      :  USB_Desc_Get_Descriptor (component USB_MSD_CLASS)
**     Description :
**         The function returns the correponding descriptor
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN]  Controller ID
**         type            - [IN]  Type of descriptor requested
**         str_num         - [IN]  String index for string
**                           descriptor
**         index           - [IN]  String descriptor language Id
**       * descriptor      - [OUT] Output descriptor
**                           pointer
**       * size            - [OUT] Size of descriptor returned
**     Returns     :
**         ---             - USB_OK                         when
**                           Successfull
**                           USBERR_INVALID_REQ_TYPE        when Error
** ===================================================================
*/

uint_8 USB_Desc_Get_Interface(uint_8 controller_ID, uint_8 interface, uint_8_ptr alt_interface);
/*
** ===================================================================
**     Method      :  USB_Desc_Get_Interface (component USB_MSD_CLASS)
**     Description :
**         The function returns the alternate interface
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         interface       - [IN] Interface number
**         alt_interface   - [OUT] Output alternate
**                           interface
**     Returns     :
**         ---             - USB_OK                         when
**                           Successfull
**                           USBERR_INVALID_REQ_TYPE        when Error
** ===================================================================
*/

boolean USB_Desc_Valid_Configation(uint_8 controller_ID, uint_16 config_val);
/*
** ===================================================================
**     Method      :  USB_Desc_Valid_Configation (component USB_MSD_CLASS)
**     Description :
**         This function checks whether the configuration is valid or
**         not
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         config_val      - [IN] Configuration value
**     Returns     :
**         ---             - TRUE           When Valid
**                           FALSE          When Error
** ===================================================================
*/
boolean USB_Desc_Valid_Interface(uint_8 controller_ID, uint_8 interface);
/*
** ===================================================================
**     Method      :  USB_Desc_Valid_Interface (component USB_MSD_CLASS)
**     Description :
**         This function checks whether the interface is valid or not
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         interface       - [IN] Target interface
**     Returns     :
**         ---             - TRUE           When Valid
**                           FALSE          When Error
** ===================================================================
*/

boolean USB_Desc_Remote_Wakeup(uint_8 controller_ID);
/*
** ===================================================================
**     Method      :  USB_Desc_Remote_Wakeup (component USB_MSD_CLASS)
**     Description :
**         This function returns remote wakeup is supported or not
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     :
**         ---             - REMOTE_WAKEUP_SUPPORT (TRUE) - If remote
**                           wakeup supported
** ===================================================================
*/

void* USB_Desc_Get_Endpoints(uint_8 controller_ID);
/*
** ===================================================================
**     Method      :  USB_Desc_Get_Endpoints (component USB_MSD_CLASS)
**     Description :
**         This function returns the information about all the non
**         control endpoints implemented
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     :
**         ---             - pointer to USB_ENDPOINTS
** ===================================================================
*/

uint_8 USB_Desc_Set_Interface(uint_8 controller_ID, uint_8 interface, uint_8 alt_interface);
/*
** ===================================================================
**     Method      :  USB_Desc_Set_Interface (component USB_MSD_CLASS)
**     Description :
**         The function sets the alternate interface
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         interface       - [IN] Interface number
**         alt_interface   - [IN] Input alternate
**                           interface
**     Returns     :
**         ---             - USB_OK                         when
**                           Successfull
**                           USBERR_INVALID_REQ_TYPE        when Error
** ===================================================================
*/
#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

