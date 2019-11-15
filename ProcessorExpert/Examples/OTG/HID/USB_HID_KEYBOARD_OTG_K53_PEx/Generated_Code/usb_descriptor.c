/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_descriptor.c
**     Project   : ProcessorExpert
**     Processor : MK53N512MD100
**     Component : USB_HID_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 13:40, # CodeGen: 34
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
/******************************************************************************
 * Includes
 *****************************************************************************/
#include "types.h"
#include "usb_descriptor.h"


/*****************************************************************************
 * Constant and Macro's
 *****************************************************************************/
/* structure containing details of all the endpoints used by this device */
const USB_ENDPOINTS usb_desc_ep = {
    HID_DESC_ENDPOINT_COUNT,
    {
        {
            1,
            USB_INTERRUPT_PIPE,
            USB_SEND,
            8,
        },
    }
};

uint_8 g_device_descriptor[DEVICE_DESCRIPTOR_SIZE]=
{
    DEVICE_DESCRIPTOR_SIZE,            /*  Device Dexcriptor Size         */
    USB_DEVICE_DESCRIPTOR,             /*  Device Type of descriptor      */
    0x00, 0x02,                        /*  BCD USB version                */
    0x00,                              /*  Device Class is indicated inthe interface descriptors      */
    0x00,                              /*  Device Subclass is indicated
                                       in the interface descriptors   */
    0x00,                              /*  Device Protocol                */
    0x20,                              /*  Max Packet size                */
    0xA2, 0x15,                        /*  Vendor ID                      */
    0x01,0x01,                         /*  Product ID  */
    0x02, 0x00,                        /*  BCD Device version             */
    0x01 ,                             /*  Manufacturer string index      */
    0x02 ,                             /*  Product string index           */
    0x03 ,                             /*  Serial number string index     */
    0x01                               /*  Number of configurations       */
};

uint_8 g_config_descriptor[CONFIG_DESC_SIZE] =
{
    CONFIG_ONLY_DESC_SIZE,             /*  Configuration Descriptor Size */
    USB_CONFIG_DESCRIPTOR,             /* "Configuration" type of descriptor */
    USB_uint_16_low(CONFIG_DESC_SIZE),USB_uint_16_high(CONFIG_DESC_SIZE), /*  Total length of the Configuration descriptor */
    1,                                 /*NumInterfaces*/
    1,                                 /*  Configuration Value */
    0,                                 /*  Configuration Description String Index*/
    0x40,                              /*  Attributes.support RemoteWakeup and self power*/
    0x32,                              /*  Current draw from bus*/
    /* INTERFACE DESCRIPTOR */
    /* Interface 0 Descriptor ()*/
    IFACE_ONLY_DESC_SIZE,              /* Descriptor Size */
    USB_IFACE_DESCRIPTOR,              /* Descriptor type: Interface descriptor */
    0x00,                              /* Number of this Interface (0..) */
    0x00,                              /* Alternative for this Interface (if any) */
    0x01,                              /* No of EPs used by this IF (excl. EP0) */
    0x03,                              /* Interface Class */
    0x01,                              /* Interface Subclass*/
    0x01,                              /* Interface Protocol*/
    0x00,                              /* Index of String Desc for this Interface */

    /* HID descriptor */
    HID_ONLY_DESC_SIZE,
    USB_HID_DESCRIPTOR,
    0x00,0x01,
    0x00,
    0x01,
    0x22,
    0x3F,0x00,                         /* report descriptor size to follow */
    /* Endpoint 1 INTERRUPT IN Descriptor ()*/
    ENDP_ONLY_DESC_SIZE,               /* Descriptor size */
    USB_ENDPOINT_DESCRIPTOR,            /* Descriptor type: Endpopint descriptor */
    0x81,                              /* Address: 1, direction: IN */
    0x03,                              /* Transfer type: No Synchonisation */
    0x08, 0x00,                        /* Max. packet size: 8 byte(s) */
    0x00,                              /* Maximum NAK rate*/

    /* OTG descriptor */
    OTG_ONLY_DESC_SIZE,
    USB_OTG_DESCRIPTOR,
    USB_OTG_SRP_SUPPORT | USB_OTG_HNP_SUPPORT,
    (uint_8)(USB_OTG_VERSION_2_0 >> 8),
    (uint_8)(USB_OTG_VERSION_2_0),
};

uint_8  g_report_descriptor[REPORT_DESC_SIZE] =
{
    0x05,0x01,
    0x09,0x06,
    0xA1,0x01,
    0x05,0x07,
    0x19,0xE0,
    0x29,0xE7,
    0x15,0x00,
    0x25,0x01,
    0x75,0x01,
    0x95,0x08,
    0x81,0x02,
    0x95,0x01,
    0x75,0x08,
    0x81,0x01,
    0x95,0x05,
    0x75,0x01,
    0x05,0x08,
    0x19,0x01,
    0x29,0x05,
    0x91,0x02,
    0x95,0x01,
    0x75,0x03,
    0x91,0x01,
    0x95,0x06,
    0x75,0x08,
    0x15,0x00,
    0x25,0x65,
    0x05,0x07,
    0x19,0x00,
    0x29,0x65,
    0x81,0x00,
    0xC0,
};
uint_8 USB_STR_0[USB_STR_0_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_0),
    USB_STRING_DESCRIPTOR,
    0x09,
    0x04                               /*equiavlent to 0x0409*/
};
uint_8 USB_STR_1[USB_STR_1_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_1),
    USB_STRING_DESCRIPTOR,
    'F',0,
    'R',0,
    'E',0,
    'E',0,
    'S',0,
    'C',0,
    'A',0,
    'L',0,
    'E',0,
    ' ',0,
    'S',0,
    'E',0,
    'M',0,
    'I',0,
    'C',0,
    'O',0,
    'N',0,
    'D',0,
    'U',0,
    'C',0,
    'T',0,
    'O',0,
    'R',0,
    ' ',0,
    'I',0,
    'N',0,
    'C',0,
    '.',0,
};
uint_8 USB_STR_2[USB_STR_2_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_2),
    USB_STRING_DESCRIPTOR,
    'U',0,
    'S',0,
    'B',0,
    ' ',0,
    'H',0,
    'I',0,
    'D',0,
    ' ',0,
    'O',0,
    'T',0,
    'G',0,
    ' ',0,
    'D',0,
    'E',0,
    'V',0,
    'I',0,
    'C',0,
    'E',0,
    ' ',0,
    'P',0,
    'E',0,
    'x',0,
    ' ',0,
    'D',0,
    'E',0,
    'M',0,
    'O',0,
};
uint_8 USB_STR_n[USB_STR_n_SIZE+USB_STR_DESC_SIZE] = {
    sizeof(USB_STR_n),
    USB_STRING_DESCRIPTOR,
    'B',0,
    'A',0,
    'D',0,
    ' ',0,
    'S',0,
    'T',0,
    'R',0,
    'I',0,
    'N',0,
    'G',0,
    ' ',0,
    'I',0,
    'N',0,
    'D',0,
    'E',0,
    'X',0
};

USB_PACKET_SIZE const g_std_desc_size[USB_MAX_STD_DESCRIPTORS+1] = {
    0,
    DEVICE_DESCRIPTOR_SIZE,
    CONFIG_DESC_SIZE,
    0,                                       /* string */
    0,                                      /* Interface */
    0,                                      /* Endpoint */
    0,                                      /* Device Qualifier */
    0,                                      /* other speed config */
    REPORT_DESC_SIZE
};

uint_8_ptr const g_std_descriptors[USB_MAX_STD_DESCRIPTORS+1] = {
    NULL,
    (uint_8_ptr)g_device_descriptor,
    (uint_8_ptr)g_config_descriptor,
    NULL,                                   /* string */
    NULL,                                   /* Interface */
    NULL,                                   /* Endpoint */
    NULL,                                   /* Device Qualifier */
    NULL,                                   /* other speed config*/
    (uint_8_ptr)g_report_descriptor
};
uint_8 const g_string_desc_size[USB_MAX_STRING_DESCRIPTORS+1] = {
    sizeof(USB_STR_0),
    sizeof(USB_STR_1),
    sizeof(USB_STR_2),
    sizeof(USB_STR_n)
};

uint_8_ptr const g_string_descriptors[USB_MAX_STRING_DESCRIPTORS+1] = {
    (uint_8_ptr const)USB_STR_0,
    (uint_8_ptr const)USB_STR_1,
    (uint_8_ptr const)USB_STR_2,
    (uint_8_ptr const)USB_STR_n
};
USB_ALL_LANGUAGES g_languages = {
    USB_STR_0, sizeof(USB_STR_0),
    {
        {
            (uint_16 const)0x0409,
            (const uint_8 **)g_string_descriptors,
            g_string_desc_size
        }
    }
};

uint_8 const g_valid_config_values[USB_MAX_CONFIG_SUPPORTED+1]={0,1};

static uint_8 g_alternate_interface[USB_MAX_SUPPORTED_INTERFACES];

/*
** ===================================================================
**     Method      :  USB_Desc_Get_Descriptor (component USB_HID_CLASS)
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
uint_8 USB_Desc_Get_Descriptor(
    uint_8 controller_ID,              /* [IN]  Controller ID */
    uint_8 type,                       /* [IN]  Type of descriptor requested */
    uint_8 str_num,                    /* [IN]  String index for string descriptor */
    uint_16 index,                     /* [IN]  String descriptor language Id */
    uint_8_ptr *descriptor,            /* [OUT] Output descriptor pointer */
    USB_PACKET_SIZE *size              /* [OUT] Size of descriptor returned */
)
{
    UNUSED (controller_ID)
    switch(type)
    {
        case USB_REPORT_DESCRIPTOR:
        {
            type = USB_MAX_STD_DESCRIPTORS;
            *descriptor = (uint_8_ptr)g_std_descriptors [type];
            *size = g_std_desc_size[type];
        }
        break;
        case USB_HID_DESCRIPTOR:
        {
            type = USB_CONFIG_DESCRIPTOR ;
            *descriptor = (uint_8_ptr)(g_std_descriptors [type]+
                               CONFIG_ONLY_DESC_SIZE+IFACE_ONLY_DESC_SIZE);
            *size = HID_ONLY_DESC_SIZE;
        }
        break;
        case USB_OTG_DESCRIPTOR:
        {
            type = USB_CONFIG_DESCRIPTOR ;
            *descriptor = (uint_8_ptr)(g_std_descriptors [type]+
                                          CONFIG_ONLY_DESC_SIZE+
                                           IFACE_ONLY_DESC_SIZE+
                                             HID_ONLY_DESC_SIZE+
                                             ENDP_ONLY_DESC_SIZE);
          *size = OTG_ONLY_DESC_SIZE;
        }
        break;
        case USB_STRING_DESCRIPTOR:
        {
            if(index == 0)
            {
                /* return the string and size of all languages */
                *descriptor = (uint_8_ptr)g_languages.languages_supported_string;
                *size = g_languages.languages_supported_size;
            } else
            {
                uint_8 lang_id=0;
                uint_8 lang_index=USB_MAX_LANGUAGES_SUPPORTED;

                for(;lang_id< USB_MAX_LANGUAGES_SUPPORTED;lang_id++)
                {
                    /* check whether we have a string for this language */
                    if(index == g_languages.usb_language[lang_id].language_id)
                    {   /* check for max descriptors */
                        if(str_num < USB_MAX_STRING_DESCRIPTORS)
                        {   /* setup index for the string to be returned */
                            lang_index=str_num;
                        }
                        break;
                    }
                }
                /* set return val for descriptor and size */
                *descriptor = (uint_8_ptr)g_languages.usb_language[lang_id].lang_desc[lang_index];
                *size = g_languages.usb_language[lang_id].lang_desc_size[lang_index];
            }
        }
        break;
        default :
        if (type < USB_MAX_STD_DESCRIPTORS)
        {
            /* set return val for descriptor and size*/
            *descriptor = (uint_8_ptr)g_std_descriptors [type];

            /* if there is no descriptor then return error */
            if(*descriptor == NULL)
            {
                return USBERR_INVALID_REQ_TYPE;
            }
            *size = g_std_desc_size[type];
        }
        else /* invalid descriptor */
        {
            return USBERR_INVALID_REQ_TYPE;
        }
        break;
    }
    return USB_OK;
}

/*
** ===================================================================
**     Method      :  USB_Desc_Get_Interface (component USB_HID_CLASS)
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
uint_8 USB_Desc_Get_Interface(
    uint_8 controller_ID,              /* [IN] Controller ID */
    uint_8 interface,                  /* [IN] Interface number */
    uint_8_ptr alt_interface           /* [OUT] Output alternate interface */
)
{
    UNUSED (controller_ID)
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES)
    {
        /* get alternate interface*/
        *alt_interface = g_alternate_interface[interface];
        return USB_OK;
    }
    return USBERR_INVALID_REQ_TYPE;
}

/*
** ===================================================================
**     Method      :  USB_Desc_Valid_Configation (component USB_HID_CLASS)
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
boolean USB_Desc_Valid_Configation(
    uint_8 controller_ID,              /*[IN] Controller ID */
    uint_16 config_val                 /*[IN] Configuration value */
)
{
    uint_8 loop_index=0;
    UNUSED (controller_ID)

    /* check with only supported val right now */
    while(loop_index < (USB_MAX_CONFIG_SUPPORTED+1))
    {
        if(config_val == g_valid_config_values[loop_index])
        {
            return TRUE;
        }
        loop_index++;
    }
    return FALSE;
}

/*
** ===================================================================
**     Method      :  USB_Desc_Valid_Interface (component USB_HID_CLASS)
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
boolean USB_Desc_Valid_Interface(
    uint_8 controller_ID,              /*[IN] Controller ID */
    uint_8 interface                   /*[IN] Target interface */
)
{
    uint_8 loop_index=0;
    UNUSED (controller_ID)

    /* check with only supported val right now */
    while(loop_index < USB_MAX_SUPPORTED_INTERFACES)
    {
        if(interface == g_alternate_interface[loop_index])
        {
            return TRUE;
        }
        loop_index++;
    }
    return FALSE;
}

/*
** ===================================================================
**     Method      :  USB_Desc_Remote_Wakeup (component USB_HID_CLASS)
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
boolean USB_Desc_Remote_Wakeup(
    uint_8 controller_ID               /* [IN] Controller ID */
)
{
    UNUSED (controller_ID)
    return 0;
}

/*
** ===================================================================
**     Method      :  USB_Desc_Get_Endpoints (component USB_HID_CLASS)
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
void* USB_Desc_Get_Endpoints(
    uint_8 controller_ID               /* [IN] Controller ID */
)
{
    UNUSED (controller_ID)
    return (void*)&usb_desc_ep;
}

/*
** ===================================================================
**     Method      :  USB_Desc_Set_Interface (component USB_HID_CLASS)
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
uint_8 USB_Desc_Set_Interface(
    uint_8 controller_ID,              /* [IN] Controller ID */
    uint_8 interface,                  /* [IN] Interface number */
    uint_8 alt_interface               /* [IN] Input alternate interface */
)
{
    UNUSED (controller_ID)
    /* if interface valid */
    if(interface < USB_MAX_SUPPORTED_INTERFACES)
    {
        /* set alternate interface*/
        g_alternate_interface[interface] = alt_interface;
        return USB_OK;
    }

    return USBERR_INVALID_REQ_TYPE;
}

/* EOF */
