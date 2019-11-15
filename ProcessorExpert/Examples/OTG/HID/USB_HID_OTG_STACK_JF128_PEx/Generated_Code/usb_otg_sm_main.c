/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_otg_sm_main.c
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
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO_Map.h"
#include "usb.h"
#include "usb_devapi.h"
#include "host_dev_list.h"
#include "host_common.h"
#include "usbprv_host.h"
#include "usbevent.h"
#include "usb_otg_main.h"
#include "usb_otg_max3353.h"
#include "usb_otg_sm.h"
#include "host_dev_list.h"
#include "usb_otg_private.h"
extern LDD_TDeviceData  *USB_LDD_DevDataPtr;
/* Internal method prototypes */
void _usb_otg_a_change_state(_usb_otg_handle otg_handle , uint_32 new_state  );
void _usb_otg_b_change_state(_usb_otg_handle otg_handle, uint_32 new_state);
/*
** ===================================================================
**     Method      :  _usb_otg_sm (component USB_OTG_STACK)
**     Description :
**         Handles the changes in OTG status
**     Parameters  :
**         NAME            - DESCRIPTION
**         otg_handle      - 
**         new_state       - 
**     Returns     : Nothing
** ===================================================================
*/
void _usb_otg_sm(_usb_otg_handle otg_handle, uint_32 new_state)
{
    _usb_otg_a_change_state(otg_handle ,new_state  );
    _usb_otg_b_change_state(otg_handle ,new_state);
}
/*
** ===================================================================
**     Method      :  _usb_otg_a_change_state (component USB_OTG_STACK)
**     Description :
**         This function handles the actions performed at A substate
**         change
**     Parameters  :
**         NAME            - DESCRIPTION
**         otg_handle      - 
**         new_state       - 
**     Returns     : Nothing
** ===================================================================
*/
void _usb_otg_a_change_state(_usb_otg_handle otg_handle, uint_32 new_state)
{
    USB_OTG_STRUCT *usb_otg_struct_ptr = (USB_OTG_STRUCT *)otg_handle;
    switch(new_state)
    {
    case OTG_A_IDLE:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_IDLE;
        USB_LDD_OtgCmd(USB_LDD_DevDataPtr, LDD_USB_OTG_CMD_SET_A_BUS_REQUEST);
        break;
    case OTG_A_WAIT_VRISE:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_WAIT_VRISE;
        usb_otg_struct_ptr->init_struct->ext_set_VBUS(TRUE);
        break;
    case OTG_A_WAIT_BCON:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_WAIT_BCON;
        break;
    case OTG_A_VBUS_ERR:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_VBUS_ERR;
        usb_otg_struct_ptr->init_struct->ext_set_VBUS(FALSE);
        break;
    case OTG_A_WAIT_VFALL:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_WAIT_VFALL;
        usb_otg_struct_ptr->init_struct->ext_set_VBUS(FALSE);
        break;
    case OTG_A_HOST:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_HOST;
        {
            uint_32 error;
            error = usb_otg_struct_ptr->init_struct->load_usb_host();
        }
        break;
    case OTG_A_SUSPEND:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_SUSPEND;
        break;
    case OTG_A_PERIPHERAL:
        usb_otg_struct_ptr->subState = USB_OTG_SM_A_PERIPHERAL;
        usb_otg_struct_ptr->init_struct->load_usb_device();
        break;
    }
}

/*
** ===================================================================
**     Method      :  _usb_otg_b_change_state (component USB_OTG_STACK)
**     Description :
**         This function handles the actions performed at B substate
**         change
**     Parameters  :
**         NAME            - DESCRIPTION
**         otg_handle      - 
**         new_state       - 
**     Returns     : Nothing
** ===================================================================
*/
void _usb_otg_b_change_state(_usb_otg_handle otg_handle, uint_32 new_state)
{
    USB_OTG_STRUCT *usb_otg_struct_ptr = (USB_OTG_STRUCT *)otg_handle;
    switch(new_state)
    {
    case OTG_B_PERIPHERAL:

        /* Load the Peripheral stack */
        if(usb_otg_struct_ptr->init_struct->ext_set_pdowns != (otg_ext_set_pdowns)NULL)
        {
            usb_otg_struct_ptr->init_struct->ext_set_pdowns(OTG_CTRL_PDOWN_DM);
        }
        usb_otg_struct_ptr->init_struct->load_usb_device();

        break;

    case OTG_B_HOST:
        /* Unload the active USB stack if any. Most probably the peripheral stack is active */
        if(usb_otg_struct_ptr->init_struct->ext_set_pdowns != (otg_ext_set_pdowns)NULL)
        {
            usb_otg_struct_ptr->init_struct->ext_set_pdowns( OTG_CTRL_PDOWN_DP | OTG_CTRL_PDOWN_DM);
        }
        /* Load the Host stack */
        usb_otg_struct_ptr->init_struct->load_usb_host();

        break;

        default :   break;
    }
    usb_otg_struct_ptr->subState = new_state;
}
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
