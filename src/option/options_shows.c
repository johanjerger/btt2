#include <stdio.h>
#include <stdlib.h>
#include "utilities/includes/colors.h"
#include "includes/options.h"

/*
 *  This modules defines the game's options
 *  shows.
 */

int show_option(option * opt)
{
        printf("%s\n", opt->text);

        return 42; // Ale's purpose
}


int show_option_selected(option * opt)
{
        printf(YELLOW "%s\n" RESET, opt->text);

        return 42; // Ale's purpose
}
