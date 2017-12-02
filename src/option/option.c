#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/option.h"
#include "include/option_show.h"
#include "include/option_select.h"

/*
 *  This file defines the game's options,
 *  developing his representations and
 *  defining some constructors to improve the
 *  easy understanding of the code.
 */

option_t * new_option (char * text, void (*show_function)(option_t *),
                                  int (*action_function)(option_t *))
{
        //  Abtract generate method. Never used directly.

        option * new_option = malloc(sizeof(option));

        new_option->text = (char *) malloc(strlen(text) + 1);
        strcpy(new_option->text, text);
        new_option->show = show_function;
        new_option->action = action_function;
        new_option->select = select_option;
        new_option->unselect = unselect_option;

        return new_option;
}

option_t * unselected_option(char * text, int (*action_function)())
{
        return new_option(text, show_unselected_option, action_function);
}

option_t * selected_option(char * text, int (*action_function)())
{
        return new_option(text, show_selected_option, action_function);
}
