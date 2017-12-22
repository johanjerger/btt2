#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"
#include "include/scores_menu.h"

int main()
{
        menu_t * main_menu = new_main_menu();
        keymap_t * main_menu_keymap = new_main_menu_keymap();
        main_menu->show(main_menu);

        while(true) {
                char key;
                key = btt_getch();

                main_menu_keymap->exec(main_menu, main_menu_keymap, key);
                main_menu->show(main_menu);
        }

        free(main_menu);
        free(main_menu_keymap);
        return 0;
}
