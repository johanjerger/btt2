#include <stdio.h>
#include <stdlib.h>
#include "include/test.h"
#include "include/character_test.h"
#include "include/option_test.h"
#include "include/option_list_test.h"
#include "include/menu_test.h"
#include "include/keymap_test.h"
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

        //character_test();

        option_test();

        //option_list_test();

        //keymap_test();

        //menu_test();

        make_footer();

        return 0;
}
