#include <string.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/score.h"


score_t * new_score(char * player_name, uint32_t points, int level)
{
        score_t * new_score;

        new_score = (score_t *) malloc(sizeof(score_t *));
        check_error(new_score, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE);

        new_score->player_name = (char *) malloc(sizeof(name) + 1);
        check_error(new_score->player_name, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_PLAYER);

        strcpy(new_score->player_name, player_name);
        new_score->points = points;
        new_score->level = level;

        return new_score;
}
