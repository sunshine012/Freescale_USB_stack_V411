/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_descriptor.h
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
/* Begin of code block <0>  auto generated code, DO NOT MODIFY LINES BELOW */
#ifndef _USB_DESCRIPTOR_H
#define _USB_DESCRIPTOR_H
#include "usb_class.h"
#include "usb_framework.h"
/* End code block <0>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write your own includes here ... */

/* Begin of code block <1>  auto generated code, DO NOT MODIFY LINES BELOW */
/******************************************************************************
* Macro's
*****************************************************************************/
#define BCD_USB_VERSION                     (0x0200)
/* Various descriptor sizes */
#define DEVICE_DESCRIPTOR_SIZE              (18)
#define DEVICE_QUALIFIER_DESCRIPTOR_SIZE    (10)
#define CONFIG_ONLY_DESC_SIZE               (9)
#define IFACE_ONLY_DESC_SIZE                (9)
#define ENDP_ONLY_DESC_SIZE                 (7)
#define DESC_ENDPOINT_COUNT                 (1)
#define DESC_INTERFACE_COUNT                (1)
#define OTG_ONLY_DESC_SIZE                  (5)
#define CONFIG_DESC_SIZE                    (CONFIG_ONLY_DESC_SIZE + \
                                             IFACE_ONLY_DESC_SIZE * DESC_INTERFACE_COUNT + \
                                             ENDP_ONLY_DESC_SIZE * DESC_ENDPOINT_COUNT +\
                                             OTG_ONLY_DESC_SIZE+\
                                             SPECIFIC_DESC_SIZE)

/* Max descriptors provided by the Application */
#define USB_MAX_STD_DESCRIPTORS             (8)
#define USB_MAX_CLASS_SPECIFIC_DESCRIPTORS  (2)

/* Max configuration supported by the Application */
#define USB_MAX_CONFIG_SUPPORTED            (1)

/* Max string descriptors supported by the Application */
#define USB_MAX_STRING_DESCRIPTORS          (4)

/* Max language codes supported by the USB */
#define USB_MAX_LANGUAGES_SUPPORTED         (1)

/* OTG definitions */
#define USB_OTG_DESCRIPTOR                  (9)
#define USB_OTG_SRP_SUPPORT                 (0x01)
#define USB_OTG_HNP_SUPPORT                 (0x02)
#define USB_OTG_ADP_SUPPORT                 (0x04)
#define USB_OTG_VERSION_2_0                 (0x0200)

/* string descriptors sizes */
#define USB_STR_DESC_SIZE                   (2)
#define USB_STR_0_SIZE                      (2)
#define USB_STR_1_SIZE                      (56)
#define USB_STR_2_SIZE                      (54)
#define USB_STR_n_SIZE                      (32)

/* descriptors codes */
#define USB_DEVICE_DESCRIPTOR               (1)
#define USB_CONFIG_DESCRIPTOR               (2)
#define USB_STRING_DESCRIPTOR               (3)
#define USB_IFACE_DESCRIPTOR                (4)
#define USB_ENDPOINT_DESCRIPTOR             (5)
#define USB_DEVQUAL_DESCRIPTOR              (6)
#define USB_MAX_SUPPORTED_INTERFACES        (1)
/* End code block <1>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write code here ... */
/* Add your custom macro here*/
#define HID_ONLY_DESC_SIZE                  (9)
#define REPORT_DESC_SIZE                    (63)
#define HID_DESC_ENDPOINT_COUNT             (1)
#define HID_ENDPOINT                        (1)
#define HID_ENDPOINT_PACKET_SIZE            (8)
#define USB_HID_DESCRIPTOR                  (0x21)
#define USB_REPORT_DESCRIPTOR               (0x22)
/* The following macro is used for specific descriptor and default 0. If need,
 you can redefine this value belongs to the application*/
#define SPECIFIC_DESC_SIZE HID_ONLY_DESC_SIZE
/* Begin of code block <2>  auto generated code, DO NOT MODIFY LINES BELOW */
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
    USB_EP_STRUCT ep[DESC_ENDPOINT_COUNT];
}USB_ENDPOINTS;

typedef struct usb_otg_descriptor_tag
{
    uint_8   bLength;          /* Descriptor size in bytes = 9 */
    uint_8   bDescriptorType;  /* CONFIGURATION type = 2 or 7 */
    uint_8   bmAttributes;     /* OTG characteristics */
#define OTG_SRP_SUPPORT   (0x01)  /* Supports SRP */
#define OTG_HNP_SUPPORT   (0x02)  /* Supports HNP */
    uint_8   bcdOTG[2];       /* OTG supplement release number */
} OTG_DESCRIPTOR_T, _PTR_ OTG_DESCRIPTOR_PTR_T;
/* End code block <2>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write code here ... */


/* Begin of code block <3>  auto generated code, DO NOT MODIFY LINES BELOW */
/******************************************************************************
* Global Functions
*****************************************************************************/
uint_8 USB_Desc_Get_Descriptor(uint_8 controller_ID, uint_8 type, uint_8 str_num, uint_16 index, uint_8_ptr *descriptor, USB_PACKET_SIZE *size);
/*
    ** ===================================================================
    **     Method      :  USB_Desc_Get_Descriptor (component USB_OTG_STACK)
    **     Description :
    **         The function returns the correponding descriptor
**     Parameters  :
**         NAME            - DESCRIPTION
    **         controller_ID - [IN]  Controller ID
    **         type        - [IN]  Type of descriptor requested
    **         str_num     - [IN]  String index for string
    **                       descriptor
    **         index       - [IN]  String descriptor language Id
    **       * descriptor  - [OUT] Output descriptor
    **                       pointer
    **       * size        - [OUT] Size of descriptor returned
    **     Returns     :
    **         ---         - USB_OK                         when
    **                       Successful
    **                       USBERR_INVALID_REQ_TYPE        when Error
    ** ===================================================================
    */

uint_8 USB_Desc_Get_Interface(uint_8 controller_ID, uint_8 interface, uint_8_ptr alt_interface);
/*
    ** ===================================================================
    **     Method      :  USB_Desc_Get_Interface (component USB_OTG_STACK)
    **     Description :
    **         The function returns the alternate interface
**     Parameters  :
**         NAME            - DESCRIPTION
    **         controller_ID - [IN] Controller ID
    **         interface   - [IN] Interface number
    **         alt_interface - [OUT] Output alternate
    **                       interface
    **     Returns     :
    **         ---         - USB_OK                         when
    **                       Successful
    **                       USBERR_INVALID_REQ_TYPE        when Error
    ** ===================================================================
    */

boolean USB_Desc_Valid_Configation(uint_8 controller_ID, uint_16 config_val);
/*
    ** ===================================================================
    **     Method      :  USB_Desc_Valid_Configation (component USB_OTG_STACK)
    **     Description :
    **         This function checks whether the configuration is valid or
    **         not
**     Parameters  :
**         NAME            - DESCRIPTION
    **         controller_ID - [IN] Controller ID
    **         config_val  - [IN] Configuration value
    **     Returns     :
    **         ---         - TRUE           When Valid
    **                       FALSE          When Error
    ** ===================================================================
    */

boolean USB_Desc_Valid_Interface(uint_8 controller_ID, uint_8 interface);
/*
    ** ===================================================================
    **     Method      :  USB_Desc_Valid_Interface (component USB_OTG_STACK)
    **     Description :
    **         This function checks whether the interface is valid or not
**     Parameters  :
**         NAME            - DESCRIPTION
    **         controller_ID - [IN] Controller ID
    **         interface   - [IN] Target interface
    **     Returns     :
    **         ---         - TRUE           When Valid
    **                       FALSE          When Error
    ** ===================================================================
    */

boolean USB_Desc_Remote_Wakeup(uint_8 controller_ID);
/*
    ** ===================================================================
    **     Method      :  USB_Desc_Remote_Wakeup (component USB_OTG_STACK)
    **     Description :
    **         This function returns remote wakeup is supported or not
**     Parameters  :
**         NAME            - DESCRIPTION
    **         controller_ID - [IN] Controller ID
    **     Returns     :
    **         ---         - REMOTE_WAKEUP_SUPPORT (TRUE) - If remote
    **                       wakeup supported
    ** ===================================================================
    */

void* USB_Desc_Get_Endpoints(uint_8 controller_ID);
/*
    ** ===================================================================
    **     Method      :  USB_Desc_Get_Endpoints (component USB_OTG_STACK)
    **     Description :
    **         This function returns the information about all the non
    **         control endpoints implemented
**     Parameters  :
**         NAME            - DESCRIPTION
    **         controller_ID - [IN] Controller ID
    **     Returns     :
    **         ---         - pointer to USB_ENDPOINTS
    ** ===================================================================
    */

uint_8 USB_Desc_Set_Interface(uint_8 controller_ID, uint_8 interface, uint_8 alt_interface);
/*
    ** ===================================================================
    **     Method      :  USB_Desc_Set_Interface (component USB_OTG_STACK)
    **     Description :
    **         The function sets the alternate interface
**     Parameters  :
**         NAME            - DESCRIPTION
    **         controller_ID - [IN] Controller ID
    **         interface   - [IN] Interface number
    **         alt_interface - [IN] Input alternate
    **                       interface
    **     Returns     :
    **         ---         - USB_OK                         when
    **                       Successful
    **                       USBERR_INVALID_REQ_TYPE        when Error
    ** ===================================================================
    */
#endif
/* End code block <3>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write code here ... */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
