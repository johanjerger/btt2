#include <stdio.h>
#include <stdlib.h>
#include "includes/test.h"
#include "includes/characters_test.h"
#include "includes/option_test.h"
#include "../src/utilities/includes/colors.h"
#include "../src/utilities/includes/utilities.h"

int main()
{

        make_header();

        characters_test();

        option_test();

        make_footer();

        return 0;
}
