#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/option.h"
#include "include/option_show.h"
#include "include/option_select.h"

/*
 *  This file defines the game's options,
 *  developing his representations and
 *  defining some constructors to improve the
 *  easy understanding of the code.
 */

option_t * new_option (char * text, void (*action_function)())
{
        //  Abtract generate method. Never used directly.

        option_t * new_option;

        new_option = (option_t *) malloc(sizeof(option_t));
        check_error(new_option, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_OPTION);

        new_option->text = (char *) malloc(strlen(text) + 1);
        strcpy(new_option->text, text);
        new_option->show = show_unselected_option;
        new_option->action = action_function;
        new_option->select = select_option;
        new_option->unselect = unselect_option;

        return new_option;
}
