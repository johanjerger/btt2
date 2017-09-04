#include <stdio.h>
#include <stdlib.h>
#include "includes/characters_test.h"
#include "../src/utilities/includes/colors.h"
#include "../src/utilities/includes/utilities.h"

int main()
{
        printf(GREEN "\n\t ... STARTING TESTS ... \n" RESET);

        characters_test();

        return 0;
}
