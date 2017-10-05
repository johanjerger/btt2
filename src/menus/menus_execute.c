#include "includes/menus.h"

int execute_menu(menu * actual_menu)
{
        return actual_menu->selected_option->option->active_option();
}
