#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/score_table.h"

score_table_t * new_score_table(char * file_name, char * title)
{
        score_table_t * new_score_table;

        new_score_table = (score_table_t *) malloc(sizeof(score_table_t *));
        check_error(new_score_table, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE);

        new_score_table->file_name = (char *) malloc(sizeof(file_name) + 1);
        check_error(new_score_table->file_name, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE_FILE);

        new_score_table->title = (char *) malloc(sizeof(title) + 1);
        check_error(new_score_table->title, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE_TITLE);
}
