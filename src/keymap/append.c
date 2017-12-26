#include <stdlib.h>
#include "include/keymap.h"

void keymap_append(keymap_t * keymap, char key, void (*action)())
{
        keymap_t * new_key = new_keymap(key, action);
        keymap_t * head = keymap;

        while (head != head->next_key) {
                head = head->next_key;
        }

        head->next_key = new_key;
        new_key->next_key = new_key;
}
