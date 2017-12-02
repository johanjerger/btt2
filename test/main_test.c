#include <stdio.h>
#include <stdlib.h>
#include "include/test.h"
#include "include/character_test.h"
#include "include/options_test.h"
#include "include/options_list_test.h"
#include "include/menus_test.h"
#include "include/keymaps_test.h"
#include "../src/utility/include/color.h"
#include "../src/utility/include/utility.h"

/*
 * This is the test main function,
 * here I manage the order of the
 * test functions.
 */

int main()
{
        make_header();

        character_test();

        options_test();

        options_list_test();

        keymaps_test();

        menus_test();

        make_footer();

        return 0;
}
