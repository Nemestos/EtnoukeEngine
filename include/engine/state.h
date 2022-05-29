/*
** ETNA PROJECT, 12/05/2022 by turpin_l
** EtnoukeEngine
** File description:
**      header file for state atom
*/

#ifndef INCLUDE_ENGINE_STATE
#define INCLUDE_ENGINE_STATE

#include "utils.h"
#include "state.h"
typedef struct State
{
    fn_ptr init;
    fn_ptr_void_ptr draw;
    fn_ptr_void_ptr update;

    fn_ptr destroy;
} State;

#endif /* INCLUDE_ENGINE_STATE */
