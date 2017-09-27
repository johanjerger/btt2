#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/test.h"
#include "../src/menus/includes/menus.h"
#include "../src/menus/includes/menus_generator.h"
#include "../src/menus/includes/menus_shows.h"
#include "../src/options/includes/options.h"
#include "../src/options/includes/options_generator.h"
#include "../src/options/includes/options_shows.h"

int auxiliar_menu_test_function(){
        return 0;
}

int menus_test()
{
        menu * main_menu = new_main_menu();

        make_test_title("menus");

        assert(strcmp(main_menu->title, "MAIN MENU") == 0
               , "title");

        assert(main_menu->show_menu == &show_main_menu
               , "show menu");

        end_test_title("menus");

        free(main_menu);

        return 0;
}
