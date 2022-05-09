/*
** ETNA PROJECT, 09/05/2022 by turpin_l
** /home/nemestos/sdl_playground
** File description:
**      header file for state manager
*/

#ifndef INCLUDE_STATEMANAGER
#define INCLUDE_STATEMANAGER
#include "state.h"

typedef struct
{
    State **stack;

} StateManager;

typedef struct
{
    float deltatime;
} StateOptions;

int sm_init(StateManager *stateManager);
int sm_free(StateManager *stateManager);
int sm_push(StateManager *stateManager, State *state);
State *sm_pop(StateManager *stateManager);
State *sm_top(StateManager *stateManager);
int sm_update(StateManager *StateManager, StateOptions StateOptions);
int sm_draw(StateManager *StateManager, StateOptions StateOptions);

#endif /* INCLUDE_STATEMANAGER */
