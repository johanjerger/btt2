#include <stdlib.h>
#include "include/option_list.h"

void
option_list_destroy (option_list_t * option_list)
{
		option_list_t * head = option_list;
		head = head->next;

		while (head->next != option_list)
		{
				head->option->destroy(head->option);
				option_list_t * aux_head = head->next;
				free(head);
				head = aux_head;
		}
		head->option->destroy(head->option);
		free(head);
		option_list->option->destroy(option_list->option);
		free(option_list);
}
