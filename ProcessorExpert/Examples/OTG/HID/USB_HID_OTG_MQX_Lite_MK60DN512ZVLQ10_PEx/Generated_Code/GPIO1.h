/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : GPIO1.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512ZVLQ10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-16, 09:27, # CodeGen: 67
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : GPIO1
**          Port                                           : PTE
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 4000000
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTE
**            Interrupt priority                           : 0
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : Page_Up
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTE26/UART4_CTS_b/ENET_1588_CLKIN/RTC_CLKOUT/USB_CLKIN
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Rising edge
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init                    - LDD_TDeviceData* GPIO1_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void GPIO1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetPortEventCondition   - LDD_TError GPIO1_SetPortEventCondition(LDD_TDeviceData *DeviceDataPtr,...
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

#ifndef __GPIO1_H
#define __GPIO1_H

/* MODULE GPIO1. */

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
#define GPIO1_PRPH_BASE_ADDRESS  0x400FF100U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define GPIO1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_GPIO1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define GPIO1_Init_METHOD_ENABLED
#define GPIO1_Deinit_METHOD_ENABLED
#define GPIO1_SetPortEventCondition_METHOD_ENABLED
#define GPIO1_SetFieldValue_METHOD_ENABLED
#define GPIO1_GetFieldValue_METHOD_ENABLED
#define GPIO1_ClearFieldBits_METHOD_ENABLED
#define GPIO1_SetFieldBits_METHOD_ENABLED
#define GPIO1_ToggleFieldBits_METHOD_ENABLED
#define GPIO1_SetFieldInputDirection_METHOD_ENABLED
#define GPIO1_SetFieldOutputDirection_METHOD_ENABLED
#define GPIO1_ConnectPin_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define GPIO1_OnPortEvent_EVENT_ENABLED

/* Definition of bit field constants */
#define Page_Up ((LDD_GPIO_TBitField)0)

/* Definition of implementation constants */
#define GPIO1_ALLOCATED_PINS_MASK 0x04000000U /* Mask of all allocated pins from the port */
#define GPIO1_MODULE_BASE_ADDRESS PTE_BASE_PTR /* Name of macro used as the base address */
#define GPIO1_PORTCONTROL_BASE_ADDRESS PORTE_BASE_PTR /* Name of macro used as the base address */
#define GPIO1_AVAILABLE_EVENTS_MASK LDD_GPIO_ON_PORT_EVENT /* Mask of all available events */
#define GPIO1_FIELD_0_PIN_0 LDD_GPIO_PIN_26 /* Constant for the pin in the field used in the method ConnectPin */
#define GPIO1_Page_Up_START_BIT 26u    /* Index of the starting bit of the bit field (0 represents LSB) */
#define GPIO1_Page_Up_MASK 0x04000000u /* Mask of the bits allocated by the bit field (within the port) */
/* Representation of unaligned data value of the port.
   Unsigned integer of proper width depending on the size of the GPIO port allocated.
   Typically the value of n-th bit represents the data for the n-th pin within the port.
   Such value is not abstracted from the physical position of the bits within the port. */
typedef uint32_t GPIO1_TPortValue;

/* Representation of right-aligned data value of the bit field.
   Typically the value of n-th bit represents the data of the n-th bit within the bit field (not within the port).
   There are used only so many lowest bits, as it is denoted by the width of the bit field.
   Such value is abstracted from the physical position of the bit field pins within the port.
   Equals to the type <compId>_TPortValue. */
typedef GPIO1_TPortValue GPIO1_TFieldValue;



LDD_TDeviceData* GPIO1_Init(LDD_TUserData *UserDataPtr);
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

void GPIO1_Deinit(LDD_TDeviceData *DeviceDataPtr);
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

LDD_TError GPIO1_SetPortEventCondition(LDD_TDeviceData *DeviceDataPtr, GPIO1_TPortValue Mask, LDD_GPIO_TEventCondition Condition);
/*
** ===================================================================
**     Method      :  GPIO1_SetPortEventCondition (component GPIO_LDD)
**
**     Description :
**         This method defines condition of the <OnPortEvent> for
**         required pins of the port.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Mask            - Unaligned mask of bits to setting the
**                           event condition. Each port pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected pin, bit value 1 means
**                           selected pin. The bit 0 corresponds with
**                           the pin which has index 0 within the port,
**                           the bit 1 corresponds with the pin which
**                           has index 1 within the port, etc.
**         Condition       - Defines conditions when event
**                           is invoked. Possible values are: 
**                           LDD_GPIO_DISABLED - Event doesn't invoke. 
**                           LDD_GPIO_LOW - Event when logic zero.
**                           LDD_GPIO_HIGH - Event when logic one.
**                           LDD_GPIO_RISING - Event on rising edge.
**                           LDD_GPIO_FALLING - Event on falling edge.
**                           LDD_GPIO_BOTH - Event on rising and falling
**                           edge. 
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask.
**                           ERR_PARAM_CONDITION - Invalid condition.
** ===================================================================
*/

void GPIO1_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Value);
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

GPIO1_TFieldValue GPIO1_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
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

void GPIO1_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask);
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

void GPIO1_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask);
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

void GPIO1_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Mask);
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

void GPIO1_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
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

void GPIO1_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO1_TFieldValue Value);
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

LDD_TError GPIO1_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask);
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

/* {MQXLite RTOS Adapter} ISR function prototype */
void GPIO1_Interrupt(LDD_RTOS_TISRParameter _isrParameter);
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

/* END GPIO1. */

#endif
/* ifndef __GPIO1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
