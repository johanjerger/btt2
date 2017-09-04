#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/utilities/includes/colors.h"
#include "../src/utilities/includes/utilities.h"

int make_test_title(char * test_name)
{
        printf(GREEN "\n BEGINING %s TEST\n\n" RESET, test_name);
        sleep(500);

        return 0;
}

int assert(bool success, char * method)
{
        // assert method to avoid the duplicate code in tests...

        (success) ?
        printf(GREEN "\t - %s method    .................................... SUCCESS \n" RESET, method) :
        fprintf(stderr, RED "\t - %s method    .................................... FAIL \n" RESET, method);
        sleep(500);

        return 0;
}

int end_test_title(char * test_name)
{
        printf(GREEN "\n %s TEST FINISH\n\n" RESET, test_name);

        return 0;
}
