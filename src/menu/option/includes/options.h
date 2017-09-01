#ifndef BTT2_MN_H
#define BTT2_MN_H

/*
 *  Struct that contains the attributes of an option
 *  it contains the option's text, the way that
 *  it show and how action perform when you click it.
 */

typedef struct
{
  char * text;
  int(*show_option)(option);
  int(*active_option)();
} option;

#endif
