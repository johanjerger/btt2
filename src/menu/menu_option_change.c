#include "include/menu.h"
#include "../option/include/option_show.h"

void select_next_option(menu_t * actual_menu)
{
        actual_menu->selected_option->option->unselect(actual_menu->selected_option->option);
        actual_menu->selected_option = actual_menu->selected_option->next;
        actual_menu->selected_option->option->select(actual_menu->selected_option->option);
}

void select_previous_option(menu_t * actual_menu)
{
        actual_menu->selected_option->option->unselect(actual_menu->selected_option->option);
        actual_menu->selected_option = actual_menu->selected_option->previous;
        actual_menu->selected_option->option->select(actual_menu->selected_option->option);
}
