#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"
#include "utility/include/output.h"

void
key_menu(option_t * option)
{
		menu_t * key_menu = new_key_menu(option->text);
		char key;

		bool key_loop = true;
		while (key_loop)
		{
				set_screen();
				key_menu->show(key_menu);

				// The key most be in a-z range
				key = btt_kbhit();

				if (key >= 'a' && key <= 'z')
				{
						keys[UP] = key;
						key_loop = false;
				}
				
		}

		//key_menu->destroy(key_menu);
}
