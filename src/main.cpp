#include <iostream>

#include "menu/menu.hpp"

int main()
{
	btt::Menu main_menu = btt::Menu("Main Menu");
        std::cout << "Hello CMake" << std::endl;
	std::cout << "The menu title is " << main_menu.title() << std::endl;
	return 0;
}
