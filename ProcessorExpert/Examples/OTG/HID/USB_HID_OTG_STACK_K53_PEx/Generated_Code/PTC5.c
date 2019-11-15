/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PTC5.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 13:09, # CodeGen: 25
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : PTC5
**          Port                                           : PTC
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 20
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTC
**            Interrupt priority                           : medium priority
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : key
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTC5/SPI0_SCK/LPT0_ALT2/CMP0_OUT/LCD_P25
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Rising edge
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init                    - LDD_TDeviceData* PTC5_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void PTC5_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void PTC5_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         GetFieldValue           - PTC5_TFieldValue PTC5_GetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         ClearFieldBits          - void PTC5_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldBits            - void PTC5_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         ToggleFieldBits         - void PTC5_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldInputDirection  - void PTC5_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void PTC5_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError PTC5_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE PTC5. */

#include "Events.h"
#include "PTC5.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

typedef struct {
  PTC5_TPortValue EventFlags;          /* Holds event flags */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} PTC5_TDeviceData, *PTC5_TDeviceDataPtr; /* Device data structure type */
/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static PTC5_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static PTC5_TDeviceData * INT_PORTC__DEFAULT_RTOS_ISRPARAM;
/*
** ===================================================================
**     Method      :  PTC5_Init (component GPIO_LDD)
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
LDD_TDeviceData* PTC5_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  PTC5_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Save RTOS Device structure */
  DeviceDataPrv->EventFlags = 0x00U;   /* Clears stored events */
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PORTC__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* GPIOC_PDDR: PDD&=~0x20 */
  GPIOC_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x20));                                                   
  /* Initialization of Port Control registers */
  /* PORTC_PCR5: ISF=0,LK=0,MUX=1 */
  PORTC_PCR5 = (uint32_t)((PORTC_PCR5 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_LK_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                                  
  /* PORTC_PCR5: ISF=1,IRQC=9 */
  PORTC_PCR5 = (uint32_t)((PORTC_PCR5 & (uint32_t)~(uint32_t)(
                PORT_PCR_IRQC(0x06)
               )) | (uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_IRQC(0x09)
               ));                                                  
  /* NVICIP89: PRI89=0x80 */
  NVICIP89 = NVIC_IP_PRI89(0x80);                                                   
  /* NVICISER2: SETENA|=0x02000000 */
  NVICISER2 |= NVIC_ISER_SETENA(0x02000000);                                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_PTC5_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  PTC5_Deinit (component GPIO_LDD)
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
void PTC5_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* PORTC_PCR5: IRQC=0 */
  PORTC_PCR5 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                                   
  /* GPIOC_PDDR: PDD&=~0x20 */
  GPIOC_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x20));                                                   
  /* Interrupt vector(s) deallocation */
  /* {Default RTOS Adapter} Restore interrupt vector: IVT is static, no code is generated */
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_PTC5_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  PTC5_SetFieldValue (component GPIO_LDD)
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
void PTC5_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTC5_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(PTC5_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(PTC5_MODULE_BASE_ADDRESS)
          & ((PTC5_TPortValue)(~((PTC5_TPortValue)PTC5_key_MASK)))
        )
        | (
          ((PTC5_TPortValue)(Value << PTC5_key_START_BIT))
          & ((PTC5_TPortValue)PTC5_key_MASK)
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
**     Method      :  PTC5_GetFieldValue (component GPIO_LDD)
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
PTC5_TFieldValue PTC5_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      return
        (PTC5_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(PTC5_MODULE_BASE_ADDRESS)
            & (PTC5_TPortValue)PTC5_key_MASK
          )
          >> PTC5_key_START_BIT
        );
    }
    default:
      break;                           /* Invalid BitField is not treated, result is undefined */
  } /* switch (Field) */
  return (PTC5_TFieldValue)0U;
}

/*
** ===================================================================
**     Method      :  PTC5_ClearFieldBits (component GPIO_LDD)
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
void PTC5_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTC5_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_ClearPortDataOutputMask(PTC5_MODULE_BASE_ADDRESS,
        ((PTC5_TPortValue)PTC5_key_MASK)
        & ((PTC5_TPortValue)(Mask << PTC5_key_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTC5_SetFieldBits (component GPIO_LDD)
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
void PTC5_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTC5_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortDataOutputMask(PTC5_MODULE_BASE_ADDRESS,
        ((PTC5_TPortValue)PTC5_key_MASK)
        & ((PTC5_TPortValue)(Mask << PTC5_key_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTC5_ToggleFieldBits (component GPIO_LDD)
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
void PTC5_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTC5_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_TogglePortDataOutputMask(PTC5_MODULE_BASE_ADDRESS,
        ((PTC5_TPortValue)PTC5_key_MASK)
        & ((PTC5_TPortValue)(Mask << PTC5_key_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTC5_SetFieldInputDirection (component GPIO_LDD)
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
void PTC5_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortInputDirectionMask(PTC5_MODULE_BASE_ADDRESS,
        PTC5_key_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTC5_SetFieldOutputDirection (component GPIO_LDD)
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
void PTC5_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PTC5_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case key: {                        /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(PTC5_MODULE_BASE_ADDRESS,
        ((PTC5_TPortValue)(
          GPIO_PDD_GetPortDataOutput(PTC5_MODULE_BASE_ADDRESS)
          & ((PTC5_TPortValue)(
            ~((PTC5_TPortValue)PTC5_key_MASK)
          ))
        ))
        | (
          ((PTC5_TPortValue)(Value << PTC5_key_START_BIT))
          & ((PTC5_TPortValue)PTC5_key_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(PTC5_MODULE_BASE_ADDRESS,
        PTC5_key_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PTC5_ConnectPin (component GPIO_LDD)
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
LDD_TError PTC5_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Pin mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((PinMask & ((LDD_TPinMask)~((LDD_TPinMask)PTC5_ALLOCATED_PINS_MASK))) != 0U) {
    return ERR_PARAM_MASK;
  }
  if ((PinMask & LDD_GPIO_PIN_5) != 0U) {
    clrSetReg32Bits(PORTC_PCR5, 0x01000600U, 0x0100U); /* MUX=0x01U */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PTC5_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(PTC5_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  PTC5_TDeviceDataPtr DeviceDataPrv = INT_PORTC__DEFAULT_RTOS_ISRPARAM;
  PTC5_TPortValue State;

  State = (PTC5_TPortValue)(PORT_PDD_GetInterruptFlags(PTC5_PORTCONTROL_BASE_ADDRESS)
          & ((PTC5_TPortValue)PTC5_ALLOCATED_PINS_MASK)); /* Retrieve flags */
  DeviceDataPrv->EventFlags |= State;
  PORT_PDD_ClearInterruptFlags(PTC5_PORTCONTROL_BASE_ADDRESS, State); /* Clears flags */
  PTC5_OnPortEvent(DeviceDataPrv->UserData); /* Call OnPortEvent event */
}

/* END PTC5. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
