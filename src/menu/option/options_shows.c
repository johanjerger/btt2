#include <stdio.h>
#include <stdlib.h>
#include "includes/options.h"

/*
 *  This modules defines the game's options
 *  shows.
 */

int show_option(option * opt)
{
        printf("%s\n", opt->text);
}


int show_option_selected(option * opt)
{
        printf("%s\n", opt->text);
}
