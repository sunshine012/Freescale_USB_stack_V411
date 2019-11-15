/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : poll.h
**     Project   : ProcessorExpert
**     Processor : MK40N512LQ100
**     Component : USB_OTG_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef _POLL_H_
#define _POLL_H_

#include "psptypes.h"
/* Maximum number of functions called every time Poll function is invoked */
#define POLL_MAX_NUM  5

/* return code */
#define POLL_OK            0 /* register successfully */
#define POLL_REGISTER_FAIL 1 /* can NOT register more function to poll*/
#define POLL_NOT_FOUND     2 /* polling function pointer array is empty */

/* Poll function pointer */
typedef void (*POLL_POINTER)(void);

/* Poll structure */
typedef struct{
    POLL_POINTER   p_func[POLL_MAX_NUM]; /* polling function pointer array */
    uint_8         registered_no;  /* number of registered function */
}POLL_STRUCT, *PTR_POOL_STRUCT;

/* Register funtion to poll */
uint_8 POLL_register(POLL_POINTER);

/* Poll function to call in while loop */
void Poll(void);

/* Init POLL_STRUCT object */
void POLL_init(void);

/* Unregister polling function */
uint_8 POLL_unregister(POLL_POINTER);

#endif /* End of #ifndef _POLL_H_ */

