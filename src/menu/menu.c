#include <stdlib.h>
#include <string.h>
#include "include/menu.h"
#include "include/menu_show.h"
#include "include/menu_option_change.h"

menu_t * new_menu(char * title, option_list_t * options, int (*show_menu)(menu_t *))
{
        menu_t * new_menu = (menu_t *) malloc(sizeof(menu_t));

        new_menu->title = (char *) malloc(strlen(title) + 1);
        strcpy(new_menu->title, title);
        new_menu->options = options;
        new_menu->selected_option = options;
        new_menu->show = show_menu;
        new_menu->next_option = select_next_option;
        new_menu->previous_option = select_previous_option;

        return new_menu;
}

menu_t * new_main_menu()
{
        option_list_t * main_menu_options = new_main_menu_options_list();

        return new_menu("MAIN MENU", main_menu_options, &show_main_menu);
}
