#include <stdlib.h>
#include "include/option_list.h"

void option_list_destroy(option_list_t * option_list)
{
        option_list_t * head = option_list;

        while (head->next != head) {
                head->option->destroy(head->option);
                free(head->option);
                head = head->next;
        }
}
