#pragma once

#include <iostream>

namespace btt
{
inline namespace menu
{
class Menu
{
        private:
		std::string m_title;


	public:
		Menu(std::string);
		std::string title();
};
} // namespace menu
} // namespace btt
