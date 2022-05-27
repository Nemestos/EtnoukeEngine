/*
** ETNA PROJECT, 27/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      include file for sdl error handling
*/

#ifndef INCLUDE_ENGINE_ERRORS_HANDLER
#define INCLUDE_ENGINE_ERRORS_HANDLER
#include "unistd.h"
#include "SDL2/SDL_log.h"
#include "SDL2/SDL_error.h"

int check_return(void *return_value, char *good_message);
#endif /* INCLUDE_ENGINE_ERRORS_HANDLER */
