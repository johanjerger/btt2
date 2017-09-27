#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/options.h"
#include "includes/options_shows.h"

option * generate_option (char * text, void (*show_option)(option *), int (*active_option)(option *))
{
        //  Abtract generate method. Never used directly.

        option * new_option = malloc(sizeof(option));

        new_option->text = (char *) malloc(strlen(text) + 1);
        strcpy(new_option->text, text);
        new_option->show_option = show_option;
        new_option->active_option = active_option;

        return new_option;
}

option * unselected_option(char * text, int (*active_option)())
{
        return generate_option(text, show_option_unselected, active_option);
}

option * selected_option(char * text, int (*active_option)())
{
        return generate_option(text, show_option_selected, active_option);
}
