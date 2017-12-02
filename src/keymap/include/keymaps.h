#ifndef BTT2_KM_H
#define BTT2_KM_H

#include "../../menus/includes/menus.h"

  typedef struct _keymap
  {
    char key;
    int(*action)();
    struct _keymap * next_key;
    int(*exec)(menu *, struct _keymap *, char);
  } keymap;

  keymap * new_keymap(char *, int(**)(), int);

  keymap * new_main_menu_keymap();

#endif
