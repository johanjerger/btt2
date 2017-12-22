#include "include/menu.h"

void execute_menu(menu_t * actual_menu)
{
        actual_menu->selected_option->option->action();
}
