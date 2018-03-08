#include <stdlib.h>
#include <string.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/score.h"
#include "include/compare.h"
#include "include/show.h"
#include "include/io.h"


score_t *
new_score (char * player_name, int points, int level)
{
		score_t * new_score;

		new_score = (score_t *) malloc(sizeof(score_t));
		check_error(new_score, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE);

		int to_alloc = strlen(player_name);
		new_score->player_name = (char *) malloc(to_alloc * sizeof(char) + 1);
		check_error(new_score->player_name, NULL, MALLOC_ERROR,
		            MALLOC_ERROR_MSG_SCORE_PLAYER);

		strcpy(new_score->player_name, player_name);
		new_score->points = points;
		new_score->level = level;
		new_score->compare = score_compare;
		new_score->show = score_show;
		new_score->write = score_write;
		new_score->read = score_read;

		return new_score;
}
