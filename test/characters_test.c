#include <stdio.h>
#include <stdlib.h>
#include "../src/characters/includes/characters.h"
#include "../src/characters/includes/characters_generator.h"
#include "../src/characters/includes/characters_attacks.h"
#include "../src/characters/includes/characters_moves.h"
#include "../src/utilities/includes/colors.h"
#include "../src/utilities/includes/utilities.h"

int characters_test()
{
        int posX = 2, posY = 5;
        character new_drugo = drugo(posX, posY);
        character new_pterodactyl = pterodactyl(posX, posY);

        printf(GREEN "\n BEGINING Characters.c TEST\n\n" RESET);

        sleep(500);

        (new_drugo.body == '#' && new_pterodactyl.body == '<') ?
        printf(GREEN "\t - Body method    .................................... SUCCESS \n" RESET) :
        fprintf(stderr, RED "\t - Body method    .................................... FAIL \n" RESET);

        sleep(500);

        (new_drugo.posX == posX && new_pterodactyl.posX == posX) ?
        printf(GREEN "\t - posX method    .................................... SUCCESS \n" RESET) :
        fprintf(stderr, RED "\t - posX method    .................................... FAIL \n" RESET);

        sleep(500);

        (new_drugo.posY == posY && new_pterodactyl.posY == posY) ?
        printf(GREEN "\t - posY method    .................................... SUCCESS \n" RESET) :
        fprintf(stderr, RED "\t - posY method    .................................... FAIL \n" RESET);

        sleep(500);

        (new_drugo.move(&new_drugo) == move_drugo(&new_drugo) &&
         new_pterodactyl.move(&new_pterodactyl) == move_pterodactyl(&new_pterodactyl)) ?
        printf(GREEN "\t - Moves method   .................................... SUCCESS \n" RESET) :
        fprintf(stderr, RED "\t - Moves method   ..................................... FAIL \n" RESET);

        sleep(500);

        (new_drugo.attack(&new_drugo) == attack_drugo(&new_drugo) &&
         new_pterodactyl.attack(&new_pterodactyl) == attack_pterodactyl(&new_pterodactyl)) ?
        printf(GREEN "\t - Attacks method .................................... SUCCESS \n" RESET) :
        fprintf(stderr, RED "\t - Attacks method ....................................... FAIL \n" RESET);

        sleep(500);

        printf(GREEN "\n Characters.c TEST FINISH\n\n" RESET);

        return 0;
}
