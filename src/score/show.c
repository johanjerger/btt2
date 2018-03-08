#include <stdio.h>
#include "include/score.h"

void
score_show (score_t * score)
{
		printf("%s\t%d\t%d\n", score->player_name, score->points, score->level);
}
