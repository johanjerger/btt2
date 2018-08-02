#include <string.h>
#include "include/keymap.h"
#include "../utility/include/input.h"
#include "../utility/include/utility.h"

void
execute_keymap_action (menu_t * actual_menu, keymap_t * actual_keymap)
{
		keymap_t * head = actual_keymap;
		char key = btt_kbhit();

		while (head->key != key && head != head->next_key)
		{
				head = head->next_key;
		}
		head->action(actual_menu);
}
