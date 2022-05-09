/*
** ETNA PROJECT, 09/05/2022 by turpin_l
** sdl_playground
** File description:
**      Header file for state unit
*/

#ifndef INCLUDE_STATE
#define INCLUDE_STATE

#include "utils.h"
typedef struct State
{
    fn_ptr init;
    fn_ptr_float update;
    fn_ptr_float draw;
    fn_ptr_float destroy;
} State;

#endif /* INCLUDE_STATE */
