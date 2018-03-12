#include <stdio.h>
#include <stdlib.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "../score/include/score.h"
#include "include/score_table.h"

void
score_table_add (score_table_t * score_table, score_t * final_score)
{
		FILE * score_table_file = NULL;
		score_t * scores[score_table->size + 1];

		score_table_file = score_table->open(score_table);
		for (int i = 0; i != score_table->size; i++)
		{
				score_t * aux_scr = final_score->read(score_table_file);
				scores[i] = new_score(aux_scr->player_name, aux_scr->points, aux_scr->level);
		}
		scores[score_table->size] = final_score;

		qsort(scores, score_table->size + 1, sizeof(score_t *), final_score->compare);
		fclose(score_table_file);
		score_table_file = fopen(score_table->file_name, "w");
		check_error(score_table_file, NULL, CREATE_ERROR,
		            CREATE_ERROR_MSG_SCORE_TABLE);
		for (int i = score_table->size; i != 0; i--)
		{
				final_score->write(score_table_file, scores[i]);
		}
		fclose(score_table_file);
}
