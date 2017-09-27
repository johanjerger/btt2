#include <stdlib.h>
#include <string.h>
#include "includes/menus.h"
#include "includes/menus_shows.h"
#include "../options/includes/options_generator.h"

menu * new_menu(char * title, options_list * options, int (*show_menu)(menu *))
{
        menu * new_menu = malloc(sizeof(menu));

        new_menu->title = malloc(strlen(title) + 1);
        strcpy(new_menu->title, title);
        new_menu->options = options;
        new_menu->show_menu = show_menu;

        return new_menu;
}

int auxiliar_menu_function(){

        return 0;
}

menu * new_main_menu()
{
        int size = 3;
        option * options[size];

        options[0] = selected_option("START", &auxiliar_menu_function);
        options[1] = unselected_option("CONFIGURATION", &auxiliar_menu_function);
        options[2] = unselected_option("EXIT", &auxiliar_menu_function);

        options_list * main_menu_options = new_options_list(options, size);

        return new_menu("MAIN MENU", main_menu_options, &show_main_menu);
}
