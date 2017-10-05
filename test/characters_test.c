#include <stdio.h>
#include <stdlib.h>
#include "includes/test.h"
#include "../src/characters/includes/characters.h"
#include "../src/characters/includes/characters_attacks.h"
#include "../src/characters/includes/characters_moves.h"

int characters_test()
{
        int posX = 2, posY = 5;
        character * new_drugo = drugo(posX, posY);
        character * new_pterodactyl = pterodactyl(posX, posY);

        make_test_title("characters");

        assert(new_drugo->body == '#' && new_pterodactyl->body == '<', "body");

        assert(new_drugo->posX == posX && new_pterodactyl->posX == posX, "posX");

        assert(new_drugo->posY == posY && new_pterodactyl->posY == posY, "posY");

        assert(new_drugo->move(new_drugo) == move_drugo(new_drugo), "move");

        assert(new_drugo->attack(new_drugo) == attack_drugo(new_drugo), "attack");

        end_test_title("characters");

        return 0;
}
