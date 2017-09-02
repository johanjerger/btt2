#ifndef BTT2_MN_H
#define BTT2_MN_H

/*
 *  Struct that contains the attributes of the menues
 *  it contains the menues representation, the options
 *  and the uses functions.
 */

typedef struct option_node
{
  option actual_option;
  struct option_node * next_option;
} list_of_options;

typedef struct struct _menu
{
  char * title;
  list_of_options options;
  int(*show_menu)(struct * _menu);
} menu;

#endif
