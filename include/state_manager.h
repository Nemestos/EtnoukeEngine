/*
** ETNA PROJECT, 09/05/2022 by turpin_l
** /home/nemestos/sdl_playground
** File description:
**      header file for state manager
*/

#ifndef INCLUDE_STATEMANAGER
#define INCLUDE_STATEMANAGER

#include "state.h"

#define STACK_BASE_CAPACITY 3
#define STACK_SCALE_FACTOR 2
#define STACK_BASE_FRONT -1

typedef struct
{
    State **stack;
    int front;
    int capacity;

} StateManager;

typedef struct
{
    float deltatime;
} StateOptions;

int sm_init(StateManager *stateManager);

int sm_scale(StateManager *stateManager);

int sm_free(StateManager *stateManager);

int sm_push(StateManager *stateManager, State *state);

State *sm_top(StateManager *stateManager);

State *sm_pop(StateManager *stateManager);

int sm_update(StateManager *stateManager, StateOptions stateOptions);

int sm_draw(StateManager *stateManager, StateOptions stateOptions);

#endif /* INCLUDE_STATEMANAGER */
