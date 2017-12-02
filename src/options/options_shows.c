#include <stdio.h>
#include <stdlib.h>
#include "../utilities/includes/colors.h"
#include "includes/options.h"

/*
 *  This modules defines the game's options
 *  shows.
 */

void show_unselected_option(option * opt)
{
        printf("%s\n", opt->text);
}


void show_selected_option(option * opt)
{
        printf(YELLOW "%s\n" RESET, opt->text);
}
