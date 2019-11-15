/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : GPIO1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-05, 15:01, # CodeGen: 2
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : GPIO1
**          Port                                           : PTA
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 10
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTA
**            Interrupt priority                           : medium priority
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : key
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
**         Init                    - LDD_TDeviceData* GPIO1_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void GPIO1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void GPIO1_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         GetFieldValue           - GPIO1_TFieldValue GPIO1_GetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         ClearFieldBits          - void GPIO1_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldBits            - void GPIO1_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         ToggleFieldBits         - void GPIO1_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldInputDirection  - void GPIO1_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void GPIO1_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError GPIO1_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE GPIO1. */

#include "Events.h"
#include "GPIO1.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

typedef struct {
  GPIO1_TPortValue EventFlags;         /* Holds event flags */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} GPIO1_TDeviceData, *GPIO1_TDeviceDataPtr; /* Device data structure type */
/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static GPIO1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static GPIO1_TDeviceData * INT_PORTA__DEFAULT_RTOS_ISRPARAM;
/*
** ===================================================================
**     Method      :  GPIO1_Init (component GPIO_LDD)
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
LDD_TDeviceData* GPIO1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  GPIO1_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Save RTOS Device structure */
  DeviceDataPrv->EventFlags = 0x00U;   /* Clears stored events */
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PORTA__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
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
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_GPIO1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  GPIO1_Deinit (component GPIO_LDD)
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
void GPIO1_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* PORTA_PCR4: IRQC=0 */
  PORTA_PCR4 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                                   
  /* GPIOA_PDDR: PDD&=~0x10 */
  GPIOA_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x10));                                                   
  /* Interrupt vector(s) deallocation */
  /* {Default RTOS Adapter} Restore interrupt vector: IVT is static, no code is generated */
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_GPIO1_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldValue (component GPIO_LDD)
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
void GPIO1_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(~((GPIO1_TPortValue)GPIO1_key_MASK)))
        )
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_key_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_key_MASK)
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
**     Method      :  GPIO1_GetFieldValue (component GPIO_LDD)
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
GPIO1_TFieldValue GPIO1_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      return
        (GPIO1_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(GPIO1_MODULE_BASE_ADDRESS)
            & (GPIO1_TPortValue)GPIO1_key_MASK
          )
          >> GPIO1_key_START_BIT
        );
    }
    default:
      break;                           /* Invalid BitField is not treated, result is undefined */
  } /* switch (Field) */
  return (GPIO1_TFieldValue)0U;
}

/*
** ===================================================================
**     Method      :  GPIO1_ClearFieldBits (component GPIO_LDD)
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
void GPIO1_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_ClearPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_key_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_key_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldBits (component GPIO_LDD)
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
void GPIO1_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_key_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_key_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_ToggleFieldBits (component GPIO_LDD)
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
void GPIO1_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_TogglePortDataOutputMask(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)GPIO1_key_MASK)
        & ((GPIO1_TPortValue)(Mask << GPIO1_key_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldInputDirection (component GPIO_LDD)
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
void GPIO1_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortInputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_key_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_SetFieldOutputDirection (component GPIO_LDD)
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
void GPIO1_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS,
        ((GPIO1_TPortValue)(
          GPIO_PDD_GetPortDataOutput(GPIO1_MODULE_BASE_ADDRESS)
          & ((GPIO1_TPortValue)(
            ~((GPIO1_TPortValue)GPIO1_key_MASK)
          ))
        ))
        | (
          ((GPIO1_TPortValue)(Value << GPIO1_key_START_BIT))
          & ((GPIO1_TPortValue)GPIO1_key_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(GPIO1_MODULE_BASE_ADDRESS,
        GPIO1_key_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO1_ConnectPin (component GPIO_LDD)
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
LDD_TError GPIO1_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Pin mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((PinMask & ((LDD_TPinMask)~((LDD_TPinMask)GPIO1_ALLOCATED_PINS_MASK))) != 0U) {
    return ERR_PARAM_MASK;
  }
  if ((PinMask & LDD_GPIO_PIN_4) != 0U) {
    clrSetReg32Bits(PORTA_PCR4, 0x01000600U, 0x0100U); /* MUX=0x01U */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  GPIO1_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(GPIO1_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  GPIO1_TDeviceDataPtr DeviceDataPrv = INT_PORTA__DEFAULT_RTOS_ISRPARAM;
  GPIO1_TPortValue State;

  State = (GPIO1_TPortValue)(PORT_PDD_GetInterruptFlags(GPIO1_PORTCONTROL_BASE_ADDRESS)
          & ((GPIO1_TPortValue)GPIO1_ALLOCATED_PINS_MASK)); /* Retrieve flags */
  DeviceDataPrv->EventFlags |= State;
  PORT_PDD_ClearInterruptFlags(GPIO1_PORTCONTROL_BASE_ADDRESS, State); /* Clears flags */
  GPIO1_OnPortEvent(DeviceDataPrv->UserData); /* Call OnPortEvent event */
}

/* END GPIO1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
