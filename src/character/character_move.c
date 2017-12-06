#include "include/character.h"

/*
 *  This modules defines the game's characters
 *  moves, everyone moves with a different strategy.
 */

int drugo_move (character_t * drugo)
{
        drugo->pos_x = 4;
        return 8;
}


int pterodactyl_move (character_t * pterodactyl)
{
        return 0;
}
