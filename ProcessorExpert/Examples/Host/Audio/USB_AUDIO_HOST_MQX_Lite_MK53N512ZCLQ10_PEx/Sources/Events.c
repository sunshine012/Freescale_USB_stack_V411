/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MK53DN512ZCLQ10
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-15, 16:04, # CodeGen: 3
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Sampling_TM_OnInterrupt - void Sampling_TM_OnInterrupt(void);
**         GPIO2_OnPortEvent       - void GPIO2_OnPortEvent(LDD_TUserData *UserDataPtr);
**         GPIO1_OnPortEvent       - void GPIO1_OnPortEvent(LDD_TUserData *UserDataPtr);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Sampling_TM_OnInterrupt (module Events)
**
**     Component   :  Sampling_TM [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Sampling_TM_OnInterrupt(void)
{
  /* Write your code here ... */
	 Play_task();
}

/*
** ===================================================================
**     Event       :  GPIO2_OnPortEvent (module Events)
**
**     Component   :  GPIO2 [GPIO_LDD]
**     Description :
**         Called if defined event on any pin of the port occured.
**         OnPortEvent event and GPIO interrupt must be enabled. See
**         SetPortEventMask() and GetPortEventMask() methods. This
**         event is enabled if <Interrupt service/event> is Enabled and
**         disabled if <Interrupt service/event> is Disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO2_OnPortEvent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
  Mute_button_task();
}

/*
** ===================================================================
**     Event       :  GPIO1_OnPortEvent (module Events)
**
**     Component   :  GPIO1 [GPIO_LDD]
**     Description :
**         Called if defined event on any pin of the port occured.
**         OnPortEvent event and GPIO interrupt must be enabled. See
**         SetPortEventMask() and GetPortEventMask() methods. This
**         event is enabled if <Interrupt service/event> is Enabled and
**         disabled if <Interrupt service/event> is Disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO1_OnPortEvent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
  Play_button_task();
}

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT0 (module Events)
**
**     Component   :  Cpu [MK53N512LQ100]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT0(void)
{
  /* Write your code here ... */
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/