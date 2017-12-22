#include <stdlib.h>
#include <string.h>
#include "include/menu.h"
#include "include/menu_show.h"
#include "include/menu_option_change.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"

menu_t * new_menu(char * title, option_list_t * options,
                  int (*show_menu)(menu_t *))
{
        menu_t * new_menu;

        new_menu = (menu_t *) malloc(sizeof(menu_t));
        check_error(new_menu, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_MENU);

        new_menu->title = (char *) malloc(strlen(title) + 1);
        check_error(new_menu->title, NULL, MALLOC_ERROR,
                    MALLOC_ERROR_MSG_MENU_TITLE);

        strcpy(new_menu->title, title);
        new_menu->options = options;
        new_menu->selected_option = options;
        new_menu->show = show_menu;
        new_menu->next_option = select_next_option;
        new_menu->previous_option = select_previous_option;

        return new_menu;
}

menu_t * new_main_menu()
{
        option_list_t * main_menu_options = new_main_menu_options_list();

        return new_menu("MAIN MENU", main_menu_options, &show_main_menu);
}

menu_t * new_scores_menu()
{
        option_list_t * scores_options = new_scores_options_list();

        return new_menu("SCORE TABLE", scores_options, &show_scores);
}
