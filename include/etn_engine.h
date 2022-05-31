#ifndef INCLUDE_ENGINE
#define INCLUDE_ENGINE

#include "etn_graphics.h"
#include "etn_state_manager.h"
#include "stdbool.h"
#include "stdlib.h"

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

typedef Engine *(*EngineInit)(Engine *, EngineOptions *);

Engine *engine_default_init(Engine *engine, EngineOptions *engineOptions);
Engine *engine_create(EngineOptions *engineOptions, EngineInit engineInit);
void engine_free(Engine *engine);

#endif /* INCLUDE_ENGINE */
