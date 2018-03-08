#include <stdio.h>
#include "include/score.h"

void
score_show (score_t * score)
{
		printf("\t%s\t\t%d\t\t%d\n",
		       score->player_name, score->points, score->level);
}
