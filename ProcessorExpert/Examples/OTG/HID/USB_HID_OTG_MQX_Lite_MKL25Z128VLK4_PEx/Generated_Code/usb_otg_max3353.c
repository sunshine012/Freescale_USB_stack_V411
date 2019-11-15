/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : usb_otg_max3353.c
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
#include "types.h"
#include "usb_otg_max3353.h"
#include "usb_otg_main.h"
#include "USB_LDD.h"
/* MAX5335 register addresses */
#define MAX3353_MAN_0_REG              0x00
#define MAX3353_MAN_1_REG              0x01
#define MAX3353_MAN_2_REG              0x02
#define MAX3353_MAN_3_REG              0x03
#define MAX3353_ID_0_REG               0x04
#define MAX3353_ID_1_REG               0x05
#define MAX3353_ID_2_REG               0x06
#define MAX3353_ID_3_REG               0x07
#define MAX3353_CTRL_1_REG             0x10
#define MAX3353_CTRL_2_REG             0x11
#define MAX3353_STAT_REG               0x13
#define MAX3353_INT_MASK_REG           0x14
#define MAX3353_INT_EDGE_REG           0x15
#define MAX3353_INT_LATCH_REG          0x16

/* MAX5335 CTRL1 register bits */
#define MAX3353_DP_PU_SIGNAL           0x10
#define MAX3353_DM_PU_SIGNAL           0x20
#define MAX3353_DP_PD_SIGNAL           0x40
#define MAX3353_DM_PD_SIGNAL           0x80

/* MAX5335 CTRL2 register bits */
#define MAX3353_VBUS_CHARGE_SIGNAL     0x04
#define MAX3353_VBUS_DRV_SIGNAL        0x08
#define MAX3353_VBUS_DISCHARGE_SIGNAL  0x10
/* Global variables **********************************************************/
uint32_t                 MAX3353_Ctrl1_RegVal;
uint32_t                 MAX3353_Ctrl2_RegVal;
uint_32                  u32ID=0;
extern LDD_TDeviceData   *USB_LDD_DevDataPtr;
LDD_TDeviceData          *I2CDevDataPtr;
/* Internal method prototypes */
static void           MAX3353_Init(void);
static LDD_TError     MAX3353_WriteReg(byte RegAddres, byte RegVal);
static LDD_TError     MAX3353_ReadReg(byte RegAddres, byte* VarAddress);
void                  MAX3353_SetUsbOutputSignal(LDD_TPinMask, LDD_TPinMask);
void                  MAX3353_GetUsbInputSignal(void);
uint_8                _otg_max3353_get_interrupts(void);
void                  _otg_max3353_enable_disable(boolean enable);
uint_8                _otg_max3353_get_status(void);
void                  _otg_max3353_set_VBUS(boolean enable);
void                  _otg_max3353_set_pdowns(uint_8 bitfield);
/*
** ===================================================================
**     Method      :  MAX3353_Init (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MAX3353_Init(void)
{
    uint8_t RegVal;

    I2CDevDataPtr = OTG_MAX3353_Init(NULL);
    /* Write CTRL1 = 1 */
    MAX3353_Ctrl1_RegVal = 1;
    MAX3353_WriteReg(MAX3353_CTRL_1_REG, (uint8_t)MAX3353_Ctrl1_RegVal);
    /* Write CTRL2 = 0 - Power on */
    MAX3353_Ctrl2_RegVal = 0;
    MAX3353_WriteReg(MAX3353_CTRL_2_REG, (uint8_t)MAX3353_Ctrl2_RegVal);
    /* Write INT_EDGE = 0x01 - VBUS valid -  positiv edge, Session valid - negativ edge */
    MAX3353_WriteReg(MAX3353_INT_EDGE_REG,0x01);
    /* Clear interrupt flags */
    MAX3353_ReadReg(MAX3353_INT_LATCH_REG,(byte*)&RegVal);
    /* Write INT_MASK = 0x00 - Disable all interrupts */
    MAX3353_WriteReg(MAX3353_INT_MASK_REG,0x00);
    (void)OTG_MAX3353_INT_PIN_Init(NULL);
}

LDD_TError MAX3353_WriteReg(byte RegAddres, byte RegVal)
{
    byte data[2];
    LDD_TError res;
    LDD_I2C_TBusState BusState;

    data[0] = RegAddres;
    data[1] = RegVal;

    res = OTG_MAX3353_MasterSendBlock(I2CDevDataPtr, data, 2, LDD_I2C_SEND_STOP);
    if (res == ERR_OK) {
        while (!OTG_MAX3353_MasterGetBlockSentStatus(I2CDevDataPtr)) {
            #ifdef OTG_MAX3353_Main_METHOD_ENABLED
            OTG_MAX3353_Main(I2CDevDataPtr);
            #endif
        };
    } else {
        return res;
    }

    do {
        (void)OTG_MAX3353_CheckBus(I2CDevDataPtr,&BusState);
    } while(BusState == LDD_I2C_BUSY);

    (void)OTG_MAX3353_GetError(I2CDevDataPtr, &res);
    return res;
}

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
void _otg_max3353_enable_disable(boolean enable)
{
    volatile uint_8 MAX3353_data;
    MAX3353_Init();
    if(enable)
    {
        MAX3353_data = 0x02;
        while(MAX3353_WriteReg(MAX3353_REG_CTRL_1, MAX3353_data) != ERR_OK){}
        MAX3353_data = 0x1F; /* Enable interrupts */
        while(MAX3353_WriteReg(MAX3353_REG_INT_MASK, MAX3353_data) != ERR_OK){}
        MAX3353_data = 0x00;  /* Enable module. */
    }
    else
    {
        MAX3353_data = 1;  /* Activate shutdown */
    }

    /* Enable/Disable module */
    while(MAX3353_WriteReg(MAX3353_REG_CTRL_2, MAX3353_data) != ERR_OK){}

    /* Read the latch to clear any pending interrupts */
    (void)_otg_max3353_get_interrupts();
}
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
uint_8 _otg_max3353_get_status(void)
{
    uint_8 status;
    uint_8 edge, new_edge;

    while(MAX3353_ReadReg(MAX3353_REG_STATUS, &status) != ERR_OK){}

    /* Handle here the edge detection in SessionValid and VBus valid */

    /* Read the current edge */
    while(MAX3353_ReadReg(MAX3353_REG_INT_EDGE, &edge) != ERR_OK){}

    new_edge = (uint_8)((~(status)) & 0x03);

    if(new_edge != edge)
    {
        /* Write the new edges */
        while(MAX3353_WriteReg(MAX3353_REG_INT_EDGE, new_edge) != ERR_OK){}
    }

    return status;
}

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
uint_8 _otg_max3353_get_interrupts(void)
{
    uint_8 data;

    while(MAX3353_ReadReg(MAX3353_REG_INT_LATCH, &data) != ERR_OK){}

    return data;
}

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
void _otg_max3353_set_VBUS(boolean enable)
{
    volatile uint_8 MAX3353_data;

    if(enable)
    {
        MAX3353_data = OTG_CTRL_2_VBUS_DRV;/* connect VBUS to the charge pump */
    }
    else
    {
        MAX3353_data = OTG_CTRL_2_VBUS_DISCHG;/* disconnect the charge pump and  activate the 5k pull down resistor */
    }

    /* Enable/Disable module */
    while(MAX3353_WriteReg(MAX3353_REG_CTRL_2, MAX3353_data) != ERR_OK){}
}

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
void _otg_max3353_set_pdowns(uint_8 bitfield)
{
    volatile uint_8 MAX3353_data;

    MAX3353_data =  OTG_CTRL_1_IRQ_PUSH_PULL;

    if(bitfield & OTG_CTRL_PDOWN_DP)
    {
        MAX3353_data |= OTG_CTRL_1_PDOWN_DP;
    }

    if(bitfield & OTG_CTRL_PDOWN_DM)
    {
        MAX3353_data |= OTG_CTRL_1_PDOWN_DM;
    }

    while(MAX3353_WriteReg(MAX3353_REG_CTRL_1, MAX3353_data) != ERR_OK){}
}

/*
** ===================================================================
**     Method      :  MAX3353_GetUsbInputSignal (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void MAX3353_GetUsbInputSignal(void)
{
    byte          StatusReg;
    LDD_TPinMask  SignalState = 0;

    MAX3353_ReadReg(MAX3353_STAT_REG,(byte*)&StatusReg);

    /* Cycle through all the USB OTG controllers and handle the events */
    if (USB_LDD_DevDataPtr != NULL) {

        if (StatusReg & 0x01) {  /* VBUS valid signal state */
            SignalState |= LDD_USB_OTG_VBUS_VALID_PIN;
        }

        if (StatusReg & 0x02) {  /* Session valid signal state */
            SignalState |= LDD_USB_OTG_SESSION_VALID_PIN;
        }

        if (StatusReg & 0x04) {  /* Session end signal state */
            SignalState |= LDD_USB_OTG_B_SESSION_END_PIN;
        }

        if (StatusReg & 0x10) {  /* ID signal state */
            SignalState |= LDD_USB_OTG_ID_PIN;
        }

        #ifdef USB_LDD_SetSignal_METHOD_ENABLED
        USB_LDD_SetSignal(USB_LDD_DevDataPtr, \
        LDD_USB_OTG_VBUS_VALID_PIN | \
        LDD_USB_OTG_SESSION_VALID_PIN | \
        LDD_USB_OTG_B_SESSION_END_PIN | \
        LDD_USB_OTG_ID_PIN,
        SignalState);
        #endif
    }
}

/*
** ===================================================================
**     Method      :  MAX3353_SetUsbOutputSignal (component USB_OTG_STACK)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         SignalMask      - 
**         SignalValue     - 
**     Returns     : Nothing
** ===================================================================
*/
void MAX3353_SetUsbOutputSignal(LDD_TPinMask SignalMask, LDD_TPinMask SignalValue)
{
    uint32_t Ctrl1_RegMask = 0;
    uint32_t Ctrl1_RegVal = 0;
    uint32_t Ctrl2_RegMask = 0;
    uint32_t Ctrl2_RegVal = 0;

    /* DP_PU signal */
    if (SignalMask & LDD_USB_DP_PU_PIN) {                  /* Request to set signal? */
        Ctrl1_RegMask |= MAX3353_DP_PU_SIGNAL;               /* Yes, remember request */
        if (SignalValue & LDD_USB_DP_PU_PIN ) {              /* Set signal to '1'? */
            Ctrl1_RegVal |= MAX3353_DP_PU_SIGNAL;              /* Yes, update reg. value */
        }
    }
    /* DM_PU signal */
    if (SignalMask & LDD_USB_DM_PU_PIN) {                  /* Request to set signal? */
        Ctrl1_RegMask |= MAX3353_DM_PU_SIGNAL;               /* Yes, remember request */
        if (SignalValue & LDD_USB_DM_PU_PIN ) {              /* Set signal to '1'? */
            Ctrl1_RegVal |= MAX3353_DM_PU_SIGNAL;              /* Yes, update reg. value */
        }
    }
    /* DP_PD signal */
    if (SignalMask & LDD_USB_DP_PD_PIN) {                  /* Request to set signal? */
        Ctrl1_RegMask |= MAX3353_DP_PD_SIGNAL;               /* Yes, remember request */
        if (SignalValue & LDD_USB_DP_PD_PIN ) {              /* Set signal to '1'? */
            Ctrl1_RegVal |= MAX3353_DP_PD_SIGNAL;              /* Yes, update reg. value */
        }
    }
    /* DM_PD signal */
    if (SignalMask & LDD_USB_DM_PD_PIN) {                  /* Request to set signal? */
        Ctrl1_RegMask |= MAX3353_DM_PD_SIGNAL;               /* Yes, remember request */
        if (SignalValue & LDD_USB_DM_PD_PIN ) {              /* Set signal to '1'? */
            Ctrl1_RegVal |= MAX3353_DM_PD_SIGNAL;              /* Yes, update reg. value */
        }
    }

    /* VBUS_DRV signal */
    if (SignalMask & LDD_USB_OTG_VBUS_ENABLE_PIN) {        /* Request to set signal? */
        #ifdef HOST_POWER_SOURCE
        if (SignalValue & LDD_USB_OTG_VBUS_ENABLE_PIN ) {    /* Set signal to '1'? */
            HOST_DVR_VBUS_PIN_SetFieldValue(VbusDrvDevDataPtr,HOST_DRV_VBUS,1);
        } else {
            HOST_DVR_VBUS_PIN_SetFieldValue(VbusDrvDevDataPtr,HOST_DRV_VBUS,0);
        }
        #endif
        #ifdef OTG_POWER_SOURCE
        Ctrl2_RegMask |= MAX3353_VBUS_DRV_SIGNAL;            /* Yes, remember request */
        if (SignalValue & LDD_USB_OTG_VBUS_ENABLE_PIN ) {    /* Set signal to '1'? */
            Ctrl2_RegVal |= MAX3353_VBUS_DRV_SIGNAL;           /* Yes, update reg. value */
        }
        #endif
    }
    /* VBUS_CHARGE signal */
    if (SignalMask & LDD_USB_OTG_VBUS_CHARGE_PIN) {        /* Request to set signal? */
        Ctrl2_RegMask |= MAX3353_VBUS_CHARGE_SIGNAL;         /* Yes, remember request */
        if (SignalValue & LDD_USB_OTG_VBUS_CHARGE_PIN ) {    /* Set signal to '1'? */
            Ctrl2_RegVal |= MAX3353_VBUS_CHARGE_SIGNAL;        /* Yes, update reg. value */
        }
    }
    /* VBUS_DISCHARGE signal */
    if (SignalMask & LDD_USB_OTG_VBUS_DISCHARGE_PIN) {     /* Request to set signal? */
        Ctrl2_RegMask |= MAX3353_VBUS_DISCHARGE_SIGNAL;      /* Yes, remember request */
        if (SignalValue & LDD_USB_OTG_VBUS_DISCHARGE_PIN ) { /* Set signal to '1'? */
            Ctrl2_RegVal |= MAX3353_VBUS_DISCHARGE_SIGNAL;     /* Yes, update reg. value */
        }
    }

    if (Ctrl1_RegMask != 0) {
        /* Write CTRL1 */
        MAX3353_Ctrl1_RegVal = (MAX3353_Ctrl1_RegVal & ~Ctrl1_RegMask) | Ctrl1_RegVal;
        MAX3353_WriteReg(MAX3353_CTRL_1_REG, (uint8_t)MAX3353_Ctrl1_RegVal);
    }
    if (Ctrl2_RegMask != 0) {
        /* Write CTRL2 */
        MAX3353_Ctrl2_RegVal = (MAX3353_Ctrl2_RegVal & ~Ctrl2_RegMask) | Ctrl2_RegVal;
        MAX3353_WriteReg(MAX3353_CTRL_2_REG, (uint8_t)MAX3353_Ctrl2_RegVal);
    }
}

LDD_TError MAX3353_ReadReg(byte RegAddres, byte *VarAddress)
{
    LDD_TError volatile res;
    LDD_I2C_TBusState BusState;

    /* Send register address */
    res = OTG_MAX3353_MasterSendBlock(I2CDevDataPtr, &RegAddres, 1, LDD_I2C_NO_SEND_STOP);
    if (res == ERR_OK) {
        while (!OTG_MAX3353_MasterGetBlockSentStatus(I2CDevDataPtr)) {
            #ifdef OTG_MAX3353_Main_METHOD_ENABLED
            OTG_MAX3353_Main(I2CDevDataPtr);
            #endif
        };
    } else {
        return res;
    }
    (void)OTG_MAX3353_GetError(I2CDevDataPtr, (LDD_TError *)&res);
    if (res != ERR_OK) {
        return res;
    }

    /* Read register value */
    res = OTG_MAX3353_MasterReceiveBlock(I2CDevDataPtr, VarAddress, 1, LDD_I2C_SEND_STOP);
    if (res == ERR_OK) {
        while (!OTG_MAX3353_MasterGetBlockReceivedStatus(I2CDevDataPtr)) {
            #ifdef OTG_MAX3353_Main_METHOD_ENABLED
            OTG_MAX3353_Main(I2CDevDataPtr);
            #endif
        };
    } else {
        return res;
    }
    do {
        (void)OTG_MAX3353_CheckBus(I2CDevDataPtr,&BusState);
    } while(BusState == LDD_I2C_BUSY);

    (void)OTG_MAX3353_GetError(I2CDevDataPtr, (LDD_TError *)&res);
    return res;
}

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
