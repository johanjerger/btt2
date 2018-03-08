#include "../include/game.h"

void
generic_setter (int str_ammo, int max_ammo, int str_health, int max_health,
                int str_luck)
{
		start_ammo = str_ammo;
		maximum_ammo = max_ammo;
		start_health = str_health;
		maximum_health = max_health;
		start_luck = str_luck;
		game();
}

void
set_easy_difficult (void)
{
		generic_setter(10, 50, 10, 20, 5);
}

void
set_normal_difficult (void)
{
		generic_setter(10, 30, 10, 15, 4);
}

void
set_hard_difficult (void)
{
		generic_setter(10, 20, 10, 10, 3);
}

void
set_very_hard_difficult (void)
{
		generic_setter(10, 15, 5, 5, 2);
}

void
set_hopeless_difficult (void)
{
		generic_setter(5, 5, 1, 1, 1);
}
