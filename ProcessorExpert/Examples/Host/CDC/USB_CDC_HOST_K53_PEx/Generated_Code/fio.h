/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : fio.h
**     Project   : ProcessorExpert
**     Processor : MK53N512LQ100
**     Component : USB_CDC_CLASS
**     Version   : Driver 01.00, CPU db: 3.00.000
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2012-11-19, 12:10, # CodeGen: 18
**     Abstract  :
**     Settings  :
**     (c) Copyright <company/user-name>, 2011
**     http      : www.<company>.com
**     mail      : info@<company>.com
** ###################################################################*/

#ifndef __fio_h__
#define __fio_h__

/* Include for variable length argument functions */
#include <stdarg.h>
#include "psptypes.h"

/*--------------------------------------------------------------------------*/
/*
**                            CONSTANT DEFINITIONS
*/

/* Maximum line size for scanf */
#define IO_MAXLINE  (256)

/* Definitions for filesystem table */
#define FS_MAX_DEVLEN         (8)
#define MAX_FS_INSTANCES      (4)
/* map function names to mqx function names */
/* CR1343 & CR1455 #ifndef __cplusplus */

/*--------------------------------------------------------------------------*/
/*
**                        MACRO DECLARATIONS
*/

/*--------------------------------------------------------------------------*/
/*
**                            DATATYPE DECLARATIONS
*/

/*
** FILE STRUCTURE
**
** This structure defines the information kept in order to implement
** ANSI 'C' standard I/O stream.
*/
typedef struct file_struct
{

    /* The address of the Device for this stream */
    struct io_device_struct _PTR_ DEV_PTR;

    /* Device Driver specific information */
    pointer       DEV_DATA_PTR;

    /* General control flags for this stream */
    uint_32     FLAGS;

    /* The current error for this stream */
    uint_32     ERROR;

    /* The current position in the stream */
    uint_32    LOCATION;

    /* The current size of the file */
    uint_32    SIZE;

    /* The following 2 implement undelete */
    boolean       HAVE_UNGOT_CHARACTER;
    uint_32      UNGOT_CHARACTER;

} FILE_CDC, _PTR_ FILE_CDC_PTR;

typedef struct {
   char       FS_NAME[FS_MAX_DEVLEN];
   FILE_CDC_PTR   FS_PTR;
} FS_TABLE_ENTRY, _PTR_ FS_TABLE_ENTRY_PTR;
#define _FILE_PTR_DEFINED

/*--------------------------------------------------------------------------*/
/*
**                      FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __TAD_COMPILE__
/* ANSI 'C' library function prototypes */
extern void        _io_clearerr(FILE_CDC_PTR);
extern int_32    _io_fclose(FILE_CDC_PTR);
extern int_32    _io_feof(FILE_CDC_PTR);
extern int_32    _io_ferror(FILE_CDC_PTR);
extern int_32    _io_fflush(FILE_CDC_PTR);
extern int_32    _io_fgetc(FILE_CDC_PTR);
extern int_32    _io_fgetline(FILE_CDC_PTR, char _PTR_, int_32);
extern char _PTR_  _io_fgets(char _PTR_, int_32, FILE_CDC_PTR);
extern FILE_CDC_PTR    _io_fopen(const char _PTR_, const char _PTR_);
extern int_32    _io_fprintf(FILE_CDC_PTR, const char _PTR_, ... );
extern int_32    _io_fputc(int_32, FILE_CDC_PTR);
extern int_32    _io_fputs(const char _PTR_, FILE_CDC_PTR);
extern int_32    _io_fscanf(FILE_CDC_PTR, const char _PTR_, ... );
extern int_32    _io_fseek(FILE_CDC_PTR, int_32, uint_32);
extern boolean     _io_fstatus(FILE_CDC_PTR);
extern int_32    _io_ftell(FILE_CDC_PTR);
extern int_32    _io_fungetc(int_32, FILE_CDC_PTR);
extern int_32    _io_ioctl(FILE_CDC_PTR, int_32, pointer);
extern double      _io_modf(double, double _PTR_);
extern int_32    _io_printf(const char _PTR_ , ... );
extern int_32    _io_read(FILE_CDC_PTR, pointer, int_32);
extern int_32    _io_scanf(const char _PTR_ , ... );
extern int_32    _io_sprintf(char _PTR_ , const char _PTR_ , ... );
extern int_32    _io_sscanf(char _PTR_ , char _PTR_ , ... );
extern int_32    _io_strcasecmp(const char *s1, const char *s2);
extern int_32    _io_strncasecmp(const char *s1, const char *s2, uint_32 n);
extern double      _io_strtod(char _PTR_, char _PTR_ _PTR_);
extern int_32    _io_vprintf(const char _PTR_, va_list);
extern int_32    _io_vfprintf(FILE_CDC_PTR, const char _PTR_, va_list);
extern int_32    _io_vsprintf(char _PTR_, const char _PTR_, va_list);
extern int_32    _io_write(FILE_CDC_PTR, pointer, int_32);
extern int_32    _io_atoi(const char *str);

/*
** functions mapped out as macros in 'C' but provided for assembler functions
*/
extern int_32    _io_getchar(void);
extern int_32    _io_getline(char _PTR_, int_32);
extern char _PTR_  _io_gets(char _PTR_);
extern int_32    _io_putchar(int_32);
extern int_32    _io_puts(char _PTR_);
extern boolean     _io_status(void);
extern int_32    _io_ungetc(int_32);


extern boolean     _io_strtolower( char_ptr arg);
extern char_ptr    _io_find_filename(char_ptr arg);
extern boolean     _io_validate_device(char_ptr arg);
extern void        _io_create_prefixed_filename(char_ptr new_ptr, char_ptr in_ptr,  char_ptr dev_ptr);
extern int_32      _io_rel2abs(char_ptr result, char_ptr curdir, char_ptr inputpath, int_32 len, char_ptr cur_dev);
extern int_32      _io_get_dev_for_path(char_ptr out_dev, boolean * is_dev_in_path, int_32 dev_len, char_ptr input_path, char_ptr cur_dev);

extern FILE_CDC_PTR    _io_get_first_valid_fs();
extern FILE_CDC_PTR    _io_get_fs_by_name(char_ptr fs_name);
extern int_32      _io_get_fs_name(FILE_CDC_PTR fs_ptr, char_ptr fs_name, int_32 fs_name_len);
extern boolean     _io_is_fs_valid(FILE_CDC_PTR fs_ptr);

extern uint_32     _io_unregister_file_system(FILE_CDC_PTR fd_ptr);
extern uint_32     _io_register_file_system(FILE_CDC_PTR fd_ptr,char_ptr name_ptr);

#endif

/*==========================================================================*/

#ifdef __cplusplus
}
#endif

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
