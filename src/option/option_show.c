#include <stdio.h>
#include "../utility/include/color.h"
#include "include/option.h"

/*
 *  This modules defines the game's options
 *  shows.
 */

void show_unselected_option(option_t * opt)
{
        printf("%s\n", opt->text);
}


void show_selected_option(option_t * opt)
{
        printf(YELLOW "%s\n" RESET, opt->text);
}
