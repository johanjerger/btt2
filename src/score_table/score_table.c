#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utility/include/utility.h"
#include "../utility/include/error.h"
#include "include/score_table.h"
#include "include/add.h"
#include "include/show.h"
#include "include/open.h"

score_table_t * new_score_table(char * file_name, char * title)
{
        score_table_t * new_score_table;
        char * path = SCORE_TABLE_PATH;

        new_score_table = (score_table_t *) malloc(sizeof(score_table_t));
        check_error(new_score_table, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE);

        new_score_table->file_name = (char *) malloc((strlen(file_name) + strlen(path)) * sizeof(char) + 1);
        check_error(new_score_table->file_name, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE_FILE);
        strcpy(new_score_table->file_name, path);
        strcat(new_score_table->file_name, file_name);

        new_score_table->title = (char *) malloc(strlen(file_name) * sizeof(char) + 1);
        check_error(new_score_table->title, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE_TITLE);
        strcpy(new_score_table->title, title);

        new_score_table->add = score_table_add;
        new_score_table->show = score_table_show;
        new_score_table->open = score_table_open;

        return new_score_table;
}
