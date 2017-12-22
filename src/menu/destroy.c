#include <stdlib.h>
#include "include/menu.h"

void menu_destroy(menu_t * menu)
{
        free(menu->title);
        menu->options->destroy(menu->options);
        menu->selected_option->destroy(menu->selected_option);
        free(menu->options);
        free(menu->selected_option);
}
