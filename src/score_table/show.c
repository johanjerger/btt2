#include <stdio.h>
#include <stdlib.h>
#include "../score/include/score.h"
#include "include/score_table.h"

void score_table_show (score_table_t * score_table)
{
        FILE * score_table_file = NULL;
        score_t * aux_score = new_score("aux", 0, 1);
        score_table_file = score_table->open(score_table);
        for (int i = 0; i < SCORE_TABLE_SIZE; i++) {
                score_t * score = aux_score->read(score_table_file);
                score->show(score);
        }
        fclose(score_table_file);
}