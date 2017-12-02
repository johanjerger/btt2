#include <stdlib.h>
#include "include/character.h"
#include "include/character_move.h"
#include "include/character_attack.h"

/*
 *  This modules defines the game's characters,
 *  developing his moves and special attacks and
 *  defining some constructors to improve the
 *  easy understanding of the code.
 */

character * generate_character (char body, int x, int y,
                               int (*move)(character *),
                               int (*attack)(character *))
{
        // Abtract generation method. Never used directly.

        character * new_character = malloc(sizeof(character));

        new_character->body = body;
        new_character->pos_x = x;
        new_character->pos_y = y;
        new_character->move = move;
        new_character->attack = attack;

        return new_character;

}

character * drugo (int x, int y)
{
        return generate_character('#', x, y, &drugo_move, &drugo_attack);
}

character * pterodactyl (int x, int y)
{
        return generate_character('<', x, y, &pterodactyl_move, &pterodactyl_attack);
}
