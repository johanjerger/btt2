#include <stdlib.h>
#include "include/option_list.h"
#include "include/option_list_append.h"
#include "include/option_list_select.h"
#include "../option/include/option.h"
#include "../utility/include/utility.h"

option_list_t * new_option_list(option_t * opt)
{
        option_list_t * new_option_list;

        new_option_list = malloc(sizeof(option_list_t));
        new_option_list->option = opt;
        new_option_list->next = new_option_list;
        new_option_list->previous = new_option_list;
        new_option_list->append = option_list_append;
        new_option_list->select_next = option_list_select_next;
        new_option_list->select_previous = option_list_select_previous;

        return new_option_list;
}

option_list_t * new_main_menu_options_list()
{
        option_t * start_option = new_option("START", &go_out);
        option_t * configuration_option = new_option("CONFIG", &go_out);
        option_t * exit_option = new_option("EXIT", &go_out);

        start_option->select(start_option);

        option_list_t * option_list = new_option_list(start_option);
        option_list->append(option_list, configuration_option);
        option_list->append(option_list, exit_option);

        return option_list;
}
