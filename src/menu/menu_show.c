#include <stdio.h>
#include "include/menu.h"
#include "../utility/include/utility.h"
#include "../option/include/option.h"
#include "../option_list/include/option_list.h"

int show_main_menu(menu_t * main_menu)
{
        option_list_t * head = main_menu->options;

        btt_clear();
        printf("%s\n", main_menu->title);

        while(head->next != head) {
                (head->option)->show(head->option);
                head = head->next;
        }

        (head->option)->show(head->option);

        return 0;
}
