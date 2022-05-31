#ifndef INCLUDE_ETN_ENGINE
#define INCLUDE_ETN_ENGINE

#include "etn_graphics.h"
#include "etn_errors.h"
#include "etn_state_manager.h"
#include "etn_utils.h"
#include "stdbool.h"
#include "stdlib.h"

typedef struct
{
    char *title;
    int width;
    int height;
    GraphicsInit customGraphicsInit;
} EngineOptions;

typedef struct
{
    bool running;
    Graphics *graphics;
    StateManager *stateManager;
} Engine;

typedef Engine *(*EngineInit)(Engine *, EngineOptions *);

Engine *engine_default_init(Engine *engine, EngineOptions *engineOptions);
Engine *engine_create(EngineOptions *engineOptions, EngineInit engineInit);
void engine_free(Engine *engine);

#endif /* INCLUDE_ETN_ENGINE */
