/** ###################################################################
**     Filename    : mqx_tasks.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-10-01, 14:32, # CodeGen: 18
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         App_Task - void App_Task(uint32_t task_init_data);
**
** ###################################################################*/
/* MODULE mqx_tasks */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "hidmouse.h"
#include "khci.h"
#include "usb_host_hid.h"
#include <stdio.h>
#include <string.h>

/*
** ===================================================================
**     Event       :  App_Task (module mqx_tasks)
**
**     Component   :  Task1 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void App_Task(uint32_t task_init_data)
{
  int counter = 0;
  hid_mouse_init();
  while(1) {
    counter++;

    /* Write your code here ... */

  }
}

/*
** ===================================================================
**     Event       :  Khci_Task (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/
void Khci_Task(uint32_t task_init_data)
{
  int counter = 0;
  _usb_khci_task(task_init_data);
  while(1) {
    counter++;

    /* Write your code here ... */

  }
}

/* END mqx_tasks */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
