/*
** ETNA PROJECT, 29/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      implement engine
*/

#include "etn.h"

Engine *engine_default_init(Engine *engine, EngineOptions *engineOptions)
{
    engine->graphics = graphics_create(NULL);
    if (engineOptions != NULL)
    {
        engine->graphics->title = engineOptions->title;
        engine->graphics->width = engineOptions->width;
        engine->graphics->height = engineOptions->height;
    }
    graphics_default_init(engine->graphics);
    engine->stateManager = sm_init();
    engine->running = true;
    MALLER(engine->graphics, error);
    MALLER(engine->stateManager, error);
    return engine;

error:
    engine_free(engine);
    return NULL;
}

Engine *engine_create(EngineOptions *engineOptions, EngineInit engineInit)
{
    int code = check_return_int(SDL_Init(SDL_INIT_VIDEO), "Video init : success");
    if (code)
    {
        return NULL;
    }

    Engine *engine = malloc(sizeof(Engine));
    MALLER(engine, error);

    if (engineInit)
    {
        engine = engineInit(engine, engineOptions);
    }

    return engine;
error:
    engine_free(engine);
    return NULL;
}

void engine_free(Engine *engine)
{
    sm_free(engine->stateManager);
    graphics_free(engine->graphics);
    FREEGO(&engine);
    SDL_Log("Engine free : success");
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    SDL_Quit();
}