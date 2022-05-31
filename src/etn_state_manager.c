/*
** ETNA PROJECT, 12/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      implement the state manager features
*/

#include "etn_state_manager.h"

int sm_scale(StateManager *stateManager)
{
    stateManager->capacity *= STACK_SCALE_FACTOR;
    stateManager->stack = realloc(stateManager->stack, stateManager->capacity * sizeof(State *));
    return stateManager->capacity;
}

StateManager *sm_init()
{
    StateManager *stateManager = malloc(sizeof(StateManager));
    stateManager->capacity = STACK_BASE_CAPACITY;
    stateManager->stack = malloc(stateManager->capacity * sizeof(State *));
    MALLER(stateManager->stack, error, "Can't create stack of state manager");
    stateManager->front = STACK_BASE_FRONT;
    return stateManager;
error:
    sm_free(stateManager);
    return NULL;
}

int sm_free(StateManager *stateManager)
{
    do
    {
        sm_pop(stateManager);
    } while (stateManager->front > STACK_BASE_FRONT);
    FREEGO(&stateManager->stack);
    FREEGO(&stateManager);
    SDL_Log("State manager free : success");
    return GOOD_RETURN;
}

int sm_push(StateManager *stateManager, State *state)
{
    if (stateManager->front + 1 == stateManager->capacity)
    {
        sm_scale(stateManager);
    }
    stateManager->front++;
    stateManager->stack[stateManager->front] = state;
    if (state->init != NULL)
    {
        state->init();
    }
    return stateManager->front;
}
int sm_pop(StateManager *stateManager)
{
    if (stateManager->front == -1)
    {
        return -1;
    }
    State *top = sm_top(stateManager);
    if (top->destroy != NULL)
    {
        top->destroy();
    }
    stateManager->stack[stateManager->front] = NULL;
    stateManager->front--;
    return stateManager->front;
}

State *sm_top(StateManager *stateManager)
{
    return stateManager->stack[stateManager->front];
}

int sm_update(StateManager *stateManager, StateOptions stateOptions)
{
    State *state = sm_top(stateManager);
    if (state->update != NULL)
        return state->update(&stateOptions);
    return -1;
}

int sm_draw(StateManager *stateManager, StateOptions stateOptions)
{
    State *state = sm_top(stateManager);
    if (state->draw != NULL)
        return state->draw(&stateOptions);
    return -1;
}
