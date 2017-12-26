#ifndef BTT2_MN_H
#define BTT2_MN_H

/*
 *  Struct that contains the attributes of the menus
 *  it contains the menus representation, the options
 *  and the uses functions.
 */

 #include "../../option_list/include/option_list.h"

typedef struct _menu
{
  char * title;
  option_list_t * options;
  option_list_t * selected_option;
  int(*show)(struct _menu *);
  void(*next_option)(struct _menu *);
  void(*previous_option)(struct _menu *);
  void(*destroy)(struct _menu *);
} menu_t;

menu_t * new_menu(char *, option_list_t *, int(*show_menu)(menu_t *));

menu_t * new_main_menu();

menu_t * new_difficult_menu();

menu_t * new_scores_menu();

#endif
