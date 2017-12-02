#ifndef BTT2_OLL_H
#define BTT2_OLL_H

#include "../../option/include/option.h"

typedef struct _option_list
{
  option * option;
  struct _option_list * next;
  struct _option_list * previous;
} option_list_t;

option_list_t * new_option_list ();

#endif
