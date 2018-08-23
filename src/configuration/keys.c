#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/btt2.h"

void keys_configuration()
{
		char * keys_conf_path;

		keys_conf_path = (char *) malloc(strlen(root_path) * sizeof(char) + 20);

		strcpy(keys_conf_path, config_path);
		strcat(keys_conf_path, "keys");

		// TODO This initializations must be written in a configurable file later

		keys[UP] = 'w';
		keys[DOWN] = 's';
		keys[LEFT] = 'a';
		keys[RIGHT] = 'd';
		keys[ENTER] = ENTER_KEY;

		free(keys_conf_path);
}
