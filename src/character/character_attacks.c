#include "include/character.h"

/*
 *  This modules defines the game's characters
 *  attacks, everyone attacks with a different strategy.
 */

int drugo_attack (character * drugo)
{
        drugo->pos_x = 4;
        return 9;
}


int pterodactyl_attack (character * pterodactyl)
{
        return 0;
}
