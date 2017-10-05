#ifndef BTT2_OP_H
#define BTT2_OP_H

/*
 *  Struct that contains the attributes of an option
 *  it contains the option's text, the way that
 *  it show and how action perform when you click it.
 */

typedef struct _option
{
  char * text;
  void (*show_option)(struct _option *);
  int (*active_option)();
} option;

option * unselected_option(char * text, int (*active_option)());

option * selected_option(char * text, int (*active_option)());

#endif
