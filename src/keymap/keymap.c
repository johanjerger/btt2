#include <stdio.h>
#include <stdlib.h>
#include "include/keymap.h"
#include "include/keymap_exec.h"
#include "../menu/include/menu.h"
#include "../menu/include/menu_option_change.h"
#include "../menu/include/menu_execute.h"

keymap_t * new_keymap(char * keys, void (**actions)(), int size)
{
        int i;
        keymap_t * new_keymap[size];

        for(i = 0; i < size; i++) {
                new_keymap[i] = (keymap_t *) malloc(sizeof(keymap_t));
                new_keymap[i]->key = keys[i];
                new_keymap[i]->action = actions[i];
                new_keymap[i]->exec = execute_keymap_action;
        }

        for(i = 0; i < size-1; i++) {
                new_keymap[i]->next_key = new_keymap[i+1];
        }

        new_keymap[i]->next_key = new_keymap[0];

        return new_keymap[0];
}


keymap_t * new_main_menu_keymap()
{
        int size = 3;

        char keys[3] = {'w', 's', (char) 13};
        void (*actions[3])() = {
                &select_previous_option,
                &select_next_option,
                &execute_menu
        };

        return new_keymap(keys, actions, size);
}
