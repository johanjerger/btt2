#include "menu.hpp"

using namespace btt;

Menu::Menu(std::string t) : m_title(t) {}

std::string Menu::title() { return m_title; }

