#include <stdio.h>
#include <stdlib.h>
#include "utilities/includes/utilities.h"
#include "menus/includes/menus.h"
#include "keymaps/includes/keymaps.h"
#include "menus/includes/menus_generator.h"

int main()
{
        menu * main_menu = new_main_menu();

        clear();
        main_menu->show_menu(main_menu);

        keymap * main_menu_keymap = new_main_menu_keymap();

        while(1){

          char key;

          //key = kbhit();

          //main_menu_keymap->exec(main_menu, main_menu_keymap, key);

          clear();
          main_menu->show_menu(main_menu);

        }

        return 0;
}
