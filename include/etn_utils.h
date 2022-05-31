/*
** ETNA PROJECT, 09/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      Utils header for the EtnoukeEngine
*/

#ifndef INCLUDE_ETN_UTILS
#define INCLUDE_ETN_UTILS

typedef unsigned int (*fn_ptr)();
typedef unsigned int (*fn_ptr_float)(float);
typedef unsigned int (*fn_ptr_int)(int);
typedef unsigned int (*fn_ptr_char)(char);
typedef unsigned int (*fn_ptr_str)(char *);
typedef unsigned int (*fn_ptr_void_ptr)(void *);
#define fn_ptr_custom(_custom) unsigned int (*fn_ptr_void_ptr)(_custom);

#define GOOD_RETURN 0
#define FAILED_RETURN 1

#define MALLER(_ptr, _lbl, _msg, ...)                                  \
    do                                                                 \
    {                                                                  \
        if (_msg != NULL)                                              \
        {                                                              \
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, _msg, ##__VA_ARGS__); \
        }                                                              \
                                                                       \
        if (_ptr == NULL)                                              \
        {                                                              \
            goto _lbl;                                                 \
        }                                                              \
    } while (0)
#define FREEGO(ptr)    \
    do                 \
    {                  \
        free(*(ptr));  \
        *(ptr) = NULL; \
    } while (0)

#endif /* INCLUDE_ETN_UTILS */
