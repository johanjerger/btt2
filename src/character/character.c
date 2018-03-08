#include <stdlib.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/character.h"
#include "include/move.h"
#include "include/attack.h"

// This modules defines the game's characters, developing his
// moves and special attacks and  defining some constructors
// to improve the easy understanding of the code.
character_t *
generate_character (int body, int pos_x, int pos_y, int (*move)(character_t *),
                    int (*attack)(character_t *))
{
		character_t * new_character;

		new_character = (character_t *) malloc(sizeof(character_t));
		check_error(new_character, NULL, MALLOC_ERROR,
		            MALLOC_ERROR_MSG_CHARACTER);

		new_character->body = body;
		new_character->pos_x = pos_x;
		new_character->pos_y = pos_y;
		new_character->move = move;
		new_character->attack = attack;

		return new_character;
}

character_t *
new_drugo (int pos_x, int pos_y)
{
		return generate_character('.', pos_x, pos_y, drugo_move, drugo_attack);
}

character_t *
new_pterodactyl (int pos_x, int pos_y)
{
		return generate_character('<', pos_x, pos_y, ptero_move, ptero_attack);
}
