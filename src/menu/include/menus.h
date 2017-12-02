#ifndef BTT2_MN_H
#define BTT2_MN_H

/*
 *  Struct that contains the attributes of the menus
 *  it contains the menues representation, the options
 *  and the uses functions.
 */

 #include "../../options_list/includes/options_list.h"

typedef struct _menu
{
  char * title;
  options_list * options;
  options_list * selected_option;
  int(*show_menu)(struct _menu *);
  int(*select_next_option)(struct _menu *);
  int(*select_previous_option)(struct _menu *);
} menu;

menu * new_menu(char *, options_list *, int(*show_menu)(menu *));

menu * new_main_menu();

#endif
