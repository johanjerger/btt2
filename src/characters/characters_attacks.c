#include <stdio.h>
#include <stdlib.h>
#include "includes/characters.h"

/*
 *  This modules defines the game's characters
 *  attacks, everyone attacks with a different strategy.
 */

int attack_drugo(character * drugo)
{
        drugo->posX = 4;
        return 9;
}


int attack_pterodactyl(character * pterodactyl)
{
        return 0;
}
