#include <stdio.h>
#include <stdlib.h>
#include "include/score.h"

score_t * score_read (FILE * score_table_file)
{
        score_t * score = NULL;
        fread(score, sizeof(score_t), 1, score_table_file);
        printf("%s\n", score->player_name);
        return score;
}


void score_write (FILE * score_table_file, score_t * score)
{
        fwrite(score, sizeof(score_t), 1, score_table_file);
}
