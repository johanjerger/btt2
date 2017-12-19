#include <stdlib.h>
#include "include/menu.h"
#include "../option/include/option_show.h"

// menu->selected_option->select_next(menu->selected_option);

void select_next_option(menu_t * menu)
{
        menu->selected_option->select_next(menu->selected_option);
        menu->selected_option = menu->selected_option->next;
}

void select_previous_option(menu_t * menu)
{
        menu->selected_option->select_previous(menu->selected_option);
        menu->selected_option = menu->selected_option->previous;
}
