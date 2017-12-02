#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/test.h"
#include "../src/option/include/option.h"
#include "../src/option_list/include/option_list.h"

int some_function()
{
        return 10;
}

int option_list_test()
{
        option * option1, * option2, * option3;

        options1 = selected_option("START", &some_function);
        options2 = unselected_option("CONFIGURATION", &some_function);
        options3 = unselected_option("EXIT", &some_function);

        option_list_t * option_list_test = new_option_list(options1);
        option_list_test->append(option2);
        option_list_test->append(option3)

        make_test_title("option_list");

        option_list_t * next = option_list_test->next;
        option_list_t * previous = option_list_test->previous;

        assert(strcmp(option_list_test->option->text, options[0]->text) == 0 &&
               strcmp(next->option->text, options[1]->text) == 0 &&
               strcmp(previous->option->text, options[2]->text) == 0
               , "text");

        assert(option_list_test->option->show_option == options[0]->show_option &&
               next->option->show_option == options[1]->show_option &&
               previous->option->show_option == options[2]->show_option
               , "show");

        assert(option_list_test->option->active_option() == options[0]->active_option() &&
               next->option->active_option() == options[1]->active_option() &&
               previous->option->active_option() == options[2]->active_option()
               , "active");

        end_test_title("option_list");

        free(options[0]);
        free(options[1]);
        free(options[2]);
        free(option_list_test);

        return 0;
}
