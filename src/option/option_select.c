#include <stdio.h>
#include "include/option.h"
#include "include/option_show.h"
#include "../utility/include/color.h"

/*
 *  This file defines the game's options
 *  select.
 */

void select_option(option_t * opt)
{
        option->show = show_selected_option;
}

void unselect_option(option_t * opt)
{
        option->show = show_unselected_option;
}
