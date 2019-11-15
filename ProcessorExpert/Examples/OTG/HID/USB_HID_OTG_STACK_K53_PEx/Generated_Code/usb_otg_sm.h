/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_otg_sm.h
**     Project   : ProcessorExpert
**     Processor : MK53N512MD100
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef USB_OTG_SM_H_
#define USB_OTG_SM_H_
/* Timeout definitions in ms */
#define TB_SESSEND_SRP                      (1500)
#define TB_SE0_SRP                          (1000)
#define TB_DATA_PLS                         (7)
#define TB_DATA_PLS_MIN                     (5)
#define TB_DATA_PLS_MAX                     (10)
#define TB_SRP_FAIL                         (5500)
#define TB_AIDL_BDIS                        (5)
#define TB_ASE0_BRST                        (155)

#define TA_VBUS_RISE                        (100)
#define TA_VBUS_FALL                        (1000)
#define TA_WAIT_BCON                        (2000)
#define TA_AIDL_BDIS                        (500)
#define TA_SUSPEND_RESUME                   (2)

#define TA_BIDL_ADIS                        (190)
#define TA_BCON_LDB                         (100)
#define TA_BCON_SDB                         (1)
#define TA_BCON_SDB_WIN                     (100)
#define T_HOST_REQ_POLL                     (1500)

/* USB OTG SM state definitions */
#define USB_OTG_DEVSTATE_UNDEFINED          (0xFF)
#define USB_OTG_DEVSTATE_B                  (0x00)
#define USB_OTG_DEVSTATE_A                  (0x01)

#define USB_OTG_SM_UNDEFINED                (0xFF)

#define USB_OTG_SM_B_IDLE_SESS_DETECT       (0x00)
#define USB_OTG_SM_B_IDLE_SESS_END_DETECT   (0x01)
#define USB_OTG_SM_B_IDLE_SE0_STABLE_WAIT   (0x02)
#define USB_OTG_SM_B_IDLE_SRP_START_ARMED   (0x03)

#define USB_OTG_SM_B_SRP_PULSE              (0x10)
#define USB_OTG_SM_B_SRP_VBUS_WAIT          (0x11)

#define USB_OTG_SM_B_PERI_BUS_SUSP_DETECT   (0x20)
#define USB_OTG_SM_B_PERI_BUS_SUSP_WAIT     (0x21)
#define USB_OTG_SM_B_PERI_HNP_ARMED         (0x22)
#define USB_OTG_SM_B_PERI_HNP_START         (0x23)
#define USB_OTG_SM_B_PERI_HNP_ACONN         (0x24)
#define USB_OTG_SM_B_HOST                   (0x30)

#define USB_OTG_SM_A_IDLE                   (0x00)
#define USB_OTG_SM_A_WAIT_VRISE             (0x01)
#define USB_OTG_SM_A_WAIT_BCON              (0x02)
#define USB_OTG_SM_A_VBUS_ERR               (0x03)
#define USB_OTG_SM_A_WAIT_VFALL             (0x04)

#define USB_OTG_SM_A_HOST                   (0x10)
#define USB_OTG_SM_A_SUSPEND                (0x20)
#define USB_OTG_SM_A_SUSPEND_RESUME         (0x21)
#define USB_OTG_SM_A_PERIPHERAL             (0x30)
/* Internal method prototypes */
void _usb_otg_sm(_usb_otg_handle otg_handle, uint_32 new_state);
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

#endif /* USB_OTG_SM_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
