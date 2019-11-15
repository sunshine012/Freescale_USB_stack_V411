/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PTA4.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-21, 15:57, # CodeGen: 77
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : PTA4
**          Port                                           : PTA
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 10
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTA
**            Interrupt priority                           : medium priority
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : PLAY
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : TSI0_CH5/PTA4/I2C1_SDA/TPM0_CH1/NMI_b
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Rising edge
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init                    - LDD_TDeviceData* PTA4_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void PTA4_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void PTA4_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         GetFieldValue           - PTA4_TFieldValue PTA4_GetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         ClearFieldBits          - void PTA4_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldBits            - void PTA4_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         ToggleFieldBits         - void PTA4_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldInputDirection  - void PTA4_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void PTA4_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError PTA4_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE PTA4. */

#include "Events.h"
#include "PTA4.h"
/* MQX Lite include files */
#include "mqxlite.h"
#include "mqxlite_prv.h"
#include "IO_Map.h"

typedef struct {
  LDD_RTOS_TISRVectorSettings SavedISRSettings_PortInterrupt; /* {MQXLite RTOS Adapter} Saved settings of allocated interrupt vector */
  PTA4_TPortValue EventFlags;          /* Holds event flags */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} PTA4_TDeviceData, *PTA4_TDeviceDataPtr; /* Device data structure type */
/* {MQXLite RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static PTA4_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  PTA4_Init (component GPIO_LDD)
**
**     Description :
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/
LDD_TDeviceData* PTA4_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  PTA4_TDeviceData *DeviceDataPrv;

  /* {MQXLite RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Save RTOS Device structure */
  DeviceDataPrv->EventFlags = 0x00U;   /* Clears stored events */
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {MQXLite RTOS Adapter} Save old and set new interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not saved, because it is not modified */
  DeviceDataPrv->SavedISRSettings_PortInterrupt.isrData = _int_get_isr_data(LDD_ivIndex_INT_PORTA);
  DeviceDataPrv->SavedISRSettings_PortInterrupt.isrFunction = _int_install_isr(LDD_ivIndex_INT_PORTA, PTA4_Interrupt, DeviceDataPrv);
  /* GPIOA_PDDR: PDD&=~0x10 */
  GPIOA_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x10));                                                   
  /* Initialization of Port Control registers */
  /* PORTA_PCR4: ISF=0,MUX=1 */
  PORTA_PCR4 = (uint32_t)((PORTA_PCR4 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                                  
  /* PORTA_PCR4: ISF=1,IRQC=9 */
  PORTA_PCR4 = (uint32_t)((PORTA_PCR4 & (uint32_t)~(uint32_t)(
                PORT_PCR_IRQC(0x06)
               )) | (uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_IRQC(0x09)
               ));                                                  
  /* NVIC_IPR7: PRI_30=0x80 */
  NVIC_IPR7 = (uint32_t)((NVIC_IPR7 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_30(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_30(0x80)
              ));                                                  
  /* NVIC_ISER: SETENA|=0x40000000 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x40000000);                                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_PTA4_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  PTA4_Deinit (component GPIO_LDD)
**
**     Description :
**         This method disables the device and frees the device data
**         structure memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**     Returns     : Nothing
** ===================================================================
*/
void PTA4_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* PORTA_PCR4: IRQC=0 */
  PORTA_PCR4 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                                   
  /* GPIOA_PDDR: PDD&=~0x10 */
  GPIOA_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x10));                                                   
  /* Interrupt vector(s) deallocation */
  /* {MQXLite RTOS Adapter} Restore interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not restored, because it was not modified */
  (void)_int_install_isr(LDD_ivIndex_INT_PORTA, ((PTA4_TDeviceDataPtr)DeviceDataPtr)->SavedISRSettings_PortInterrupt.isrFunction, ((PTA4_TDeviceDataPtr)DeviceDataPtr)->SavedISRSettings_PortInterrupt.isrData);
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_PTA4_ID);
  /* Deallocation of the device structure */
  /* {MQXLite RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  PTA4_SetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method sets the output data value of the specified bit
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Value           - Aligned data value to writting to the
**                           specified bit field. The bit 0 corresponds
**                           with the pin which has index 0 within the
**                           given bit field, the bit 1 corresponds with
**                           the pin which has index 1 within the given
**                           bit field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void PTA4_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTA4_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case PLAY: {                       /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(PTA4_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(PTA4_MODULE_BASE_ADDRESS)
          & ((PTA4_TPortValue)(~((PTA4_TPortValue)PTA4_PLAY_MASK)))
        )
        | (
          ((PTA4_TPortValue)(Value << PTA4_PLAY_START_BIT))
          & ((PTA4_TPortValue)PTA4_PLAY_MASK)
        )
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTA4_GetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method returns the current input data of the specified
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to reading. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     :
**         ---             - Aligned current port input value masked
**                           for allocated pins of the field. The bit 0
**                           corresponds with the pin which has index 0
**                           within the given bit field, the bit 1
**                           corresponds with the pin which has index 1
**                           within the given bit field, etc.
** ===================================================================
*/
PTA4_TFieldValue PTA4_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case PLAY: {                       /* bit field #0 */
      return
        (PTA4_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(PTA4_MODULE_BASE_ADDRESS)
            & (PTA4_TPortValue)PTA4_PLAY_MASK
          )
          >> PTA4_PLAY_START_BIT
        );
    }
    default:
      break;                           /* Invalid BitField is not treated, result is undefined */
  } /* switch (Field) */
  return (PTA4_TFieldValue)0U;
}

/*
** ===================================================================
**     Method      :  PTA4_ClearFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the inactive level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           inactive level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void PTA4_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTA4_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case PLAY: {                       /* bit field #0 */
      GPIO_PDD_ClearPortDataOutputMask(PTA4_MODULE_BASE_ADDRESS,
        ((PTA4_TPortValue)PTA4_PLAY_MASK)
        & ((PTA4_TPortValue)(Mask << PTA4_PLAY_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTA4_SetFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the active level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           active level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void PTA4_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTA4_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case PLAY: {                       /* bit field #0 */
      GPIO_PDD_SetPortDataOutputMask(PTA4_MODULE_BASE_ADDRESS,
        ((PTA4_TPortValue)PTA4_PLAY_MASK)
        & ((PTA4_TPortValue)(Mask << PTA4_PLAY_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTA4_ToggleFieldBits (component GPIO_LDD)
**
**     Description :
**         This method inverts the specified bits of the specified bit
**         field to other level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to inverting the
**                           current level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void PTA4_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTA4_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case PLAY: {                       /* bit field #0 */
      GPIO_PDD_TogglePortDataOutputMask(PTA4_MODULE_BASE_ADDRESS,
        ((PTA4_TPortValue)PTA4_PLAY_MASK)
        & ((PTA4_TPortValue)(Mask << PTA4_PLAY_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTA4_SetFieldInputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the input
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     : Nothing
** ===================================================================
*/
void PTA4_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case PLAY: {                       /* bit field #0 */
      GPIO_PDD_SetPortInputDirectionMask(PTA4_MODULE_BASE_ADDRESS,
        PTA4_PLAY_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTA4_SetFieldOutputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the output
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to set to the output
**                           direction. Bit fields are defined during
**                           design time and for each bit field there is
**                           a generated constant.
**         Value           - Aligned data value to appear on the
**                           bit field pins after they have been
**                           switched to the output direction.
**     Returns     : Nothing
** ===================================================================
*/
void PTA4_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTA4_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case PLAY: {                       /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(PTA4_MODULE_BASE_ADDRESS,
        ((PTA4_TPortValue)(
          GPIO_PDD_GetPortDataOutput(PTA4_MODULE_BASE_ADDRESS)
          & ((PTA4_TPortValue)(
            ~((PTA4_TPortValue)PTA4_PLAY_MASK)
          ))
        ))
        | (
          ((PTA4_TPortValue)(Value << PTA4_PLAY_START_BIT))
          & ((PTA4_TPortValue)PTA4_PLAY_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(PTA4_MODULE_BASE_ADDRESS,
        PTA4_PLAY_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTA4_ConnectPin (component GPIO_LDD)
**
**     Description :
**         This method reconnects the requested pin associated with the
**         selected peripheral in this component. This method is only
**         available for CPU derivatives and peripherals that support
**         the runtime pin sharing with other internal on-chip
**         peripherals.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         PinMask         - Mask for the requested pins. The
**                           peripheral pins are reconnected according
**                           to this mask.
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask
** ===================================================================
*/
LDD_TError PTA4_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Pin mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((PinMask & ((LDD_TPinMask)~((LDD_TPinMask)PTA4_ALLOCATED_PINS_MASK))) != 0U) {
    return ERR_PARAM_MASK;
  }
  if ((PinMask & LDD_GPIO_PIN_4) != 0U) {
    clrSetReg32Bits(PORTA_PCR4, 0x01000600U, 0x0100U); /* MUX=0x01U */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PTA4_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PTA4_Interrupt(LDD_RTOS_TISRParameter _isrParameter)
{
  /* {MQXLite RTOS Adapter} ISR parameter is passed as parameter from RTOS interrupt dispatcher */
  PTA4_TDeviceDataPtr DeviceDataPrv = (PTA4_TDeviceDataPtr)_isrParameter;
  PTA4_TPortValue State;

  State = (PTA4_TPortValue)(PORT_PDD_GetInterruptFlags(PTA4_PORTCONTROL_BASE_ADDRESS)
          & ((PTA4_TPortValue)PTA4_ALLOCATED_PINS_MASK)); /* Retrieve flags */
  DeviceDataPrv->EventFlags |= State;
  PORT_PDD_ClearInterruptFlags(PTA4_PORTCONTROL_BASE_ADDRESS, State); /* Clears flags */
  PTA4_OnPortEvent(DeviceDataPrv->UserData); /* Call OnPortEvent event */
}

/* END PTA4. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/