#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/output.h"

void
difficult_menu()
{
		menu_t * difficult_menu = new_difficult_menu();
		keymap_t * difficult_keymap = new_difficult_menu_keymap();

		difficult_loop = true;
		while (difficult_loop)
		{
				set_screen();
				difficult_menu->show(difficult_menu);
				difficult_keymap->execute(difficult_menu, difficult_keymap);
		}

		difficult_menu->destroy(difficult_menu);
		difficult_keymap->destroy(difficult_keymap);
}
