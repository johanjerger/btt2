#include <stdlib.h>
#include "include/menu.h"

void menu_destroy(menu_t * menu)
{
        free(menu->title);
        menu->options->destroy(menu->options);
        free(menu->options);
        free(menu->selected_option);
}
