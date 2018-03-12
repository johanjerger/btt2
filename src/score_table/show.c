#include <stdio.h>
#include <stdlib.h>
#include "../score/include/score.h"
#include "include/score_table.h"
#include "../utility/include/output.h"

void
score_table_show (score_table_t * score_table)
{
		FILE * score_table_file = NULL;
		score_t * aux_score = new_score("aux", 0, 1);
		score_table_file = score_table->open(score_table);
		printf("%s%s%s%s\n",
		       center_output("", 18),
		       left_output("Name", 21),
		       left_output("Score", 16),
		       left_output("Level", 10));
		for (int i = 0; i != score_table->size; i++)
		{
				score_t * score = aux_score->read(score_table_file);
				score->show(score);
		}
		fclose(score_table_file);
}
