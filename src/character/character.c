#include <stdlib.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/character.h"
#include "include/move.h"
#include "include/attack.h"

/*
 *  This modules defines the game's characters,
 *  developing his moves and special attacks and
 *  defining some constructors to improve the
 *  easy understanding of the code.
 */

character_t * generate_character (uint8_t body, uint16_t x, uint16_t y,
                                  int (*move)(character_t *),
                                  int (*attack)(character_t *))
{
        // Abtract generation method. Never used directly.

        character_t * new_character;

        new_character = (character_t *) malloc(sizeof(character_t));
        check_error(new_character, NULL, MALLOC_ERROR,
                    MALLOC_ERROR_MSG_CHARACTER);

        new_character->body = body;
        new_character->pos_x = x;
        new_character->pos_y = y;
        new_character->move = move;
        new_character->attack = attack;

        return new_character;

}

character_t * new_drugo (uint16_t x, uint16_t y)
{
        return generate_character('#', x, y, drugo_move, drugo_attack);
}

character_t * new_pterodactyl (uint16_t x, uint16_t y)
{
        return generate_character('<', x, y, ptero_move, ptero_attack);
}
