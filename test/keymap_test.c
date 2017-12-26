#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/test.h"
#include "../src/menu/include/menu.h"
#include "../src/keymap/include/keymap.h"

void aux_action_1(menu_t * main_menu) {
        return;
}

void aux_action_2(menu_t * main_menu) {
        return;
}

void aux_action_3(menu_t * main_menu) {
        return;
}

int keymap_test()
{

        char keys[3] = {'w', 's', '\n'};
        void (*actions[3])() = {&aux_action_1, &aux_action_2, &aux_action_3};

        keymap_t * keymap_test = new_keymap(keys, actions, 3);
        keymap_t * next_keymap = keymap_test->next_key;
        keymap_t * last_keymap = next_keymap->next_key;

        make_test_title("keymaps");

        assert((keymap_test->key == keys[0]) &&
               (next_keymap->key == keys[1]) &&
               (last_keymap->key == keys[2])
               , "keys");

        assert((keymap_test->action == actions[0]) &&
               (next_keymap->action == actions[1]) &&
               (last_keymap->action == actions[2])
               , "actions");

        free(keymap_test);

        end_test_title("keymaps");

        return 0;
}
