#ifndef BTT2_H
#define BTT2_H

#include <stdbool.h>

// Defining the bars depending on the operating system
#if defined(_WIN32) ||  defined(WIN32)
#define BAR "\\"
#elif defined(__unix__) || defined( __CYGWIN__)
#define BAR "/"
#endif

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

// global keys configurations
char action_key;
char up_key;
char down_key;
char left_key;
char right_key;
char item_key;
char enter_key;

#endif
