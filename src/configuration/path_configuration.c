#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

void path_configuration()
{
        char * root = getenv("HOMEDRIVE");
        char * home_folder = getenv("HOMEPATH");
}

#elif __unix__

void path_configuration()
{
        char * home_folder = getenv("HOME");
}

#endif
