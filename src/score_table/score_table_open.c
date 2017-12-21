#include <stdio.h>
#include <stdlib.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/score_table.h"

void score_table_open(score_table_t * score_table, FILE * score_table_file)
{
        score_table_file = fopen(score_table->file_name, "r+");
        if(score_table_file == NULL) {
                score_table_file = fopen(score_table->file_name, "w+");
                check_error(score_table_file, NULL, CREATE_ERROR,
                            CREATE_ERROR_MSG_SCORE_TABLE);
                for (int i = 0; i < SCORE_TABLE_SIZE; ++i) {
                        score_t * score = new_score("GateLlman Job", 0, 1);
                        score->write(score_table_file, score);
                }
                rewind(score_table_file);
        }
}
