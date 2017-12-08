#ifndef BTT2_OLT_H
#define BTT2_OLT_H

  #include "../../option/include/option.h"

  typedef struct _option_list
  {
    option_t * option;
    struct _option_list * next;
    struct _option_list * previous;
    void (*append) (struct _option_list *, option_t *);
  } option_list_t;

  option_list_t * new_option_list(option_t *);

  option_list_t * new_main_menu_options_list();

#endif
