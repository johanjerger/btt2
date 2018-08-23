#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/output.h"

void
config_menu()
{
		menu_t * config_menu = new_config_menu();
		keymap_t * config_keymap = new_config_menu_keymap();

		config_loop = true;
		while (config_loop)
		{
				set_screen();
				config_menu->show(config_menu);
				config_keymap->execute(config_menu, config_keymap);
		}

		config_menu->destroy(config_menu);
		config_keymap->destroy(config_keymap);
}
