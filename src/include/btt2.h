#ifndef BTT2_H
#define BTT2_H

#include <stdbool.h>

// Defining the slashes depending on the operating system
#define SLASH "/"
#define ENTER_KEY 10

// root path for games files
char * home_path;
char * root_path;
char * scores_path;
char * config_path;

// global status variables
bool main_loop;
bool game_loop;
bool scores_loop;
bool difficult_loop;
bool config_loop;

// global keys configurations
char keys[5];

enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER
};

// Terminal size
int term_lines;
int term_columns;

#endif
