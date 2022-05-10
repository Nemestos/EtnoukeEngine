#include "state_manager.h"
#include "stdlib.h"

int sm_scale(StateManager *stateManager)
{
    stateManager->capacity *= STACK_SCALE_FACTOR;
    stateManager->stack = realloc(stateManager->stack, stateManager->capacity * sizeof(State *));
    return stateManager->capacity;
}

int sm_init(StateManager *stateManager)
{
    stateManager->capacity = STACK_BASE_CAPACITY;
    stateManager->stack = malloc(stateManager->capacity * sizeof(State *));
    MALLER(stateManager->stack, error);
    stateManager->front = STACK_BASE_FRONT;
    return GOOD_RETURN;

error:
    free(stateManager->stack);
    return FAILED_RETURN;
}

int sm_free(StateManager *stateManager)
{
    do
    {
        sm_pop(stateManager);
    } while (stateManager->front > STACK_BASE_FRONT);
    free(stateManager->stack);
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
        return NULL;
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
}

int sm_draw(StateManager *stateManager, StateOptions stateOptions)
{
    State *state = sm_top(stateManager);
    if (state->draw != NULL)
        return state->draw(&stateOptions);
}

