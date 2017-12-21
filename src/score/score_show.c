#include "include/score.h"

void score_show (score_t * score)
{
        printf("%s\t%g\t%d\n", score->player_name, score->points, score->level);
}
