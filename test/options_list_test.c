#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/test.h"
#include "../src/options/includes/options.h"
#include "../src/options/includes/options_generator.h"
#include "../src/options_list/includes/options_list.h"

int some_function()
{
        return 10;
}

int options_list_test()
{
        int size = 3;
        option * options[size];

        options[0] = selected_option("START", &some_function);
        options[1] = unselected_option("CONFIGURATION", &some_function);
        options[2] = unselected_option("EXIT", &some_function);

        options_list * options_list_test = new_options_list(options, size);

        make_test_title("options_list");

        options_list * next_option = options_list_test->next_option;
        options_list * previous_option = options_list_test->previous_option;

        assert(strcmp(options_list_test->option->text, options[0]->text) == 0 &&
               strcmp(next_option->option->text, options[1]->text) == 0 &&
               strcmp(previous_option->option->text, options[2]->text) == 0
               , "text");

        assert(options_list_test->option->show_option == options[0]->show_option &&
               next_option->option->show_option == options[1]->show_option &&
               previous_option->option->show_option == options[2]->show_option
               , "show");

        assert(options_list_test->option->active_option() == options[0]->active_option() &&
               next_option->option->active_option() == options[1]->active_option() &&
               previous_option->option->active_option() == options[2]->active_option()
               , "active");

        end_test_title("options_list");

        free(options[0]);
        free(options[1]);
        free(options[2]);
        free(options_list_test);

        return 0;
}
