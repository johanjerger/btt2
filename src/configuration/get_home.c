#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/btt2.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"

#ifdef _WIN32

void
get_home(void)
{
		char * root = getenv("HOMEDRIVE");
		char * home_folder = getenv("HOMEPATH");
		int size_of_home = strlen(root) + strlen(home_folder);

		home_path = (char *) malloc(size_of_home * sizeof(char) + 20);
		check_error(home_path, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_HOME_PATH);

		strcpy(home_path, root);
		strcat(home_path, home_folder);
		strcat(home_path, BAR);
}

#elif __unix__

void
get_home(void)
{
		char * home_folder = getenv("HOME");
		int size_of_home = strlen(home_folder);

		home_path = (char *) malloc(size_of_home * sizeof(char) + 20);
		check_error(home_path, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_HOME_PATH);

		strcpy(home_path, home_folder);
		strcat(home_path, BAR);
}

#endif
