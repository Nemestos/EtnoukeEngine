#ifndef INCLUDE_ENGINE
#define INCLUDE_ENGINE
#include "errors_handler.h"
#include "graphics.h"
#include "state_manager.h"
#include "state.h"
#include "stdbool.h"

typedef struct
{
    char *title;
    int width;
    int height;
} EngineOptions;

typedef struct
{
    bool running;
    Graphics *graphics;
    StateManager *stateManager;
} Engine;

Engine *engine_init(EngineOptions *opt);
int engine_free(Engine *engine);

#endif /* INCLUDE_ENGINE */
