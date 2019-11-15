/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : OTG_MAX3353_INT_PIN.h
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCMD10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-11-19, 13:40, # CodeGen: 34
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : OTG_MAX3353_INT_PIN
**          Port                                           : PTB
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 100
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTB
**            Interrupt priority                           : medium priority
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : I2C_INT
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTB8/UART3_RTS_b/LCD_P8
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Falling edge
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init                    - LDD_TDeviceData* OTG_MAX3353_INT_PIN_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void OTG_MAX3353_INT_PIN_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void OTG_MAX3353_INT_PIN_SetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         GetFieldValue           - OTG_MAX3353_INT_PIN_TFieldValue OTG_MAX...
**         ClearFieldBits          - void OTG_MAX3353_INT_PIN_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldBits            - void OTG_MAX3353_INT_PIN_SetFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         ToggleFieldBits         - void OTG_MAX3353_INT_PIN_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldInputDirection  - void OTG_MAX3353_INT_PIN_SetFieldInputDirection(LDD_TDeviceData...
**         SetFieldOutputDirection - void OTG_MAX3353_INT_PIN_SetFieldOutputDirection(LDD_TDeviceData...
**         ConnectPin              - LDD_TError OTG_MAX3353_INT_PIN_ConnectPin(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __OTG_MAX3353_INT_PIN_H
#define __OTG_MAX3353_INT_PIN_H

/* MODULE OTG_MAX3353_INT_PIN. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"
#include "PORT_PDD.h"
#include "PE_LDD.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define OTG_MAX3353_INT_PIN_PRPH_BASE_ADDRESS  0x400FF040U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define OTG_MAX3353_INT_PIN_Init_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_Deinit_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_SetFieldValue_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_GetFieldValue_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_ClearFieldBits_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_SetFieldBits_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_ToggleFieldBits_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_SetFieldInputDirection_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_SetFieldOutputDirection_METHOD_ENABLED
#define OTG_MAX3353_INT_PIN_ConnectPin_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define OTG_MAX3353_INT_PIN_OnPortEvent_EVENT_ENABLED

/* Definition of bit field constants */
#define I2C_INT ((LDD_GPIO_TBitField)0)

/* Definition of implementation constants */
#define OTG_MAX3353_INT_PIN_ALLOCATED_PINS_MASK 0x0100U /* Mask of all allocated pins from the port */
#define OTG_MAX3353_INT_PIN_MODULE_BASE_ADDRESS PTB_BASE_PTR /* Name of macro used as the base address */
#define OTG_MAX3353_INT_PIN_PORTCONTROL_BASE_ADDRESS PORTB_BASE_PTR /* Name of macro used as the base address */
#define OTG_MAX3353_INT_PIN_AVAILABLE_EVENTS_MASK LDD_GPIO_ON_PORT_EVENT /* Mask of all available events */
#define OTG_MAX3353_INT_PIN_FIELD_0_PIN_0 LDD_GPIO_PIN_8 /* Constant for the pin in the field used in the method ConnectPin */
#define OTG_MAX3353_INT_PIN_I2C_INT_START_BIT 8u /* Index of the starting bit of the bit field (0 represents LSB) */
#define OTG_MAX3353_INT_PIN_I2C_INT_MASK 0x0100u /* Mask of the bits allocated by the bit field (within the port) */
/* Representation of unaligned data value of the port.
   Unsigned integer of proper width depending on the size of the GPIO port allocated.
   Typically the value of n-th bit represents the data for the n-th pin within the port.
   Such value is not abstracted from the physical position of the bits within the port. */
typedef uint32_t OTG_MAX3353_INT_PIN_TPortValue;

/* Representation of right-aligned data value of the bit field.
   Typically the value of n-th bit represents the data of the n-th bit within the bit field (not within the port).
   There are used only so many lowest bits, as it is denoted by the width of the bit field.
   Such value is abstracted from the physical position of the bit field pins within the port.
   Equals to the type <compId>_TPortValue. */
typedef OTG_MAX3353_INT_PIN_TPortValue OTG_MAX3353_INT_PIN_TFieldValue;



LDD_TDeviceData* OTG_MAX3353_INT_PIN_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_Init (component GPIO_LDD)
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

void OTG_MAX3353_INT_PIN_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_Deinit (component GPIO_LDD)
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

void OTG_MAX3353_INT_PIN_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OTG_MAX3353_INT_PIN_TFieldValue Value);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_SetFieldValue (component GPIO_LDD)
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

OTG_MAX3353_INT_PIN_TFieldValue OTG_MAX3353_INT_PIN_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_GetFieldValue (component GPIO_LDD)
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

void OTG_MAX3353_INT_PIN_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OTG_MAX3353_INT_PIN_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_ClearFieldBits (component GPIO_LDD)
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

void OTG_MAX3353_INT_PIN_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OTG_MAX3353_INT_PIN_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_SetFieldBits (component GPIO_LDD)
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

void OTG_MAX3353_INT_PIN_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OTG_MAX3353_INT_PIN_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_ToggleFieldBits (component GPIO_LDD)
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

void OTG_MAX3353_INT_PIN_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_SetFieldInputDirection (component GPIO_LDD)
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

void OTG_MAX3353_INT_PIN_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OTG_MAX3353_INT_PIN_TFieldValue Value);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_SetFieldOutputDirection (component GPIO_LDD)
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

LDD_TError OTG_MAX3353_INT_PIN_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_ConnectPin (component GPIO_LDD)
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

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(OTG_MAX3353_INT_PIN_Interrupt);
/*
** ===================================================================
**     Method      :  OTG_MAX3353_INT_PIN_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END OTG_MAX3353_INT_PIN. */

#endif
/* ifndef __OTG_MAX3353_INT_PIN_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
