/*
** ETNA PROJECT, 27/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      include file for graphic abstraction
*/

#ifndef INCLUDE_ETN_GRAPHICS
#define INCLUDE_ETN_GRAPHICS

#include "unistd.h"
#include "etn_consts.h"
#include "etn_utils.h"
#include "SDL2/SDL.h"

typedef struct
{
    char *title;
    int width;
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
} Graphics;

typedef Graphics *(*GraphicsInit)(Graphics *);

Graphics *graphics_default_init(Graphics *graphics);
Graphics *graphics_create(GraphicsInit graphicsInit);
void graphics_free(Graphics *graphics);

#endif /* INCLUDE_ETN_GRAPHICS */
