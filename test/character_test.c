#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "include/test.h"
#include "../src/character/include/character.h"
#include "../src/character/include/character_attack.h"
#include "../src/character/include/character_move.h"

int character_test()
{
        uint16_t pos_x = 2, pos_y = 5;
        character_t * new_drugo = drugo(pos_x, pos_y);
        character_t * new_pterodactyl = pterodactyl(pos_x, pos_y);

        make_test_title("characters");

        assert(new_drugo->body == '#' && new_pterodactyl->body == '<', "body");

        assert(new_drugo->pos_x == pos_x && new_pterodactyl->pos_x == pos_x, "pos_x");

        assert(new_drugo->pos_y == pos_y && new_pterodactyl->pos_y == pos_y, "pos_y");

        assert(new_drugo->move(new_drugo) == drugo_move(new_drugo), "move");

        assert(new_drugo->attack(new_drugo) == drugo_attack(new_drugo), "attack");

        end_test_title("characters");

        return 0;
}
