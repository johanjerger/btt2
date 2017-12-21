#include <stdlib.h>
#include "include/option_list.h"

void option_list_append(option_list_t * opt_list, option_t * opt)
{
        option_list_t * new_element = new_option_list(opt);
        option_list_t * head = opt_list;

        while (head->next != head) {
                head = head->next;
        }

        head->next = new_element;
        new_element->previous = head;
        new_element->next = new_element;
}
