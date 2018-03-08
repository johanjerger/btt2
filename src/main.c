#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "configuration/include/configuration.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"

int
main (void)
{
		make_configuration();
		menu_t * main_menu = new_main_menu();
		keymap_t * main_menu_keymap = new_main_menu_keymap();

		game = true;
		while (game)
		{
				main_menu->show(main_menu);
				char key = btt_getch();
				main_menu_keymap->execute(main_menu, main_menu_keymap, key);
		}

		return 0;
}
