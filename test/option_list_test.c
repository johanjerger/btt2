#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/test.h"
#include "../src/option/include/option.h"
#include "../src/option_list/include/option_list.h"

void some_function()
{
        return;
}

int option_list_test()
{
        option_t * option1, * option2, * option3;

        option1 = selected_option("START", &some_function);
        option2 = unselected_option("CONFIGURATION", &some_function);
        option3 = unselected_option("EXIT", &some_function);

        option_list_t * option_list_test = new_option_list(option1);
        option_list_test->append(option_list_test, option2);
        option_list_test->append(option_list_test, option3);

        make_test_title("option_list");

        option_list_t * next = option_list_test->next;
        option_list_t * last = option_list_test->next->next;

        assert(strcmp(option_list_test->option->text, option1->text) == 0 &&
               strcmp(next->option->text, option2->text) == 0 &&
               strcmp(last->option->text, option3->text) == 0
               , "text");

        assert(option_list_test->option->show == option1->show &&
               next->option->show == option2->show &&
               last->option->show == option3->show
               , "show");

        assert(option_list_test->option->action == option1->action &&
               next->option->action == option2->action &&
               last->option->action == option3->action
               , "active");

        end_test_title("option_list");

        free(option1);
        free(option2);
        free(option3);
        free(option_list_test);

        return 0;
}
