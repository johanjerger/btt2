#include <stdio.h>
#include <stdlib.h>
#include "menus/includes/menus.h"
#include "menus/includes/menus_generator.h"

int main()
{
        menu * main_menu = new_main_menu();

        main_menu->show_menu(main_menu);
        
        return 0;
}
