#include <stdio.h>
#include <stdlib.h>
#include "includes/characters.h"

/*
 *  This modules defines the game's characters
 *  moves, everyone moves with a different strategy.
 */

int move_drugo(character * drugo)
{
        drugo->posX = 4;
        return 8;
}


int move_pterodactyl(character * pterodactyl)
{
        return 0;
}
