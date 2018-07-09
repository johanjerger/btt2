#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/get_home.h"
#include "../include/btt2.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"

void
paths_configuration (void)
{
		get_home();

		// Defining the root folder for the btt files
		int size_of_home = strlen(home_path);
		root_path = (char *) malloc(size_of_home * sizeof(char) + 20);
		check_error(root_path, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_ROOT_PATH);

		strcpy(root_path, home_path);
		strcat(root_path, ".btt2");
		strcat(root_path, BAR);
		create_directory(root_path);

		// Defining the scores table folder for the scores data
		int size_of_root = strlen(root_path);
		scores_path = (char *) malloc(size_of_root * sizeof(char) + 20);
		check_error(scores_path, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORES_PATH);

		strcpy(scores_path, root_path);
		strcat(scores_path, "scores");
		strcat(scores_path, BAR);
		create_directory(scores_path);

		// Defining the configuration folder for the cfg files
		config_path = (char *) malloc(size_of_root * sizeof(char) + 20);
		check_error(config_path, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_CONFIG_PATH);
		strcpy(config_path, root_path);
		strcat(config_path, "config");
		strcat(config_path, BAR);
		create_directory(config_path);
}
