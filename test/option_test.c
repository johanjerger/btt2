#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/test.h"
#include "../src/option/include/option.h"
#include "../src/option/include/option_show.h"

void test_active_option()
{
        return;
}

int option_test()
{
        char * text1 = "START";
        char * text2 = "OPTION";
        option_t * selected_option_test = new_option(text1, &test_active_option);
        option_t * unselected_option_test = new_option(text2, &test_active_option);

        selected_option_test->select(selected_option_test);

        make_test_title("option");

        assert(strcmp(selected_option_test->text, text1) == 0 &&
               strcmp(unselected_option_test->text, text2) == 0, "text");

        assert(selected_option_test->show == &show_selected_option &&
               unselected_option_test->show == &show_unselected_option, "show");

        assert(selected_option_test->action == &test_active_option &&
               unselected_option_test->action == &test_active_option, "active");

        unselected_option_test->select(unselected_option_test);
        assert(unselected_option_test->show == &show_selected_option, "select");

        selected_option_test->unselect(selected_option_test);
        assert(selected_option_test->show == &show_unselected_option, "unselect");

        end_test_title("option");

        free(selected_option_test);
        free(unselected_option_test);

        return 0;
}
