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

        new_score_table = (score_table_t *) malloc(sizeof(score_table_t *));
        check_error(new_score_table, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE);

        new_score_table->file_name = (char *) malloc(sizeof(file_name) + sizeof(path) + 1);
        check_error(new_score_table->file_name, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE_FILE);
        printf("creating table %s\n", file_name);
        btt_sleep(500);
        strcpy(new_score_table->file_name, path);
        printf("created table in %s\n", new_score_table->file_name);
        strcat(new_score_table->file_name, file_name);
        printf("created table as %s\n", new_score_table->file_name);
        btt_sleep(500);
        printf("survive?0\n");

        new_score_table->title = (char *) malloc(sizeof(title) + 1);
        printf("survive?0.5\n");
        check_error(new_score_table->title, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_SCORE_TABLE_TITLE);
        strcpy(new_score_table->title, title);
        printf("survive?1\n");

        new_score_table->add = score_table_add;
        new_score_table->show = score_table_show;
        new_score_table->open = score_table_open;

        printf("survive?2\n");

        return new_score_table;
}
