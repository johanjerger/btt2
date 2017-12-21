#include <stdio.h>
#include "../utility/include/color.h"
#include "include/option.h"

/*
 *  This modules defines the game's options
 *  shows.
 */

void show_unselected_option(option_t * opt)
{
        printf("\t\t\t\t    %s\n", opt->text);
}


void show_selected_option(option_t * opt)
{
        printf(YELLOW "\t\t\t\t    %s\n" RESET, opt->text);
}
