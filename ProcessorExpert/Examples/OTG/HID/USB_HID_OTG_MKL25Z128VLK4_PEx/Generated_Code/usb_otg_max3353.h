/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_otg_max3353.h
**     Project   : ProcessorExpert
**     Processor : MKL25Z128LK4
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/
#ifndef _USB_OTG_MAX3353_H_
#define _USB_OTG_MAX3353_H_
#include "PE_Types.h"
/* Public constants */
#define MAX3353_MID                         (0x6A0B5333)
#define MAX3353_PID                         (0x485A4200)

#define ID_GND_EVENT                        (0x20)
#define ID_FLOAT_EVENT                      (0x40)
#define VBUS_LOW_EVENT                      (0x10)
#define VBUS_HIGH_EVENT                     (0x01)

#define ID_FLOAT_EN_MASK                    (0x10)
#define ID_GND_EN_MASK                      (0x08)
#define VBUS_VALID_EN_MASK                  (0x01)
#define SESSION_SESSEND_EN_MASK             (0x04)
#define SESSION_VALID_EN_MASK               (0x01)

#define VBUS_VALID_ED_MASK                  (0x01)
#define SESSION_VALID_ED_MASK               (0x02)
#define MAX3353_I2C_ADDRESS                 (0x2C)
/* MAX3353 I2C slave address */
#define MAX3353_SLAVE_ADDR                  (0x2C)

/* MAX3353 Registers */
#define MAX3353_REG_MANU_0                  (0x00)
#define MAX3353_REG_MANU_1                  (0x01)
#define MAX3353_REG_MANU_2                  (0x02)
#define MAX3353_REG_MANU_3                  (0x03)
#define MAX3353_REG_PRODID_0                (0x04)
#define MAX3353_REG_PRODID_1                (0x05)
#define MAX3353_REG_PRODID_2                (0x06)
#define MAX3353_REG_PRODID_3                (0x07)
#define MAX3353_REG_CTRL_1                  (0x10)
#define MAX3353_REG_CTRL_2                  (0x11)
#define MAX3353_REG_STATUS                  (0x13)
#define MAX3353_REG_INT_MASK                (0x14)
#define MAX3353_REG_INT_EDGE                (0x15)
#define MAX3353_REG_INT_LATCH               (0x16)

/* MAX3353 register bits */
#define OTG_STAT_VBUS_VALID                 (0x01)
#define OTG_STAT_SESS_VALID                 (0x02)
#define OTG_STAT_SESS_END                   (0x04)
#define OTG_STAT_ID_GND                     (0x08)
#define OTG_STAT_ID_FLOAT                   (0x10)
#define OTG_STAT_A_HNP                      (0x20)
#define OTG_STAT_B_HNP                      (0x40)

#define OTG_INT_VBUS_VALID_CHG              (0x01)
#define OTG_INT_SESS_VALID_CHG              (0x02)
#define OTG_INT_SESS_END_CHG                (0x10)
#define OTG_INT_ID_GND_CHG                  (0x20)
#define OTG_INT_ID_FLOAT_CHG                (0x40)
#define OTG_INT_A_HNP_CHG                   (0x80)

#define OTG_CTRL_2_SDWN                     (0x01)
#define OTG_CTRL_2_VBUS_CHG1                (0x02)
#define OTG_CTRL_2_VBUS_CHG2                (0x04)
#define OTG_CTRL_2_VBUS_DRV                 (0x08)
#define OTG_CTRL_2_VBUS_DISCHG              (0x10)

#define OTG_CTRL_1_IRQ_PUSH_PULL            (0x02)
#define OTG_CTRL_1_PDOWN_DP                 (0x40)
#define OTG_CTRL_1_PDOWN_DM                 (0x80)

#define ENABLE_USB_5V                       GPIOB_PSOR|=(1<<9);
#define DISABLE_USB_5V                      GPIOB_PCOR|=(1<<9);
enum
{
    MAX3353_OK,
    MAX3353_NOT_PRESENT
};
/* Internal method prototypes */
void _otg_max3353_enable_disable(boolean enable);
/*
** ===================================================================
**     Method      :  _otg_max3353_enable_disable (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         enable          - 
**     Returns     : Nothing
** ===================================================================
*/

uint_8 _otg_max3353_get_status(void);
/*
** ===================================================================
**     Method      :  _otg_max3353_get_status (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint_8 _otg_max3353_get_interrupts(void);
/*
** ===================================================================
**     Method      :  _otg_max3353_get_interrupts (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void _otg_max3353_set_VBUS(boolean enable);
/*
** ===================================================================
**     Method      :  _otg_max3353_set_VBUS (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         enable          - 
**     Returns     : Nothing
** ===================================================================
*/

void _otg_max3353_set_pdowns(uint_8 bitfield);
/*
** ===================================================================
**     Method      :  _otg_max3353_set_pdowns (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         bitfield        - 
**     Returns     : Nothing
** ===================================================================
*/

#endif  /* _USB_OTG_MAX3353_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
