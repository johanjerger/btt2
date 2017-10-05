#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/test.h"
#include "../src/options/includes/options.h"
#include "../src/options/includes/options_shows.h"

int test_active_option()
{
        return 10;
}

int options_test()
{
        char * text1 = "START";
        char * text2 = "OPTION";
        option * selected_option_test = selected_option(text1, &test_active_option);
        option * unselected_option_test = unselected_option(text2, &test_active_option);

        make_test_title("options");

        assert(strcmp(selected_option_test->text, text1) == 0 &&
               strcmp(unselected_option_test->text, text2) == 0, "text");

        assert(selected_option_test->show_option == &show_option_selected &&
               unselected_option_test->show_option == &show_option_unselected, "show");

        assert(selected_option_test->active_option() == test_active_option() &&
               unselected_option_test->active_option() == test_active_option(), "active");

        end_test_title("options");

        free(selected_option_test);
        free(unselected_option_test);

        return 0;
}
