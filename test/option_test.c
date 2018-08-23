#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/test.h"
#include "../src/option/include/option.h"
#include "../src/option/include/show.h"

void test_active_option(option_t * option, ...)
{
        return;
}

int option_test()
{
        char * text1 = "START";
        char * text2 = "OPTION";
        option_t * selected_option = new_option(text1, test_active_option);
        option_t * unselected_option = new_option(text2, test_active_option);

        selected_option->select(selected_option);

        make_test_title("option");

        assert(strcmp(selected_option->text, text1) == 0 &&
               strcmp(unselected_option->text, text2) == 0, "text");

        assert(selected_option->show == show_selected_option &&
               unselected_option->show == show_unselected_option, "show");

        assert(selected_option->action == test_active_option &&
               unselected_option->action == test_active_option, "active");

        unselected_option->select(unselected_option);
        assert(unselected_option->show == show_selected_option, "select");

        selected_option->unselect(selected_option);
        assert(selected_option->show == show_unselected_option, "unselect");

        selected_option->destroy(selected_option);
        unselected_option->destroy(unselected_option);

        end_test_title("option");

        return 0;
}
