#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"
#include "utility/include/output.h"

void
key_menu(option_t * option, ...)
{
		menu_t * key_menu = new_key_menu(option->text);

		bool key_loop = true;
		while (key_loop)
		{
				set_screen();
				key_menu->show(key_menu);
		}

		key_menu->destroy(key_menu);
}
