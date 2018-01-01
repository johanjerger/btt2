#ifndef BTT2_ERR_H
#define BTT2_ERR_H

#define MALLOC_ERROR 63035
#define CLEAR_ERROR 45731
#define SLEEP_ERROR 23967
#define CREATE_ERROR 63375
#define ERROR_CREATING_DIRECTORY 111 // Modify later
#define MALLOC_ERROR_MSG_CHARACTER "error while allocting character_t type pointer."
#define MALLOC_ERROR_MSG_KEYMAP "error while allocting keymap_t type pointer."
#define MALLOC_ERROR_MSG_MENU "error while allocting menu_t type pointer."
#define MALLOC_ERROR_MSG_MENU_TITLE "error while allocting char * type pointer in menu.c."
#define MALLOC_ERROR_MSG_OPTION "error while allocting option_t type pointer."
#define MALLOC_ERROR_MSG_OPTION_LIST "error while allocting option_list_t type pointer."
#define MALLOC_ERROR_MSG_SCORE "error while allocting score_t type pointer."
#define MALLOC_ERROR_MSG_SCORE_PLAYER "error while allocting char * type in score.c pointer."
#define MALLOC_ERROR_MSG_SCORE_TABLE "error while allocting score_table_t type pointer in 'score_table/score_table.c'."
#define MALLOC_ERROR_MSG_SCORE_TABLE_FILE "error while allocting char * type pointer for table file name in 'score_table/score_table.c'."
#define MALLOC_ERROR_MSG_SCORE_TABLE_TITLE "error while allocting char * type pointer for table title in 'score_table/score_table.c'."
#define CLEAR_ERROR_MSG "error calling clear function (defined in utility.c)"
#define SLEEP_ERROR_MSG "error calling sleep function (defined in utility.c)"
#define ERROR_CREATING_DIRECTORY_MSG "Unable to create configuration path in 'configuration/configuration.c'"
#define CREATE_ERROR_MSG_SCORE_TABLE "error while creating score table file in 'score_table/open.c'"

#endif
