#include <stdlib.h>
#include <string.h>
#include "includes/menus.h"
#include "includes/menus_shows.h"
#include "includes/menus_options_change.h"
#include "../keymaps/includes/keymaps.h"

menu * new_menu(char * title, options_list * options, int (*show_menu)(menu *))
{
        menu * new_menu = malloc(sizeof(menu));

        new_menu->title = malloc(strlen(title) + 1);
        strcpy(new_menu->title, title);
        new_menu->options = options;
        new_menu->selected_option = options;
        new_menu->show_menu = show_menu;
        new_menu->select_next_option = &select_next_option;
        new_menu->select_previous_option = &select_previous_option;

        return new_menu;
}

menu * new_main_menu()
{
        options_list * main_menu_options = new_main_menu_options_list();

        return new_menu("MAIN MENU", main_menu_options, &show_main_menu);
}
