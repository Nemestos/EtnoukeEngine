/*
** ETNA PROJECT, 27/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      source file for graphics abstraction
*/

#include "etn_graphics.h"

Graphics *graphics_default_init(Graphics *graphics)
{
    if (!graphics->title)
        graphics->title = ETN_WINDOW_NAME;
    if (!graphics->width)
        graphics->width = ETN_WINDOW_WIDTH;
    if (!graphics->height)
        graphics->height = ETN_WINDOW_HEIGHT;

    graphics->window = SDL_CreateWindow(
        graphics->title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        graphics->width,
        graphics->height,
        SDL_WINDOW_SHOWN);
    MALLER(graphics->window, error, "Can't init window: %s", graphics->title);
    graphics->renderer = SDL_CreateRenderer(graphics->window, -1, SDL_RENDERER_ACCELERATED);
    MALLER(graphics->renderer, error, "Can't create renderer");
    return graphics;

error:
    graphics_free(graphics);
    return NULL;
}

Graphics *graphics_create(GraphicsInit graphicsInit)
{
    Graphics *graphics = malloc(sizeof(Graphics));
    MALLER(graphics, error, "Can't create graphics module");

    if (graphicsInit)
    {
        graphics = graphicsInit(graphics);
    }
    return graphics;
error:
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
    graphics_free(graphics);
    return NULL;
}

void graphics_free(Graphics *graphics)
{
    SDL_DestroyWindow(graphics->window);
    SDL_DestroyRenderer(graphics->renderer);
    FREEGO(&graphics);
    SDL_Log("Graphics free : success");
}
