#include "include/character.h"

/*
 *  This modules defines the game's characters
 *  attacks, everyone attacks with a different strategy.
 */

int drugo_attack (character_t * drugo)
{
        drugo->pos_x = 4;
        return 9;
}


int ptero_attack (character_t * ptero)
{
        return 0;
}
