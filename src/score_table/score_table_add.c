#include <stdio.h>
#include <stdlib.h>
#include "../score/include/score.h"
#include "include/score_table.h"

void score_table_add (score_table_t * score_table, score_t * new_score)
{
        FILE * score_table_file;
        score_t * scores[SCORE_TABLE_SIZE + 1];

        score_table->open(score_table_file);

        for (int i = 0; i < SCORE_TABLE_SIZE; i++) {
                scores[i] = new_score->read(score_table_file);
        }
        scores[SCORE_TABLE_SIZE] = new_score;

        qsort(scores, size, sizeof(score_t), new_score->compare);

        for (int i = SCORE_TABLE_SIZE; i > 0; i--) {
                new_score->write(score_table_file, scores[i]);
        }

        fclose(score_table_file);
}
