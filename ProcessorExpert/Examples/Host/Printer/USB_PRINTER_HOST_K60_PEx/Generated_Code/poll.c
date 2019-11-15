/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : poll.c
**     Project   : ProcessorExpert
**     Processor : MK60N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-12-27, 10:02, # CodeGen: 23
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "poll.h"

/* poll global variale */

POLL_STRUCT g_poll;

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : POLL_init
* Returned Value   : void
* Comments         : Init POLL_STRUCT object
*
*END*----------------------------------------------------------------------*/

void POLL_init()
{
    uint_8 i;
    g_poll.registered_no = 0;
    for (i = 0; i <POLL_MAX_NUM; i++){
        g_poll.p_func[i] = NULL;
    }

}
/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : POLL_register
* Returned Value   : POLL_OK: register successfully
*                    POLL_REGISTER_FAIL: can NOT register more function to poll
* Comments         : Register funtion to poll
*
*END*----------------------------------------------------------------------*/

uint_8 POLL_register(POLL_POINTER func)
{
    if (POLL_MAX_NUM <= g_poll.registered_no){
        return POLL_REGISTER_FAIL;
    }else{
        g_poll.p_func[g_poll.registered_no] = func;
        g_poll. registered_no ++;
        return POLL_OK;
    }
}
/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : Poll
* Returned Value   : void
* Comments         : Poll function to call in while loop
*
*END*----------------------------------------------------------------------*/
void Poll()
{
    uint_8 i;

    for (i = 0; i < g_poll.registered_no; i++)
    {
        g_poll.p_func[i]();
    }

}
/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : Poll
* Returned Value   : POLL_OK: register successfully
*                    POLL_NOT_FOUND: Nothing to unregister
* Comments         : Unregister polling function
*
*END*----------------------------------------------------------------------*/
uint_8 POLL_unregister(POLL_POINTER func)
{
    uint_8 i, j =0, ret = POLL_NOT_FOUND;

    POLL_POINTER temp[POLL_MAX_NUM] = {NULL};

    /* find and unregister func */
    for(i = 0; i < POLL_MAX_NUM; i++)
    {
        if(g_poll.p_func[i] == func)
        {
            g_poll.p_func[i] = NULL;
            g_poll. registered_no--;
            ret = POLL_OK;
        }else
        {
            temp[j] = g_poll.p_func[i];
            j++;
        }
    }

    /* sort the function pointer erray */
    for(i = 0; i < POLL_MAX_NUM; i++)
    {
        g_poll.p_func[i] = temp [i];
    }
    return ret;
}
