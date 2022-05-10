/*
** ETNA PROJECT, 09/05/2022 by turpin_l
** sdl_playground
** File description:
**      Header file for state unit
*/

#ifndef INCLUDE_STATE
#define INCLUDE_STATE

#include "utils.h"
#include "state.h"
typedef struct State
{
    fn_ptr init;
    fn_ptr_void_ptr draw;
    fn_ptr_void_ptr update;

    fn_ptr destroy;
} State;

#endif /* INCLUDE_STATE */
