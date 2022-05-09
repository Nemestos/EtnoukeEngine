/*
** ETNA PROJECT, 09/05/2022 by turpin_l
** sdl_playground
** File description:
**      Utils header for the EtnoukeEngine
*/

#ifndef INCLUDE_UTILS
#define INCLUDE_UTILS

typedef unsigned int (*fn_ptr)();
typedef unsigned int (*fn_ptr_float)(float);
typedef unsigned int (*fn_ptr_int)(int);
typedef unsigned int (*fn_ptr_char)(char);
typedef unsigned int (*fn_ptr_str)(char *);
typedef unsigned int (*fn_ptr_void)(void *);
#define fn_ptr_custom(_custom) unsigned int (*fn_ptr)(_custom)

#define GOOD_RETURN 0
#define FAILED_RETURN 1

#define MALLER(_ptr, _lbl) \
    do                     \
    {                      \
        if (_ptr == NULL)  \
        {                  \
            goto _lbl;     \
        }                  \
    } while (0)

#endif /* INCLUDE_UTILS */
