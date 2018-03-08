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

		// This initializations must be written in a configurable file later

		action_key = 'k';
		up_key = 'w';
		down_key = 's';
		left_key = 'a';
		right_key = 'd';
		item_key = 'q';
#ifdef _WIN32
		enter_key = 13;
#elif __unix__
		enter_key = 10;
#endif

		printf("%s\n", keys_conf_path);
}
