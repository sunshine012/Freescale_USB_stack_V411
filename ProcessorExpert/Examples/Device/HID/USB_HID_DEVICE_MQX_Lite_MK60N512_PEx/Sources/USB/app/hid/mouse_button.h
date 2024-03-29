/******************************************************************************
 *
 * Freescale Semiconductor Inc.
 * (c) Copyright 2004-2009 Freescale Semiconductor, Inc.
 * ALL RIGHTS RESERVED.
 *
 **************************************************************************//*!
 *
 * @file mouse_button.h
 *
 * @author
 *
 * @version
 *
 * @date May-28-2009
 *
 * @brief The file contains Macro's and functions needed by the Mouse
 *        Application
 *
 *****************************************************************************/
#ifndef _MOUSE_BUTTON_H
#define _MOUSE_BUTTON_H

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "types.h"

/******************************************************************************
 * Constants - None
 *****************************************************************************/
/******************************************************************************
 * Macro's
 *****************************************************************************/
#define CONTROLLER_ID      (0)    /* ID to identify USB CONTROLLER */
#define SHIFT_VAL          (0x08) /* send +8 for down and right movement */   
#define MOUSE_BUFF_SIZE   (4)    /* report buffer size */
#define REQ_DATA_SIZE     (1)
#define KBI_STAT_MASK     (0x0F)
#define LEFT_CLICK        (0x01) /* Left click */
#define RIGHT_CLICK       (0x02) /* Right click */
#define MOVE_LEFT_RIGHT   (0x04) /* Left-Right movement*/
#define MOVE_UP_DOWN      (0x08) /* Up-Down movement*/

/*****************************************************************************
 * Global Functions
 *****************************************************************************/
extern void TestApp_Init(void);
extern void TestApp_Task(void);
#endif
/* EOF */
