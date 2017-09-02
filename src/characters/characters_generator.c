#include <stdio.h>
#include <stdlib.h>
#include "includes/characters.h"
#include "includes/characters_moves.h"
#include "includes/characters_attacks.h"

/*
 *  This modules defines the game's characters,
 *  developing his moves and special attacks and
 *  defining some constructors to improve the
 *  easy understanding of the code.
 */

character generate_character(char body, int x, int y,
                             int (*move)(character *), int (*attack)(character *))
{
        // Abtract generation method. Never used directly.

        character new_character;

        new_character.body = body;
        new_character.posX = x;
        new_character.posY = y;
        new_character.move = move;
        new_character.attack = attack;

        return new_character;

}

character drugo(int x, int y)
{
        return generate_character('#', x, y, &move_drugo, &attack_drugo);
}

character pterodactyl(int x, int y)
{
        return generate_character('<', x, y, &move_pterodactyl, &attack_pterodactyl);
}
