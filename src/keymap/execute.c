#include <string.h>
#include "include/keymap.h"

void execute_keymap_action(menu_t * actual_menu, keymap_t * actual_keymap, char key)
{
        keymap_t * head = actual_keymap;

        while(head->key != key) {
                head = head->next_key;
                if (head == actual_keymap) return;
        }

        head->action(actual_menu);
}
