#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/test.h"
#include "../src/menu/include/menu.h"
#include "../src/menu/include/menu_show.h"
#include "../src/option/include/option.h"
#include "../src/option/include/option_show.h"

int menu_test()
{
        menu_t * main_menu = new_main_menu();

        make_test_title("menus");

        assert(strcmp(main_menu->title, "MAIN MENU") == 0
               , "title");

        assert(main_menu->show == &show_main_menu
               , "show menu");

        main_menu->next_option(main_menu);

        assert(main_menu->options->next->option->show == &show_selected_option
               , "next opt");

        main_menu->previous_option(main_menu);

        assert(main_menu->options->option->show == &show_selected_option
               , "prev opt");

        end_test_title("menus");

        free(main_menu);

        return 0;
}
