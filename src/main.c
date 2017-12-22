#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"
#include "include/scores_menu.h"

int main()
{
        game = true;
        menu_t * main_menu = new_main_menu();
        keymap_t * main_menu_keymap = new_main_menu_keymap();

        while(true && game) {
                main_menu->show(main_menu);
                char key;
                key = btt_getch();
                main_menu_keymap->exec(main_menu, main_menu_keymap, key);
        }

        main_menu->destroy(main_menu);
        free(main_menu);
        free(main_menu_keymap);
        return 0;
}
