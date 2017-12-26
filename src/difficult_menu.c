#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"

int difficult_menu()
{
        menu_t * difficult_menu = new_difficult_menu();
        keymap_t * difficult_menu_keymap = new_difficult_menu_keymap();

        difficult = true;
        while(difficult) {
                difficult_menu->show(difficult_menu);
                char key;
                key = btt_getch();
                difficult_menu_keymap->execute(difficult_menu, difficult_menu_keymap, key);
        }

        return 0;
}
