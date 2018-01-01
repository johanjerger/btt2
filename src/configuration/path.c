#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/btt2.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"

#ifdef _WIN32

void path_configuration()
{
        char * root = getenv("HOMEDRIVE");
        char * home_folder = getenv("HOMEPATH");

        int size_of_home = strlen(root) + strlen(home_folder);

        /*
         * I alloc a little bit more than necessary because of the sub-
         * folders length.
         */

        root_path = (char *) malloc(size_of_home * sizeof(char) + 40);

        strcpy(root_path, root);
        strcat(root_path, home_folder);
        strcat(root_path, BAR);
        strcat(root_path, ".btt2");
        strcat(root_path, BAR);

        create_directory(root_path);

        strcat(root_path, "scores");
        strcat(root_path, BAR);

        create_directory(root_path);
}

#elif __unix__

void path_configuration()
{
        char * home_folder = getenv("HOME");

        int size_of_home = strlen(home_folder);

        /*
         * I alloc a little bit more than necessary because of the sub-
         * folders length.
         */

        root_path = (char *) malloc(size_of_home * sizeof(char) + 20);

        strcpy(root_path, home_folder);
        strcat(root_path, BAR);
        strcat(root_path, ".btt2");
        strcat(root_path, BAR);

        create_directory(root_path);

        strcat(root_path, "scores");
        strcat(root_path, BAR);

        create_directory(root_path);
}

#endif
