/** ###################################################################
**     THIS USER MODULE IS GENERATED BY THE TOOL. MODIFY IT FOLLOW COMMENTS BELOW.
**     Filename  : usb_classes.c
**     Project   : ProcessorExpert
**     Processor : MK40N512LQ100
**     Component : USB_HOST_STACK
**     Version   : Driver 01.00, CPU db: 3.00.001
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2013-01-25, 09:53, # CodeGen: 3
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#include "hostapi.h"
#include "host_ch9.h"
#include "host_common.h"

/* get application-specific configuration */
#include "usb_classes.h"
/* End of header definition, DO NOT MODIFY LINES ABOVE */
/* Write your own includes here ...*/

/* Begin of class interface map definition, DO NOT MODIFY LINES BELOW*/
CLASS_MAP class_interface_map[] =
{
    {
        usb_class_pex_audio_control_init,
        sizeof(USB_CLASS_PEX_AUDIO_CONTROL_INTF_STRUCT),
        0x01,
        0x01,
        0x00,
        0xFF,
        0xFF,
        0x00,
    },
    {
        usb_class_pex_audio_stream_init,
        sizeof(USB_CLASS_PEX_AUDIO_STREAM_INTF_STRUCT),
        0x01,
        0x02,
        0x00,
        0xFF,
        0xFF,
        0x00,
    },
    {
        NULL,
        0,
        0, 0, 0,
        0, 0, 0
    }
};
/* End of class interface map definition, DO NOT MODIFY LINES ABOVE*/

/* DO NOT MODIFY LINES BELOW */
void usb_class_pex_audio_control_init(PIPE_BUNDLE_STRUCT_PTR pbs_ptr, CLASS_CALL_STRUCT_PTR ccs_ptr)
{
/* End <function_begin_1>, DO NOT MODIFY LINES ABOVE */
/* Write your own code of usb_class_pex_audio_control_init function below */
	usb_class_audio_control_init(pbs_ptr,ccs_ptr);
/* End of <function_end_1>, DO NOT MODIFY LINES BELOW */
} /* End of usb_class_pex_audio_control_init function */
/* DO NOT MODIFY LINES ABOVE */

/* DO NOT MODIFY LINES BELOW */
void usb_class_pex_audio_stream_init(PIPE_BUNDLE_STRUCT_PTR pbs_ptr, CLASS_CALL_STRUCT_PTR ccs_ptr)
{
/* End <function_begin_2>, DO NOT MODIFY LINES ABOVE */
/* Write your own code of usb_class_pex_audio_stream_init function below */
	usb_class_audio_stream_init(pbs_ptr,ccs_ptr);
/* End of <function_end_2>, DO NOT MODIFY LINES BELOW */
} /* End of usb_class_pex_audio_stream_init function */
/* DO NOT MODIFY LINES ABOVE */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
