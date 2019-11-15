/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_cdc_pstn.h
**     Project   : ProcessorExpert
**     Processor : MCF51JF128_64
**     Component : USB_CDC_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 09:44, # CodeGen: 11
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef _USB_CDC_PSTN_H
#define _USB_CDC_PSTN_H

 #include "usb_cdc.h" /* USB CDC Class Header File */

/******************************************************************************
 * Macro's
 *****************************************************************************/
#define UART_BITMAP_SIZE           (0x02)
#define ABSTRACT_STATE_FEATURE     (0x01)
#define COUNTRY_SETTING_FEATURE    (0x02)
#define CARRIER_ACTIVATION_CHECK   (0x02)
#define DTE_PRESENCE_CHECK         (0x01)

typedef struct _BITMAP_UART
{
    uint_8 bRxCarrier   : 1;    /* Receive Carrier Activation Flag */
    uint_8 bTxCarrier   : 1;    /* Transmit Carrier Activation Flag */
    uint_8 bBreak       : 1;    /* Break Flag */
    uint_8 bRingSignal  : 1;    /* Ring Signal Flag */
    uint_8 bFraming     : 1;    /* Frame Flag */
    uint_8 bParity      : 1;    /* Parity Flag */
    uint_8 bOverRun     : 1;    /* OverRun Flag */
    uint_8 reserved1    : 1;    /* Reserved */
}BITMAP_UART;


typedef union _UART_BITMAP
{
    uint_8 _byte;
    BITMAP_UART Bitmap_Uart;
}UART_BITMAP;   /* UART STATE BITMAP */


uint_8 USB_Class_CDC_Pstn_Init(uint_8 controller_ID, USB_CLASS_CALLBACK callback);
/*
** ===================================================================
**     Method      :  usb_cdc_USB_Class_CDC_Pstn_Init (component USB_CDC_CLASS)
**
**     Description :
**         The funtion initializes the PSTN Module
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**         callback        - [IN] PSTN Callback
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_CDC_PSTN_Get_Line_Coding(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
/*
** ===================================================================
**     Method      :  USB_Class_CDC_PSTN_Get_Line_Coding (component USB_CDC_CLASS)
**     Description :
**         This function is called in response to GetLineCoding request
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data to be send
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_CDC_PSTN_Set_Line_Coding(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
/*
** ===================================================================
**     Method      :  USB_Class_CDC_PSTN_Set_Line_Coding (component USB_CDC_CLASS)
**     Description :
**         This function is called in response to SetLineCoding request
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data to be send
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_CDC_PSTN_Set_Ctrl_Line_State(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
/*
** ===================================================================
**     Method      :  USB_Class_CDC_PSTN_Set_Ctrl_Line_State (component USB_CDC_CLASS)
**     Description :
**         This function is called in response to Set Control Line State
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data to be send
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_CDC_PSTN_Send_Break(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
/*
** ===================================================================
**     Method      :  USB_Class_CDC_PSTN_Send_Break (component USB_CDC_CLASS)
**     Description :
**         This function is called in response to Set Config request
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data to be send
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_CDC_PSTN_Get_Comm_Feature(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
/*
** ===================================================================
**     Method      :  usb_cdc_USB_Class_CDC_PSTN_Get_Comm_Feature (component USB_CDC_CLASS)
**
**     Description :
**         This function is called in response to Set Config request
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data to be send
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 USB_Class_CDC_PSTN_Set_Comm_Feature(uint_8 controller_ID, USB_SETUP_STRUCT *setup_packet, uint_8_ptr *data, USB_PACKET_SIZE *size);
/*
** ===================================================================
**     Method      :  usb_cdc_USB_Class_CDC_PSTN_Set_Comm_Feature (component USB_CDC_CLASS)
**
**     Description :
**         This function is called in response to SetCommFeature request
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**       * setup_packet    - [IN] Pointer to setup
**                           packet
**       * data            - [OUT] Pointer to Data to be send
**       * size            - [OUT] Pointer to Size of Data
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void USB_Class_CDC_PSTN_Send_Serial_State(uint_8 controller_ID);
/*
** ===================================================================
**     Method      :  USB_Class_CDC_PSTN_Send_Serial_State (component USB_CDC_CLASS)
**     Description :
**         This function is called to send serial state notification
**     Parameters  :
**         NAME            - DESCRIPTION
**         controller_ID   - [IN] Controller ID
**     Returns     : Nothing
** ===================================================================
*/

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale ColdFirePlus series of microcontrollers.
**
** ###################################################################
*/
