/*
** ETNA PROJECT, 09/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      header file for state manager
*/

#ifndef INCLUDE_ETN_STATE_MANAGER
#define INCLUDE_ETN_STATE_MANAGER

#include "etn_state.h"

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

StateManager *sm_init();

int sm_scale(StateManager *stateManager);

int sm_free(StateManager *stateManager);

int sm_push(StateManager *stateManager, State *state);

State *sm_top(StateManager *stateManager);

int sm_pop(StateManager *stateManager);

int sm_update(StateManager *stateManager, StateOptions stateOptions);

int sm_draw(StateManager *stateManager, StateOptions stateOptions);

#endif /* INCLUDE_ETN_STATE_MANAGER */
