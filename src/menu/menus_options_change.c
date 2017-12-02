#include "includes/menus.h"
#include "../options/includes/options_shows.h"

int select_next_option(menu * actual_menu)
{

        actual_menu->selected_option->option->show_option = &show_option_unselected;
        actual_menu->selected_option = actual_menu->selected_option->next_option;
        actual_menu->selected_option->option->show_option = &show_option_selected;

        return 0;
}

int select_previous_option(menu * actual_menu)
{

        actual_menu->selected_option->option->show_option = &show_option_unselected;
        actual_menu->selected_option = actual_menu->selected_option->previous_option;
        actual_menu->selected_option->option->show_option = &show_option_selected;

        return 0;
}
