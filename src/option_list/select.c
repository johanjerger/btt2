#include "include/option_list.h"

void
option_list_select_next (option_list_t * option_list)
{
		option_list->option->unselect(option_list->option);
		option_list->option->select(option_list->next->option);
}

void
option_list_select_previous (option_list_t * option_list)
{
		option_list->option->unselect(option_list->option);
		option_list->option->select(option_list->previous->option);
}
