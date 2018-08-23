#include "include/menu.h"
#include "../option/include/option.h"

void
execute_menu (menu_t * actual_menu)
{
		option_t * option = actual_menu->selected_option->option;
		option->action(option);
}
