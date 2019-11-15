/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_descriptor.c
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

/* Begin of code block <0>  auto generated code, DO NOT MODIFY LINES BELOW */
#include "types.h"
#include "usb_otg.h"
#include "usb_descriptor.h"
/* End code block <0>  auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write your own includes here ... */

/* Begin of code block <1>  auto generated code, DO NOT MODIFY LINES BELOW */
/*****************************************************************************
 * Constant and Macro's
 *****************************************************************************/
/* structure containing details of all the endpoints used by this device */
const USB_ENDPOINTS usb_desc_ep = {
    DESC_ENDPOINT_COUNT,
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
    0x00,                              /*  Device Class is indicated in
                                       the interface descriptors      */
    0x00,                              /*  Device Subclass is indicated
                                        in the interface descriptors   */
    0x00,                              /*  Device Protocol                */
    0x20,                              /*  Max Packet size                */
    0xA2, 0x15,                        /*  Vendor ID                      */
    0x01, 0x01,                        /*  Product ID  */
    0x02, 0x00,                        /*  BCD Device version             */
    0x01,                              /*  Manufacturer string index      */
    0x02,                              /*  Product string index           */
    0x00,                              /*  Serial number string index     */
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
    /* Interface 0 Descriptor ()                           */
    IFACE_ONLY_DESC_SIZE,              /* Descriptor Size */
    USB_IFACE_DESCRIPTOR,              /* Descriptor type: Interface descriptor */
    0x00,                              /* Number of this Interface (0..) */
    0x00,                              /* Alternative for this Interface (if any) */
    0x01,                              /* No of EPs used by this IF (excl. EP0) */
    0x03,                              /* Interface Class */
    0x01,                              /* Interface Subclass*/
    0x01,                              /* Interface Protocol*/
    0x00,                              /* Index of String Desc for this Interface */
/* End code block <1> auto generated code, DO NOT MODIFY LINES ABOVE */
    /* Specific Interface Descriptor */
    /* Write code to define specific descriptor here */
	HID_ONLY_DESC_SIZE,
   USB_HID_DESCRIPTOR,
   0x00,0x01,
   0x00,
   0x01,
   0x22,
   0x3F,0x00, /* report descriptor size to follow */
/* Begin of code block <2>  auto generated code, DO NOT MODIFY LINES BELOW */
    /* Endpoint 1 INTERRUPT IN Descriptor ()                                      */
    ENDP_ONLY_DESC_SIZE,               /* Descriptor size */
    USB_ENDPOINT_DESCRIPTOR,           /* Descriptor type: Endpopint descriptor */
    0x81,                              /* Address: 1, direction: IN */
    0x03,                              /* Transfer type: No Synchonisation */
    0x08, 0x00,                        /* Max. packet size */
    0x0A,                              /* Maximum NAK rate*/
    /* OTG Descriptor */
    OTG_ONLY_DESC_SIZE,
    USB_OTG_DESCRIPTOR,
    USB_OTG_SRP_SUPPORT | USB_OTG_HNP_SUPPORT,
    (uint_8)(USB_OTG_VERSION_2_0 >> 8),
    (uint_8)(USB_OTG_VERSION_2_0),
};

/* End code block <2> auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write your own structure of specific descriptor code here ... */
uint_8 g_report_descriptor[REPORT_DESC_SIZE] =
{
    0x05, 0x01,                    /* USAGE_PAGE (Generic Desktop) */
    0x09, 0x06,                    /* USAGE (Keyboard) */
    0xa1, 0x01,                    /* COLLECTION (Application) */
    0x05, 0x07,                    /*   USAGE_PAGE (Keyboard) */
    0x19, 0xe0,                    /*   USAGE_MINIMUM (Keyboard LeftControl) */
    0x29, 0xe7,                    /*   USAGE_MAXIMUM (Keyboard Right GUI) */
    0x15, 0x00,                    /*   LOGICAL_MINIMUM (0) */
    0x25, 0x01,                    /*   LOGICAL_MAXIMUM (1) */
    0x75, 0x01,                    /*   REPORT_SIZE (1) */
    0x95, 0x08,                    /*   REPORT_COUNT (8) */
    0x81, 0x02,                    /*   INPUT (Data,Var,Abs) modifier keys (CTRL, ALT, etc...*/
    0x95, 0x01,                    /*   REPORT_COUNT (1) */
    0x75, 0x08,                    /*   REPORT_SIZE (8) */
    0x81, 0x01,                    /*   INPUT (Cnst,Var,Abs) filupp to byte boundary */
    0x95, 0x05,                    /*   REPORT_COUNT (5) */
    0x75, 0x01,                    /*   REPORT_SIZE (1) */
    0x05, 0x08,                    /*   USAGE_PAGE (LEDs) */
    0x19, 0x01,                    /*   USAGE_MINIMUM (Num Lock) */
    0x29, 0x05,                    /*   USAGE_MAXIMUM (Kana) */
    0x91, 0x02,                    /*   OUTPUT (Data,Var,Abs) pc->kbd */
    0x95, 0x01,                    /*   REPORT_COUNT (1) */
    0x75, 0x03,                    /*   REPORT_SIZE (3 */
    0x91, 0x01,                    /*   OUTPUT (Cnst,Var,Abs) filupp to byte boundary */
    0x95, 0x06,                    /*   REPORT_COUNT (6) */
    0x75, 0x08,                    /*   REPORT_SIZE (8) */
    0x15, 0x00,                    /*   LOGICAL_MINIMUM (0) */
    0x25, 0x65,                    /*   LOGICAL_MAXIMUM (101) */
    0x05, 0x07,                    /*   USAGE_PAGE (Keyboard) */
    0x19, 0x00,                    /*   USAGE_MINIMUM (Reserved (no event indicated)) */
    0x29, 0x65,                    /*   USAGE_MAXIMUM (Keyboard Application) */
    0x81, 0x00,                    /*   INPUT (Data,Ary,Abs) array for pressed keys */
    0xc0                           /* END_COLLECTION */
};
/* Begin of code block <3> auto generated code, DO NOT MODIFY LINES BELOW */
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

uint_8 USB_STR_n[USB_STR_n_SIZE+USB_STR_DESC_SIZE] ={
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
    0,                                      /* string */
    0,                                      /* Interface */
    0,                                      /* Endpoint */
    0,                                      /* Device Qualifier */
    0                                       /* other speed config */
/* End code block <3> auto generated code, DO NOT MODIFY LINES ABOVE */
/* write the specific descriptor size here*/
 ,REPORT_DESC_SIZE
/* Begin of code block <4>  auto generated code, DO NOT MODIFY LINES BELOW */
};

uint_8_ptr const g_std_descriptors[USB_MAX_STD_DESCRIPTORS+1] ={
    NULL,
    (uint_8_ptr)g_device_descriptor,
    (uint_8_ptr)g_config_descriptor,
    NULL,                                   /* string */
    NULL,                                   /* Interface */
    NULL,                                   /* Endpoint */
    NULL,                                   /* Device Qualifier */
    NULL                                    /* other speed config*/
/* End code block <4> auto generated code, DO NOT MODIFY LINES ABOVE */
/* write the specific descriptor pointer here*/
 ,(uint_8_ptr)g_report_descriptor
/* Begin of code block <5>  auto generated code, DO NOT MODIFY LINES BELOW */
};

uint_8 const g_string_desc_size[] = {
    sizeof(USB_STR_0),
    sizeof(USB_STR_1),
    sizeof(USB_STR_2),
    sizeof(USB_STR_n)
};

uint_8_ptr const g_string_descriptors[] = {
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
uint_8 USB_Desc_Get_Descriptor(uint_8 controller_ID, uint_8 type, uint_8 str_num, uint_16 index, uint_8_ptr *descriptor, USB_PACKET_SIZE *size)
{
    UNUSED (controller_ID)
    switch(type)
    {
/* End code block <5> auto generated code, DO NOT MODIFY LINES ABOVE */

      /* Write your own code here ... */
      /* ex
        case aaa:
          {
               // some code
          }
      */
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
                               ENDP_ONLY_DESC_SIZE
                               );
          *size = OTG_ONLY_DESC_SIZE;
        }
        break;
/* Begin of code block <6> auto generated code, DO NOT MODIFY LINES BELOW */
      case USB_STRING_DESCRIPTOR:
        {
            if(index == 0)
            {
                /* return the string and size of all languages */
                *descriptor = (uint_8_ptr)g_languages.
                languages_supported_string;
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
                *descriptor = (uint_8_ptr)g_languages.usb_language[lang_id].
                lang_desc[lang_index];
                *size = g_languages.usb_language[lang_id].
                lang_desc_size[lang_index];
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
/* End code block <6> auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write your own code here ... */


/* Begin of code block <7> auto generated code, DO NOT MODIFY LINES BELOW */
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
uint_8 USB_Desc_Get_Interface(uint_8 controller_ID, uint_8 interface, uint_8_ptr alt_interface)
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
boolean USB_Desc_Valid_Configation(uint_8 controller_ID, uint_16 config_val)
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
boolean USB_Desc_Valid_Interface(uint_8 controller_ID, uint_8 interface)
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
boolean USB_Desc_Remote_Wakeup(uint_8 controller_ID)
{
    UNUSED (controller_ID)
    return 0;
}

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
void* USB_Desc_Get_Endpoints(uint_8 controller_ID)
{
    UNUSED (controller_ID)
    return (void*)&usb_desc_ep;
}

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
uint_8 USB_Desc_Set_Interface(uint_8 controller_ID, uint_8 interface, uint_8 alt_interface)
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

/* End code block <7> auto generated code, DO NOT MODIFY LINES ABOVE */

/* Write your own code here ... */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
