#include <stdlib.h>
#include "include/option_list.h"

void option_list_append(option_list_t * opt_list, option_t * opt)
{
        option_list_t * new_option_list = new_options_list(opt);
        option_list_t * head = opt_list;

        while (head->next != NULL) {
          head = head->next;
        }

        head->next = new_option_list;
        new_option_list->previous = head;
}
