#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/score.h"
#include "../utility/include/output.h"
#include "../include/btt2.h"

void
score_show (score_t * score)
{
		char points[16];
		char level[10];

		sprintf(points, "%d", score->points);
		sprintf(level, "%d", score->level);
		printf("%s%s%s%s\n",
		       center_output("", 18),
		       left_output(score->player_name, 21),
		       left_output(points, 16),
		       left_output(level, 10));
}
