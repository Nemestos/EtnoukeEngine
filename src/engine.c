/*
** ETNA PROJECT, 29/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      implement engine
*/

#include "engine.h"

Engine *engine_init(EngineOptions *opt)
{
    int code = check_return_int(SDL_Init(SDL_INIT_VIDEO), "Video init : success");
    if (code)
    {
        return 1;
    }

    Engine *engine = malloc(sizeof(Engine));
    engine->graphics = graphics_init();
    engine->stateManager = sm_init();
    MALLER(engine, error);
    MALLER(engine->graphics, error);
    MALLER(engine->stateManager, error);

    if (opt)
    {
        engine->graphics->width = opt->width;
        engine->graphics->height = opt->height;
    }

    return engine;
error:
    engine_free(engine);
    return NULL;
}

int engine_free(Engine *engine)
{
}