#include <stdlib.h>
#include "include/option_list.h"

void option_list_append(option_list_t * opt_list, option_t * opt)
{
        option_list_t * new_element = new_option_list(opt);
        option_list_t * last_element = opt_list->previous;

        new_element->next = opt_list;
        new_element->previous = last_element;
        opt_list->previous = new_element;
        last_element->next = new_element;
}
