/*
** ETNA PROJECT, 27/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      source file for graphics abstraction
*/

#include "engine.h"
#include "unistd.h"
#include "consts.h"
#include "utils.h"
#include "SDL2/SDL.h"
Graphics *graphics_alloc()
{
    Graphics *graphics = malloc(sizeof(Graphics));
    graphics->window = SDL_CreateWindow(
        WINDOW_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN

    );
    MALLER(graphics, error);
    MALLER(graphics->window, error);
    return graphics;
error:
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
    graphics_free(graphics);
    return NULL;
}
void graphics_free(Graphics *graphics)
{
    SDL_DestroyWindow(graphics->window);
    FREEGO(graphics);
    SDL_Log("Graphics free : success");
}
