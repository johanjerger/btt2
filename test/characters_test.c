#include <stdio.h>
#include <stdlib.h>
#include "includes/test.h"
#include "../src/characters/includes/characters.h"
#include "../src/characters/includes/characters_attacks.h"
#include "../src/characters/includes/characters_moves.h"

int characters_test()
{
        int pos_x = 2, pos_y = 5;
        character * new_drugo = drugo(pos_x, pos_y);
        character * new_pterodactyl = pterodactyl(pos_x, pos_y);

        make_test_title("characters");

        assert(new_drugo->body == '#' && new_pterodactyl->body == '<', "body");

        assert(new_drugo->pos_x == pos_x && new_pterodactyl->pos_x == pos_x, "pos_x");

        assert(new_drugo->pos_y == pos_y && new_pterodactyl->pos_y == pos_y, "pos_y");

        assert(new_drugo->move(new_drugo) == move_drugo(new_drugo), "move");

        assert(new_drugo->attack(new_drugo) == attack_drugo(new_drugo), "attack");

        end_test_title("characters");

        return 0;
}
