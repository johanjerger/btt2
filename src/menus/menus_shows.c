#include <stdio.h>
#include "includes/menus.h"
#include "../options/includes/options.h"
#include "../options/includes/options_generator.h"
#include "../options_list/includes/options_list.h"

int show_main_menu(menu * main_menu)
{
        options_list head = *(main_menu->options);
        options_list * first_option = main_menu->options;

        printf("%s\n", main_menu->title);

        while(head.next_option != first_option) {
                (head.option)->show_option(head.option);
                head = *(head.next_option);
        }

        (head.option)->show_option(head.option);

        return 0;
}
