/*
** ETNA PROJECT, 27/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      include file for sdl error handling
*/

#ifndef INCLUDE_ETN_ERRORS
#define INCLUDE_ETN_ERRORS
#include "unistd.h"
#include "SDL2/SDL_log.h"
#include "SDL2/SDL_error.h"

int check_return_ptr(void *ptr, char *good_message);
int check_return_int(int return_value, char *good_message);
#endif /* INCLUDE_ETN_ERRORS */
