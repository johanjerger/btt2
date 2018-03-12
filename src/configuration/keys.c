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

		// This initializations must be written in a configurable file later

		action_key = 'k';
		up_key = 'w';
		down_key = 's';
		left_key = 'a';
		right_key = 'd';
		item_key = 'q';
		enter_key = ENTER;
}
