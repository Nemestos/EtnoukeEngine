/*
** ETNA PROJECT, 27/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      include file for graphic abstraction
*/

#ifndef INCLUDE_ENGINE_GRAPHICS
#define INCLUDE_ENGINE_GRAPHICS

#include "SDL2/SDL.h"

typedef struct
{
    int width;
    int height;
    SDL_Window *window;
} Graphics;

int graphics_init();
void graphics_free(Graphics *graphics);

#endif /* INCLUDE_ENGINE_GRAPHICS */
