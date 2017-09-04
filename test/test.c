#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../src/utilities/includes/colors.h"
#include "../src/utilities/includes/utilities.h"

int make_test_title(char * test_name)
{
        // Method that make the Test title header

        printf(GREEN "\n BEGINING %s TEST\n\n" RESET, test_name);
        sleep(500);

        return 0;
}

int assert(bool success, char * method)
{
        // assert method to avoid the duplicate code in tests...

        // the spaces variable is only for output purpose
        char spaces[] = "          ";
        int size_of_spaces = strlen(spaces) - strlen(method);
        spaces[size_of_spaces] = '\0';

        // printing the test result.
        (success) ?
        printf(GREEN "\t - %s method %s ..............................     SUCCESS \n" RESET, method, spaces) :
        fprintf(stderr, RED "\t - %s method %s ..............................     FAIL \n" RESET, method, spaces);
        sleep(500);

        return 0;
}

int end_test_title(char * test_name)
{
        // Method that announces the finish of the current Test

        printf(GREEN "\n %s TEST FINISH\n\n" RESET, test_name);

        return 0;
}
