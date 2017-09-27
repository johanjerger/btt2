#include <stdio.h>
#include <stdlib.h>
#include "includes/test.h"
#include "includes/characters_test.h"
#include "includes/options_test.h"
#include "includes/options_list_test.h"
#include "includes/menus_test.h"
#include "../src/utilities/includes/colors.h"
#include "../src/utilities/includes/utilities.h"

/*
 * This is the test main function,
 * here I manage the order of the
 * test functions.
 */

int main()
{
        make_header();

        characters_test();

        options_test();

        options_list_test();

        menus_test();

        make_footer();

        return 0;
}
