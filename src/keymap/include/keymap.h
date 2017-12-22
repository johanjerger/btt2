#ifndef BTT2_KM_H
#define BTT2_KM_H

#include "../../menu/include/menu.h"

  typedef struct _keymap
  {
    char key;
    void (*action) ();
    struct _keymap * next_key;
    void (*exec) (menu_t *, struct _keymap *, char);
  } keymap_t;

  keymap_t * new_keymap(char *, void (**) (), int);

  keymap_t * new_main_menu_keymap ();

  keymap_t * new_scores_keymap();

#endif
