#include <stdlib.h>
#include "../include/btt2.h"

void
free_environment_variables (void)
{
    free(home_path);
    free(root_path);
    free(scores_path);
    free(config_path);
}
