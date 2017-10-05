#include <string.h>
#include "includes/keymaps.h"

int execute_keymap_action(menu * actual_menu, keymap * actual_keymap, char key)
{
  keymap * head = actual_keymap;

  while(head->key != key) {
    head = head->next_key;
    if (head == actual_keymap) return 0 ;
  }

  return head->action(actual_menu);
}
