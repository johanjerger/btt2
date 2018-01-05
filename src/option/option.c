#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/option.h"
#include "include/show.h"
#include "include/select.h"
#include "include/destroy.h"

/*
 *  This file defines the game's options, developing his representations and
 *  defining a constructor to improve the easy understanding of the code.
 */

option_t * new_option (char * text, void (*action_function)())
{
        option_t * new_option;

        // Memory allocation
        new_option = (option_t *) malloc(sizeof(option_t));
        check_error(new_option, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_OPTION);
        new_option->text = (char *) malloc(strlen(text) * sizeof(char) + 1);

        // Struct initialization
        strcpy(new_option->text, text);
        new_option->show = show_unselected_option;
        new_option->action = action_function;
        new_option->select = select_option;
        new_option->unselect = unselect_option;
        new_option->destroy = option_destroy;

        return new_option;
}
