#include <stdlib.h>
#include "../include/game.h"

void
generic_setter (int ammo, int max_ammo, int health, int max_health, int luck)
{
		start_ammo = ammo;
		maximum_ammo = max_ammo;
		start_health = health;
		maximum_health = max_health;
		start_luck = luck;
		game("level_1", NULL);
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
