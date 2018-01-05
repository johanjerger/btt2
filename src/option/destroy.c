#include <stdlib.h>
#include "include/option.h"

/*
 *  Function to define how the memory is freed after you use the option_t type.
 */

void option_destroy(option_t * option)
{
        free(option->text);
}
