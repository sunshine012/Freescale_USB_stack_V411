/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : GPIO2.h
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-25, 09:53, # CodeGen: 3
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : GPIO2
**          Port                                           : PTC
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 2000
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTC
**            Interrupt priority                           : 0
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : MUTE
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTC13/UART4_CTS_b/LCD_P33
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Rising edge
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init                    - LDD_TDeviceData* GPIO2_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void GPIO2_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void GPIO2_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         GetFieldValue           - GPIO2_TFieldValue GPIO2_GetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         ClearFieldBits          - void GPIO2_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldBits            - void GPIO2_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         ToggleFieldBits         - void GPIO2_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldInputDirection  - void GPIO2_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void GPIO2_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError GPIO2_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __GPIO2_H
#define __GPIO2_H

/* MODULE GPIO2. */

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
#define GPIO2_PRPH_BASE_ADDRESS  0x400FF080U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define GPIO2_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_GPIO2_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define GPIO2_Init_METHOD_ENABLED
#define GPIO2_Deinit_METHOD_ENABLED
#define GPIO2_SetFieldValue_METHOD_ENABLED
#define GPIO2_GetFieldValue_METHOD_ENABLED
#define GPIO2_ClearFieldBits_METHOD_ENABLED
#define GPIO2_SetFieldBits_METHOD_ENABLED
#define GPIO2_ToggleFieldBits_METHOD_ENABLED
#define GPIO2_SetFieldInputDirection_METHOD_ENABLED
#define GPIO2_SetFieldOutputDirection_METHOD_ENABLED
#define GPIO2_ConnectPin_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define GPIO2_OnPortEvent_EVENT_ENABLED

/* Definition of bit field constants */
#define MUTE ((LDD_GPIO_TBitField)0)

/* Definition of implementation constants */
#define GPIO2_ALLOCATED_PINS_MASK 0x2000U /* Mask of all allocated pins from the port */
#define GPIO2_MODULE_BASE_ADDRESS PTC_BASE_PTR /* Name of macro used as the base address */
#define GPIO2_PORTCONTROL_BASE_ADDRESS PORTC_BASE_PTR /* Name of macro used as the base address */
#define GPIO2_AVAILABLE_EVENTS_MASK LDD_GPIO_ON_PORT_EVENT /* Mask of all available events */
#define GPIO2_FIELD_0_PIN_0 LDD_GPIO_PIN_13 /* Constant for the pin in the field used in the method ConnectPin */
#define GPIO2_MUTE_START_BIT 13u       /* Index of the starting bit of the bit field (0 represents LSB) */
#define GPIO2_MUTE_MASK 0x2000u        /* Mask of the bits allocated by the bit field (within the port) */
/* Representation of unaligned data value of the port.
   Unsigned integer of proper width depending on the size of the GPIO port allocated.
   Typically the value of n-th bit represents the data for the n-th pin within the port.
   Such value is not abstracted from the physical position of the bits within the port. */
typedef uint32_t GPIO2_TPortValue;

/* Representation of right-aligned data value of the bit field.
   Typically the value of n-th bit represents the data of the n-th bit within the bit field (not within the port).
   There are used only so many lowest bits, as it is denoted by the width of the bit field.
   Such value is abstracted from the physical position of the bit field pins within the port.
   Equals to the type <compId>_TPortValue. */
typedef GPIO2_TPortValue GPIO2_TFieldValue;



LDD_TDeviceData* GPIO2_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  GPIO2_Init (component GPIO_LDD)
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

void GPIO2_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  GPIO2_Deinit (component GPIO_LDD)
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

void GPIO2_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Value);
/*
** ===================================================================
**     Method      :  GPIO2_SetFieldValue (component GPIO_LDD)
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

GPIO2_TFieldValue GPIO2_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  GPIO2_GetFieldValue (component GPIO_LDD)
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

void GPIO2_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  GPIO2_ClearFieldBits (component GPIO_LDD)
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

void GPIO2_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  GPIO2_SetFieldBits (component GPIO_LDD)
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

void GPIO2_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  GPIO2_ToggleFieldBits (component GPIO_LDD)
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

void GPIO2_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  GPIO2_SetFieldInputDirection (component GPIO_LDD)
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

void GPIO2_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Value);
/*
** ===================================================================
**     Method      :  GPIO2_SetFieldOutputDirection (component GPIO_LDD)
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

LDD_TError GPIO2_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask);
/*
** ===================================================================
**     Method      :  GPIO2_ConnectPin (component GPIO_LDD)
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
void GPIO2_Interrupt(void);
/*
** ===================================================================
**     Method      :  GPIO2_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END GPIO2. */

#endif
/* ifndef __GPIO2_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
