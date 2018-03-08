#include <stdio.h>
#include <stdlib.h>
#include "../score/include/score.h"
#include "include/score_table.h"

void
score_table_add (score_table_t * score_table, score_t * new_score)
{
		FILE * score_table_file = NULL;
		score_t * scores[score_table->size + 1];

		score_table_file = score_table->open(score_table);
		for (int i = 0; i < score_table->size; i++)
		{
				scores[i] = new_score->read(score_table_file);
		}
		scores[score_table->size] = new_score;
		qsort(scores, score_table->size + 1, sizeof(score_t), new_score->compare);
		for (int i = score_table->size; i != 0; i--)
		{
				new_score->write(score_table_file, scores[i]);
		}
		fclose(score_table_file);
}
