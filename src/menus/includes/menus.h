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
  int(*show_menu)(struct _menu *);
} menu;

#endif
