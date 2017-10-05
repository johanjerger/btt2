#include <stdio.h>
#include <string.h>
#include "includes/test.h"
#include "../src/menus/includes/menus.h"
#include "../src/menus/includes/menus_generator.h"
#include "../src/keymaps/includes/keymaps.h"

int aux_action_1(menu * main_menu) { return 1; }

int aux_action_2(menu * main_menu) { return 2; }

int aux_action_3(menu * main_menu) { return 3; }

int keymaps_test()
{

  char keys[3] = {'w', 's', '\n'};
  int(*actions[3])() = {&aux_action_1, &aux_action_2, &aux_action_3};

  menu * main_menu = new_main_menu();

  keymap * keymap_test = new_keymap(keys, actions, 3);
  keymap * next_keymap = keymap_test->next_key;
  keymap * last_keymap = next_keymap->next_key;

  make_test_title("keymaps");

  assert((keymap_test->key == keys[0]) &&
         (next_keymap->key == keys[1]) &&
         (last_keymap->key == keys[2])
         , "keys");

  assert((keymap_test->action() == actions[0]()) &&
         (next_keymap->action() == actions[1]()) &&
         (last_keymap->action() == actions[2]())
         , "actions");

  assert((keymap_test->exec(main_menu, keymap_test, keys[0]) == actions[0]()) &&
         (keymap_test->exec(main_menu, keymap_test, keys[1]) == actions[1]()) &&
         (keymap_test->exec(main_menu, keymap_test, keys[2]) == actions[2]())
         , "exec");

  end_test_title("keymaps");

  return 0;
}
