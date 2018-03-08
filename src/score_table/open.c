#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/score_table.h"

FILE *
score_table_open (score_table_t * score_table)
{
		FILE * score_table_file;
		score_table_file = fopen(score_table->file_name, "r");

		if (score_table_file == NULL)
		{
				score_table_file = fopen(score_table->file_name, "w");
				check_error(score_table_file, NULL, CREATE_ERROR,
				            CREATE_ERROR_MSG_SCORE_TABLE);
				for (int i = 0; i < score_table->size; i++)
				{
						score_t * score = new_score("GateLlman Job", 0, 1);
						score->write(score_table_file, score);
				}
				fclose(score_table_file);
				score_table_file = fopen(score_table->file_name, "r");
		}

		return score_table_file;
}
