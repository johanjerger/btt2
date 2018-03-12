#include <stdio.h>
#include "include/score.h"

int
score_compare (const void * actual, const void * other)
{
		score_t * actual_score = *((score_t **) actual);
		score_t * other_score = *((score_t **) other);
		int actual_points = actual_score->points;
		int other_points = other_score->points;
		if (actual_points > other_points) return 1;
		if (actual_points < other_points) return -1;
		return 0;
}
