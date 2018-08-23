#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "configuration/include/configuration.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/output.h"
#include "configuration/include/free_environment_variables.h"

int
main (void)
{
		make_configuration();
		menu_t * main_menu = new_main_menu();
		keymap_t * main_menu_keymap = new_main_menu_keymap();
		main_loop = true;
		while (main_loop)
		{
				set_screen();
				main_menu->show(main_menu);
				main_menu_keymap->execute(main_menu, main_menu_keymap);
		}

		free_environment_variables();
		main_menu->destroy(main_menu);
		main_menu_keymap->destroy(main_menu_keymap);
		return 0;
}
