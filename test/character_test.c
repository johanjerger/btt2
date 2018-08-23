#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "include/test.h"
#include "../src/character/include/character.h"
#include "../src/character/include/attack.h"
#include "../src/character/include/move.h"

int
character_test()
{
        uint16_t pos_x = 2, pos_y = 5;
        character_t * drugo = new_drugo(pos_x, pos_y);
        character_t * pterodactyl = new_pterodactyl(pos_x, pos_y);

        make_test_title("characters");

        assert(drugo->body == '.' && pterodactyl->body == '<', "body");

        assert(drugo->pos_x == pos_x && pterodactyl->pos_x == pos_x, "pos_x");

        assert(drugo->pos_y == pos_y && pterodactyl->pos_y == pos_y, "pos_y");

        assert(drugo->move == drugo_move, "move");

        assert(drugo->attack == drugo_attack, "attack");

        free(drugo);
        free(pterodactyl);

        end_test_title("characters");

        return 0;
}
