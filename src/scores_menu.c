#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/output.h"

void
scores_menu (void)
{
		menu_t * scores_menu = new_scores_menu();
		keymap_t * scores_keymap = new_scores_keymap();

		scores_loop = true;
		while (scores_loop)
		{
				set_screen();
				scores_menu->show(scores_menu);
				scores_keymap->execute(scores_menu, scores_keymap);
		}

		scores_menu->destroy(scores_menu);
		scores_keymap->destroy(scores_keymap);
}
