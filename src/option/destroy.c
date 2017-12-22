#include <stdlib.h>
#include "include/option.h"

void option_destroy(option_t * option)
{
        free(option->text);
}
