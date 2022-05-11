/*
** ETNA PROJECT, 12/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      testing the state manager
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include "state_manager.h"
#include "stdlib.h"

unsigned int def_init()
{
    printf("init state\n");
    return 0;
}

unsigned int def_destroy()
{
    printf("delete state\n");
    return 0;
}

unsigned int def_draw(void *stateOptions)
{
    StateOptions *options = (StateOptions *)stateOptions;
    if (options == NULL)
    {
        return FAILED_RETURN;
    }
    printf("draw_dt:%.1f", options->deltatime);
    for (int i = 0; i < 10; i++)
    {
        printf("%i", i);
    }
    printf("\n");

    return GOOD_RETURN;
}

unsigned int def_update(void *stateOptions)
{
    StateOptions *options = (StateOptions *)stateOptions;
    if (options == NULL)
    {
        return FAILED_RETURN;
    }
    printf("update_dt:%.1f", options->deltatime);
    for (int i = 'a'; i <= 'c'; i++)
    {
        printf("%c", i);
    }
    printf("\n");
    return GOOD_RETURN;
}

State *def_state()
{
    State *state = malloc(sizeof(State));
    state->init = def_init;
    state->destroy = def_destroy;
    state->draw = def_draw;
    state->update = def_update;
    return state;
}

TestSuite(state_manager,
          .description = "test the state manager core");

Test(state_manager, init_state_manager)
{
    StateManager *stateManager = sm_init();

    cr_assert(ne(stateManager, NULL));
    cr_assert(eq(stateManager->capacity, STACK_BASE_CAPACITY));
    cr_assert(eq(stateManager->front, STACK_BASE_FRONT));
    sm_free(stateManager);
}

Test(state_manager, free_state_manager)
{
    StateManager *stateManager = sm_init();
    int ret = sm_free(stateManager);
    cr_assert(eq(ret, GOOD_RETURN));
}

Test(state_manager, push_one_state)
{
    StateManager *stateManager = sm_init();
    State *state = def_state();
    sm_push(stateManager, state);
    cr_assert(eq(stateManager->front, 0));
    sm_free(stateManager);
}
Test(state_manager, pop_one_state)
{
    StateManager *stateManager = sm_init();
    State *state = def_state();
    sm_push(stateManager, state);
    cr_assert(eq(stateManager->front, 0));
    sm_pop(stateManager);
    cr_assert(eq(stateManager->front, -1));
    sm_free(stateManager);
}

Test(state_manager, check_stdout_init_update_draw_delete, .init = cr_redirect_stdout)
{
    StateManager *stateManager = sm_init();
    State *state = def_state();
    sm_push(stateManager, state);

    StateOptions opt = {.deltatime = 60.0f};
    sm_update(stateManager, opt);
    sm_draw(stateManager, opt);

    fflush(stdout);
    char buff[80];
    sprintf(buff, "init state\nupdate_dt:%.1fabc\ndraw_dt:%.1f0123456789\n", opt.deltatime);
    cr_assert_stdout_eq_str(buff);
    sm_free(stateManager);
}