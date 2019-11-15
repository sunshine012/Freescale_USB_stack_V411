/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_host_hub_sm.c
**     Project   : ProcessorExpert
**     Processor : MK60FN1M0LQ15
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:32, # CodeGen: 26
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "usb_host_hub.h"
#include "usb_host_hub_prv.h"
#include "usb_host_hub_sm.h"

static HUB_DEVICE_STRUCT_PTR  hubs = NULL;

static void usb_host_hub_device_sm(_usb_pipe_handle, pointer, pointer, uint_32, USB_STATUS);
static void usb_host_hub_int_callback(_usb_pipe_handle, pointer, pointer, uint_32, USB_STATUS);
static USB_STATUS usb_hub_wait_for_interrupt(HUB_DEVICE_STRUCT_PTR);

/*
** ===================================================================
**     Method      :  usb_host_hub_device_event (component USB_HOST_STACK)
**     Description :
**         called when a hub has been attached, detached, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**         dev_handle      - [IN] pointer to device
**                           instance
**         intf_handle     - [IN] pointer to interface
**                           descriptor
**         event_code      - [IN] code number for event
**                           causing callback
**     Returns     : Nothing
** ===================================================================
*/
void usb_host_hub_device_event(_usb_device_instance_handle dev_handle, _usb_interface_descriptor_handle intf_handle, uint_32 event_code)
{

    HUB_COMMAND hub_com;

    switch (event_code) {
    case USB_CONFIG_EVENT:
        /* Drop through into attach, same processing */
    case USB_ATTACH_EVENT: {
            HUB_DEVICE_STRUCT_PTR new_hub, hub_parser;

            new_hub = (HUB_DEVICE_STRUCT_PTR)malloc(sizeof(HUB_DEVICE_STRUCT));
            if (NULL == new_hub){
                break;
            }
            memset(new_hub, 0, sizeof(HUB_DEVICE_STRUCT));
            if (hubs == NULL)
            hubs = new_hub;
            else {
                for (hub_parser = hubs; hub_parser->CLASS_INTF.next != NULL; hub_parser = hub_parser->CLASS_INTF.next)
                /* void */;
                hub_parser->CLASS_INTF.next = new_hub;
            }

            new_hub->DEV_HANDLE = dev_handle;
            new_hub->INTF_HANDLE = intf_handle;
            _usb_hostdev_select_interface(dev_handle,
            intf_handle,
            (pointer)&new_hub->CLASS_INTF
            );
        }
        break;
    case USB_INTF_EVENT: {
            HUB_DEVICE_STRUCT_PTR hub_parser;

            for (hub_parser = hubs; hub_parser->INTF_HANDLE != NULL ; hub_parser = hub_parser->CLASS_INTF.next)
            if (hub_parser->INTF_HANDLE == intf_handle) {
                /* prepare buffer where to store data */
                /* allocate 7 bytes of descriptor to get its full size and number of ports */
                if (NULL == (hub_parser->control_buffer = malloc(7)))
                break;
                /* set we are in proceMss of getting hub descriptor */
                hub_parser->STATE = HUB_GET_DESCRIPTOR_TINY_PROCESS;
                hub_com.CLASS_PTR = (CLASS_CALL_STRUCT_PTR) &hub_parser->CLASS_INTF;
                hub_com.CALLBACK_FN = (tr_callback) usb_host_hub_device_sm;
                hub_com.CALLBACK_PARAM = (pointer) hub_parser;

                /* here, we should retrieve information from the hub */
                usb_class_hub_get_descriptor(&hub_com, hub_parser->control_buffer, 7);

                break;
            }
        }
        break;
    case USB_DETACH_EVENT: {
            HUB_DEVICE_STRUCT_PTR hub_previous, hub_parser;
            uint_16              i;

            /* find hub in the list */
            for (hub_previous = NULL, hub_parser = hubs; hub_parser->INTF_HANDLE != NULL ; hub_previous = hub_parser, hub_parser = hub_parser->CLASS_INTF.next)
            if (hub_parser->INTF_HANDLE == intf_handle) {
                /* found hub in the list, remove it from the list */
                if (hub_previous == NULL)
                hubs = hub_parser->CLASS_INTF.next;
                else
                hub_previous->CLASS_INTF.next = hub_parser->CLASS_INTF.next;
                /* detach all the devices connected to all the ports of found hub */
                for (i = 0; i < hub_parser->HUB_PORT_NR; i++) {
                    if ((hub_parser->HUB_PORTS + i)->APP_STATUS & APP_STATUS_ATTACHED)
                    usb_dev_list_detach_device(
                    ((USB_HUB_CLASS_INTF_STRUCT_PTR) hub_parser->CLASS_INTF.class_intf_handle)->G.host_handle,
                    ((DEV_INSTANCE_PTR) ((USB_HUB_CLASS_INTF_STRUCT_PTR) hub_parser->CLASS_INTF.class_intf_handle)->G.dev_handle)->address, /* hub address */
                    (uint_8)(i + 1) /* hub port */
                    );
                }
                if (hub_parser->control_buffer != NULL)
                free(hub_parser->control_buffer);
                if (hub_parser->interrupt_buffer != NULL)
                free(hub_parser->interrupt_buffer);
                if (hub_parser->HUB_PORTS != NULL)
                free(hub_parser->HUB_PORTS);
                free(hub_parser);
                break;
            }
        }
        break;
    default:
        break;
    }

}

/*
** ===================================================================
**     Method      :  usb_host_hub_device_sm (component USB_HOST_STACK)
**
**     Description :
**         This fucntion is called when a hub changes state; sm = state 
**         machine
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void usb_host_hub_device_sm
(
/* [IN] structure with USB pipe information on the interface */
_usb_pipe_handle  pipe,

/* [IN] parameters */
pointer           param,

/* [IN] buffer of data from IN stage */
pointer           buffer,

/* [IN] length of data from IN stage */
uint_32           len,

/* [IN] status of transaction */
USB_STATUS        status
)
{ /* Body */
    HUB_COMMAND                    hub_com;
    register HUB_DEVICE_STRUCT_PTR hub_instance = (HUB_DEVICE_STRUCT_PTR) param;
    uint_16                        i,j;

    UNUSED(len)
    UNUSED(status)
    hub_com.CLASS_PTR = (CLASS_CALL_STRUCT_PTR) &hub_instance->CLASS_INTF;
    hub_com.CALLBACK_FN = (tr_callback) usb_host_hub_device_sm;
    hub_com.CALLBACK_PARAM = (pointer) hub_instance;

    switch (hub_instance->STATE) {
    case HUB_GET_DESCRIPTOR_TINY_PROCESS:
        {
            /* here we get number of ports from USB data */
            hub_instance->HUB_PORT_NR = ((HUB_DESCRIPTOR_STRUCT_PTR) buffer)->BNRPORTS;
            free(buffer); /* USB_memfree(hub_instance->control_buffer) in fact */
            j = (uint_16)(hub_instance->HUB_PORT_NR / 8 + 8);
            hub_instance->control_buffer = malloc(j);
            if (NULL == (hub_instance->control_buffer))
            break;
            memset(hub_instance->control_buffer, 0, j);

            hub_instance->STATE = HUB_GET_DESCRIPTOR_PROCESS;
            usb_class_hub_get_descriptor(&hub_com, hub_instance->control_buffer, (uint_8)j);
            break;
        }

    case HUB_GET_DESCRIPTOR_PROCESS:
        {
            /* here, we get information from the hub and fill info in hub_instance */
            HUB_DESCRIPTOR_STRUCT_PTR hub_desc = (HUB_DESCRIPTOR_STRUCT_PTR) buffer;

            hub_instance->HUB_PORTS = malloc(hub_instance->HUB_PORT_NR * sizeof(HUB_PORT_STRUCT));
            if (NULL == hub_instance->HUB_PORTS){
                break;
            }

            memset(hub_instance->HUB_PORTS, 0, (hub_instance->HUB_PORT_NR * sizeof(HUB_PORT_STRUCT)));
            for (i = 0; i < hub_instance->HUB_PORT_NR; i++)
            {
                /* get REMOVABLE bit from the desriptor for appropriate installed port */
                (hub_instance->HUB_PORTS + i)->REMOVABLE = hub_desc->DEVICEREMOVABLE[(i + 1) / 8];
                (hub_instance->HUB_PORTS + i)->REMOVABLE &= (0x01 << ((i + 1) % 8));
                (hub_instance->HUB_PORTS + i)->APP_STATUS = 0x00;
            }

            free(buffer);  /* USB_mem_free(hub_instance->control_buffer) in fact */
        }

        /* pass fluently to HUB_SET_PORT_FEATURE_PROCESS */
        hub_instance->STATE = HUB_SET_PORT_FEATURE_PROCESS;
        hub_instance->port_iterator = 0;
    case HUB_SET_PORT_FEATURE_PROCESS:
        if (hub_instance->port_iterator < hub_instance->HUB_PORT_NR)
        {
            usb_class_hub_set_port_feature(&hub_com, (uint_8)(++hub_instance->port_iterator), PORT_POWER);
            break;
        } /* EndIf */
        /* else */

        /* pass fluently to HUB_CLEAR_PORT_FEATURE_PROCESS */
        hub_instance->STATE = HUB_CLEAR_PORT_FEATURE_PROCESS;
        hub_instance->port_iterator = 0;
    case HUB_CLEAR_PORT_FEATURE_PROCESS:
        if (hub_instance->port_iterator < hub_instance->HUB_PORT_NR)
        {
            usb_class_hub_clear_port_feature(&hub_com, (uint_8)(++hub_instance->port_iterator), C_PORT_CONNECTION);
            break;
        } /* EndIf */
        /* else */

        /* pass fluently to HUB_GET_PORT_STATUS_PROCESS */
        if (NULL == (hub_instance->control_buffer = malloc(4)))
        break;
        hub_instance->STATE = HUB_GET_PORT_STATUS_PROCESS;
        hub_instance->port_iterator = 0;
    case HUB_GET_PORT_STATUS_PROCESS:
        if (hub_instance->port_iterator)
        /* register the current status of the port, do the conversion LSB -> MSB */
        (hub_instance->HUB_PORTS + hub_instance->port_iterator - 1)->STATUS = utoh16((uint_8 _PTR_) buffer);
        if (hub_instance->port_iterator < hub_instance->HUB_PORT_NR)
        {
            usb_class_hub_get_port_status(&hub_com, (uint_8)(++hub_instance->port_iterator), hub_instance->control_buffer, 4);
            break;
        } /* EndIf */
        /* else */
        j = (uint_16)(hub_instance->HUB_PORT_NR / 8 + 1);
        hub_instance->interrupt_buffer = malloc(j);
        if (NULL == hub_instance->interrupt_buffer)
        break;
        memset(hub_instance->interrupt_buffer, 0, j);

        /* test if device is attached since startup */
        for (i = 0; i < hub_instance->HUB_PORT_NR; i++)
        if ((hub_instance->HUB_PORTS + i)->STATUS & (1 << PORT_CONNECTION))
        {
            USB_STATUS s;

            /* if some device is attached since startup, then start session */
            hub_instance->port_iterator = i;
            hub_instance->STATE = HUB_NONE;
            (hub_instance->HUB_PORTS + i)->APP_STATUS |= APP_STATUS_ATTACHED;
            s = usb_class_hub_set_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1),PORT_RESET);
            break;
        }

        usb_hub_wait_for_interrupt(hub_instance);
        break;

    case HUB_RESET_DEVICE_PORT_PROCESS:
        hub_instance->STATE = HUB_NONE;

        usb_class_hub_set_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), PORT_RESET);

        usb_hub_wait_for_interrupt(hub_instance);
        break;

    case HUB_ADDRESS_DEVICE_PORT_PROCESS:
        /* compute speed */
        if ((hub_instance->HUB_PORTS + hub_instance->port_iterator)->STATUS & (1 << PORT_HIGH_SPEED))
        i = USB_SPEED_HIGH;
        else if ((hub_instance->HUB_PORTS + hub_instance->port_iterator)->STATUS & (1 << PORT_LOW_SPEED))
        i = USB_SPEED_LOW;
        else
        i = USB_SPEED_FULL;

        usb_dev_list_attach_device(
        ((USB_HUB_CLASS_INTF_STRUCT_PTR) hub_instance->CLASS_INTF.class_intf_handle)->G.host_handle,
        (uint_8)i, /* port speed */
        ((PIPE_INIT_PARAM_STRUCT_PTR) pipe)->DEVICE_ADDRESS, /* hub address */
        (uint_8)(hub_instance->port_iterator + 1) /* hub port */
        );

        /* test if there is still device which was not reset */
        for (i = 0; i < hub_instance->HUB_PORT_NR; i++)
        if (((hub_instance->HUB_PORTS + i)->STATUS & (1 << PORT_CONNECTION)) && !((hub_instance->HUB_PORTS + i)->APP_STATUS & APP_STATUS_ATTACHED))
        {
            USB_STATUS s;
            /* if some device is attached since startup, then start session */
            hub_instance->port_iterator = i;
            hub_instance->STATE = HUB_NONE;
            (hub_instance->HUB_PORTS + i)->APP_STATUS |= APP_STATUS_ATTACHED;
            s = usb_class_hub_set_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), PORT_RESET);
            break;
        }

        usb_hub_wait_for_interrupt(hub_instance);
        break;

    case HUB_DETACH_DEVICE_PORT_PROCESS:
        usb_dev_list_detach_device(
        ((USB_HUB_CLASS_INTF_STRUCT_PTR) hub_instance->CLASS_INTF.class_intf_handle)->G.host_handle,
        ((PIPE_INIT_PARAM_STRUCT_PTR) pipe)->DEVICE_ADDRESS, /* hub address */
        (uint_8)(hub_instance->port_iterator + 1) /* hub port */
        );

        /* reset the app status */
        (hub_instance->HUB_PORTS + hub_instance->port_iterator)->APP_STATUS = 0x00;

        /* test if there is still device which was not reset */
        for (i = 0; i < hub_instance->HUB_PORT_NR; i++)
        if (((hub_instance->HUB_PORTS + i)->STATUS & (1 << PORT_CONNECTION)) && !((hub_instance->HUB_PORTS + i)->APP_STATUS & APP_STATUS_ATTACHED))
        {
            USB_STATUS s;

            /* if some device is attached since startup, then start session */
            hub_instance->port_iterator = i;
            hub_instance->STATE = HUB_NONE;
            (hub_instance->HUB_PORTS + i)->APP_STATUS |= APP_STATUS_ATTACHED;
            s = usb_class_hub_set_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), PORT_RESET);
            break;
        }

        usb_hub_wait_for_interrupt(hub_instance);
        break;

    case HUB_GET_PORT_STATUS_ASYNC:
        {
            uint_32 stat = utoh32((uint_8 _PTR_) buffer);

            /* register the current status of the port */
            (hub_instance->HUB_PORTS + hub_instance->port_iterator)->STATUS = (uint_16)stat;

            /* let's see what happened */
            if ((1 << C_PORT_CONNECTION) & stat)
            {
                /* get if a device on port was attached or detached */
                if ((hub_instance->HUB_PORTS + hub_instance->port_iterator)->APP_STATUS & APP_STATUS_ATTACHED)
                {
                    hub_instance->STATE = HUB_DETACH_DEVICE_PORT_PROCESS;
                    usb_class_hub_clear_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), C_PORT_CONNECTION);
                }
                else
                {
                    hub_instance->STATE = HUB_RESET_DEVICE_PORT_PROCESS;
                    usb_class_hub_clear_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), C_PORT_CONNECTION);
                }
                break;
            }
            else if ((1 << C_PORT_RESET) & stat)
            {
                hub_instance->STATE = HUB_ADDRESS_DEVICE_PORT_PROCESS;
                (hub_instance->HUB_PORTS + hub_instance->port_iterator)->APP_STATUS |= APP_STATUS_ATTACHED;
                usb_class_hub_clear_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), C_PORT_RESET);
                break;
            }
            else if ((1 << C_PORT_ENABLE) & stat)
            {
                /* unexpected event (error), just ignore the port */
                hub_instance->STATE = HUB_DETACH_DEVICE_PORT_PROCESS;
                usb_class_hub_clear_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), C_PORT_ENABLE);
                break;
            }
            else if ((1 << C_PORT_OVER_CURRENT) & stat)
            {
                /* unexpected event (error), just ignore the port */
                hub_instance->STATE = HUB_NONE;
                usb_class_hub_clear_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), C_PORT_OVER_CURRENT);
                usb_hub_wait_for_interrupt(hub_instance);
                break;
            }
            else if ((1 << C_PORT_POWER) & stat)
            {
                /* unexpected event (error), just ignore the port */
                hub_instance->STATE = HUB_NONE;
                usb_class_hub_clear_port_feature(&hub_com, (uint_8)(hub_instance->port_iterator + 1), C_PORT_POWER);
                usb_hub_wait_for_interrupt(hub_instance);
                break;
            }
            /* FIXME: handle more events */

            break;

        }

    } /* EndSwitch */
    return;
} /* EndBody */

/*
** ===================================================================
**     Method      :  usb_host_hub_int_callback (component USB_HOST_STACK)
**
**     Description :
**         This fucntion is called on interrupt endpoint data reception
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void usb_host_hub_int_callback
(
/* [IN] pointer to pipe */
_usb_pipe_handle  pipe,

/* [IN] user-defined parameter */
pointer           param,

/* [IN] buffer address */
pointer           buffer,

/* [IN] length of data transferred */
uint_32           len,

/* [IN] status, hopefully USB_OK or USB_DONE */
uint_32           status
)
{ /* Body */
    HUB_DEVICE_STRUCT_PTR          hub_instance = (HUB_DEVICE_STRUCT_PTR) param;
    USB_HUB_CLASS_INTF_STRUCT_PTR  if_ptr;
    uint_16                       i, j, port;
    uint_8 _PTR_                   port_pattern= (uint_8 _PTR_) buffer;
    HUB_COMMAND                    hub_com;

    UNUSED(pipe)
    UNUSED(status)
    USB_lock();

    /* Validity checking, always needed when passing data to lower API */
    if (usb_host_class_intf_validate(&hub_instance->CLASS_INTF)) {
        if_ptr = (USB_HUB_CLASS_INTF_STRUCT_PTR) hub_instance->CLASS_INTF.class_intf_handle;
        if(USB_OK != usb_hostdev_validate(if_ptr->G.dev_handle)) {
            USB_unlock();
            return;
        }

        if_ptr->INT_PIPE = 0; /* mark we are not using interrupt pipe */

        USB_unlock();
        /* find which port changed its state */
        for (i = 0; i < len; i++)
        {
            if (!port_pattern[i])
            continue;
            port = (uint_16)(i<<3);
            for (j = 0; j < 8; j++, port++)
            {
                if (port_pattern[i] & 0x01)
                break;
                port_pattern[i] >>= 1;
            }
            break;
        }

        /* The port number, which changed status, is written in variable "port"
        ** Note, that if there are more ports, which changed its status, these will
        ** be invoked later (in next interrupt)
        */

        hub_com.CLASS_PTR = (CLASS_CALL_STRUCT_PTR) &hub_instance->CLASS_INTF;
        hub_com.CALLBACK_FN = (tr_callback) usb_host_hub_device_sm;
        hub_com.CALLBACK_PARAM = (pointer) hub_instance;

        hub_instance->STATE = HUB_GET_PORT_STATUS_ASYNC;
        hub_instance->port_iterator = (uint_16)(port - 1);
        usb_class_hub_get_port_status(&hub_com, (uint_8)port, hub_instance->control_buffer, 4);

    }
    else
    USB_unlock();
} /*EndBody */

/*
** ===================================================================
**     Method      :  usb_hub_wait_for_interrupt (component USB_HOST_STACK)
**
**     Description :
**         Starts interrupt endpoint to poll for interrupt on specified 
**         hub
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static USB_STATUS usb_hub_wait_for_interrupt
(
/* hub device instance */
HUB_DEVICE_STRUCT_PTR      hub_instance
)
{ /* Body */
    USB_HUB_CLASS_INTF_STRUCT_PTR  if_ptr;
    TR_INIT_PARAM_STRUCT           tr;
    USB_STATUS                     status = USBERR_NO_INTERFACE;

    USB_lock();
    /* Validity checking, always needed when passing data to lower API */
    if (usb_host_class_intf_validate(&hub_instance->CLASS_INTF)) {
        if_ptr = (USB_HUB_CLASS_INTF_STRUCT_PTR) hub_instance->CLASS_INTF.class_intf_handle;
        status = usb_hostdev_validate(if_ptr->G.dev_handle);
    }

    if (!status && !if_ptr->INT_PIPE) {
        if_ptr->INT_PIPE = 1; /* mark we are using interrupt pipe */
        usb_hostdev_tr_init(&tr, (tr_callback)usb_host_hub_int_callback, (pointer) hub_instance);
        tr.RX_BUFFER = hub_instance->interrupt_buffer;
        tr.RX_LENGTH = (uint_32)(hub_instance->HUB_PORT_NR / 8 + 1);
        status = _usb_host_recv_data(
        if_ptr->G.host_handle,
        if_ptr->P_INT_IN,
        &tr
        );
    }

    USB_unlock();

    return status;
}
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
