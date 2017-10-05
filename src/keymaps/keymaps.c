#include <stdio.h>
#include <stdlib.h>
#include "includes/keymaps.h"
#include "includes/keymaps_exec.h"
#include "../menus/includes/menus.h"
#include "../menus/includes/menus_options_change.h"
#include "../menus/includes/menus_execute.h"

keymap * new_keymap(char * keys, int (**actions)(), int size)
{
        int i;
        keymap * new_keymap[size];

        for(i = 0; i < size; i++) {
                new_keymap[i] = (keymap *) malloc(sizeof(keymap));
                new_keymap[i]->key = keys[i];
                new_keymap[i]->action = actions[i];
                new_keymap[i]->exec = &execute_keymap_action;
        }

        for(i = 0; i < size-1; i++) {
                new_keymap[i]->next_key = new_keymap[i+1];
        }

        new_keymap[i]->next_key = new_keymap[0];

        return new_keymap[0];
}

keymap * new_main_menu_keymap()
{
        int size = 3;

        char keys[3] = {'w', 's', (char) 10};
        int (*actions[3])() = {
                &select_previous_option,
                &select_next_option,
                &execute_menu
        };

        return new_keymap(keys, actions, size);
}
