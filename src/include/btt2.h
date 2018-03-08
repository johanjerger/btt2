#ifndef BTT2_H
#define BTT2_H

#include <stdbool.h>

// root path for games files

char * home_path;
char * root_path;
char * scores_path;
char * config_path;

#ifdef _WIN32
  #define BAR "\\"
#elif __unix__
  #define BAR "/"
#endif

// global status variables

bool game;
bool scores;
bool difficult;

// global keys configurations

char action_key;
char up_key;
char down_key;
char left_key;
char right_key;
char item_key;
char enter_key;

#endif
