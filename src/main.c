#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menus/includes/menus.h"
#include "keymaps/includes/keymaps.h"
#include "utilities/includes/inputs.h"

int main()
{
        menu * main_menu = new_main_menu();
        keymap * main_menu_keymap = new_main_menu_keymap();

        main_menu->show_menu(main_menu);

        while(true) {
                char key;

                key = getch();
                main_menu_keymap->exec(main_menu, main_menu_keymap, key);
                main_menu->show_menu(main_menu);
        }

        return 0;
}
