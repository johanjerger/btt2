#include <stdlib.h>
#include <string.h>
#include "include/menu.h"
#include "include/show.h"
#include "include/destroy.h"
#include "include/change_option.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"

menu_t *
new_menu (char * title, option_list_t * options, void (*show_menu)(menu_t *))
{
		menu_t * new_menu;

		new_menu = (menu_t *) malloc(sizeof(menu_t));
		check_error(new_menu, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_MENU);

		new_menu->title = (char *) malloc(strlen(title) * sizeof(char) + 1);
		check_error(new_menu->title, NULL, MALLOC_ERROR,
		            MALLOC_ERROR_MSG_MENU_TITLE);

		strcpy(new_menu->title, title);
		new_menu->options = options;
		new_menu->selected_option = options;
		new_menu->show = show_menu;
		new_menu->next_option = select_next_option;
		new_menu->previous_option = select_previous_option;
		new_menu->destroy = menu_destroy;

		return new_menu;
}

menu_t * new_main_menu (void)
{
		option_list_t * main_menu_options = new_main_menu_options_list();
		return new_menu("MAIN MENU", main_menu_options, show_standard_menu);
}

menu_t * new_difficult_menu (void)
{
		option_list_t * difficult_options = new_difficult_options_list();
		return new_menu("DIFFICULT MENU", difficult_options, show_standard_menu);
}

menu_t * new_scores_menu (void)
{
		option_list_t * scores_options = new_scores_options_list();
		return new_menu("SCORE TABLE", scores_options, show_scores);
}

menu_t * new_config_menu (void)
{
		option_list_t * config_options = new_config_options_list();
		return new_menu("CONFIGURATION MENU", config_options, show_standard_menu);
}
