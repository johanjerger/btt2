#include <stdio.h>
#include <stdlib.h>
#include "include/keymap.h"
#include "include/execute.h"
#include "include/append.h"
#include "include/destroy.h"
#include "../include/btt2.h"
#include "../menu/include/menu.h"
#include "../menu/include/change_option.h"
#include "../menu/include/execute.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"

keymap_t *
new_keymap (char key, void (*action)())
{
		keymap_t * new_keymap;

		new_keymap = (keymap_t *) malloc(sizeof(keymap_t));
		check_error(new_keymap, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_KEYMAP);

		new_keymap->key = key;
		new_keymap->action = action;
		new_keymap->execute = execute_keymap_action;
		new_keymap->next_key = new_keymap;
		new_keymap->append = keymap_append;
		new_keymap->destroy = keymap_destroy;

		return new_keymap;
}

keymap_t *
new_main_menu_keymap (void)
{
		keymap_t * keymap = new_keymap(keys[UP], select_previous_option);
		keymap->append(keymap, keys[DOWN], select_next_option);
		keymap->append(keymap, keys[ENTER], execute_menu);
		keymap->append(keymap, (char) 777, do_nothing);

		return keymap;
}

keymap_t *
new_difficult_menu_keymap (void)
{
		keymap_t * keymap = new_keymap(keys[UP], select_previous_option);
		keymap->append(keymap, keys[DOWN], select_next_option);
		keymap->append(keymap, keys[ENTER], execute_menu);
		keymap->append(keymap, (char) 777, do_nothing);

		return keymap;
}

keymap_t *
new_scores_keymap (void)
{
		keymap_t * keymap = new_keymap(keys[LEFT], select_previous_option);
		keymap->append(keymap, keys[RIGHT], select_next_option);
		keymap->append(keymap, keys[ENTER], execute_menu);
		keymap->append(keymap, (char) 777, do_nothing);

		return keymap;
}

keymap_t *
new_config_menu_keymap (void)
{
		keymap_t * keymap = new_keymap(keys[UP], select_previous_option);
		keymap->append(keymap, keys[DOWN], select_next_option);
		keymap->append(keymap, keys[ENTER], execute_menu);
		keymap->append(keymap, (char) 777, do_nothing);

		return keymap;
}
