#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/btt2.h"

void keys_configuration()
{
        char * keys_conf_path;

        keys_conf_path = (char *) malloc(strlen(root_path) * sizeof(char) + 20);

        strcpy(keys_conf_path, root_path);
        strcat(keys_conf_path, "keys_conf");

        printf("%s\n", keys_conf_path);
}
