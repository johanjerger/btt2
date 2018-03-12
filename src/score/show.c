#include <stdio.h>
#include "include/score.h"

void
score_show (score_t * score)
{
		printf("%18s%-21s%-16d%-10d\n",
		       "", score->player_name, score->points, score->level);
}
