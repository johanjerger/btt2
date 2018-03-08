#include "include/score.h"

int
score_compare (const void * actual, const void * other)
{
		int actual_points = (int) ((score_t *) actual)->points;
		int other_points = (int) ((score_t *) other)->points;
		return actual_points - other_points;
}
