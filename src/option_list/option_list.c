#include <stdlib.h>
#include "include/option_list.h"
#include "include/option_list_append.h"
#include "../option/include/option.h"
#include "../utility/include/utility.h"

option_list_t * new_option_list(option_t * opt)
{
        option_list_t * new_option_list;

        new_option_list = malloc(sizeof(option_list_t));
        new_option_list->option = opt;
        new_option_list->next = NULL;
        new_option_list->previous = NULL;
        new_option_list->append = option_list_append;

        return new_option_list;
}

option_list_t * new_main_menu_options_list()
{
        option_list_t * option_list = new_option_list(selected_option("START", &go_out));
        option_list->append(option_list, unselected_option("CONFIG", &go_out));
        option_list->append(option_list, unselected_option("EXIT", &go_out));
        return option_list;
}
