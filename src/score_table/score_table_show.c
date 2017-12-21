#include <stdio.h>
#include <stdlib.h>
#include "../score/include/score.h"
#include "include/score_table.h"

void score_table_show (score_table_t *)
{
        FILE * score_table_file;

        score_table->open(score_table_file);

        for (int i = 0; i < SCORE_TABLE_SIZE; i++) {
                score_t * score = new_score->read(score_table_file);
                score->show();
        }
}
