#ifndef BTT2_OLL_H
#define BTT2_OLL_H

#include "../../options/includes/options.h"

typedef struct _options_list
{
  option * option;
  struct _options_list * next_option;
  struct _options_list * previous_option;
} options_list;

options_list * new_options_list(option **, int);

options_list * new_main_menu_options_list();

#endif
