#ifndef BTT2_ERR_H
#define BTT2_ERR_H

#define MALLOC_ERROR 63035
#define CLEAR_ERROR 45731
#define SLEEP_ERROR 23967
#define CREATE_ERROR 63375
#define ERROR_CREATING_DIRECTORY 59649
#define FREAD_ERROR 5688
#define FWRITE_ERROR 12945
#define SCANF_ERROR_MSG "error doing the scanf function in 'utility/input.c'."
#define MALLOC_ERROR_MSG_CHARACTER "error allocating character_t pointer type."
#define MALLOC_ERROR_MSG_KEYMAP "error allocating keymap_t pointer type."
#define MALLOC_ERROR_MSG_MENU "error allocating menu_t pointer type."
#define MALLOC_ERROR_MSG_MENU_TITLE "error allocating char pointer type in menu.c."
#define MALLOC_ERROR_MSG_OPTION "error allocating option_t pointer type in 'option/option.c'."
#define MALLOC_ERROR_MSG_OPTION_TEXT "error allocating char pointer type for the options text in 'option/option.c'."
#define MALLOC_ERROR_MSG_OPTION_LIST "error allocating option_list_t pointer type."
#define MALLOC_ERROR_MSG_SCORE "error allocating score_t pointer type."
#define MALLOC_ERROR_MSG_SCORE_PLAYER "error allocating char pointer type in score.c."
#define MALLOC_ERROR_MSG_SCORE_TABLE "error allocating score_table_t pointer type in 'score_table/score_table.c'."
#define MALLOC_ERROR_MSG_SCORE_TABLE_FILE "error allocating char pointer type for table file name in 'score_table/score_table.c'."
#define MALLOC_ERROR_MSG_SCORE_TABLE_TITLE "error allocating char pointer type for table title in 'score_table/score_table.c'."
#define MALLOC_ERROR_MSG_HOME_PATH "error allocating char pointer type for the home path in 'configuration/path.c'."
#define MALLOC_ERROR_MSG_ROOT_PATH "error allocating char pointer type for the root path in 'configuration/path.c'."
#define MALLOC_ERROR_MSG_SCORES_PATH "error allocating char pointer type for the scores path in 'configuration/path.c'."
#define MALLOC_ERROR_MSG_CONFIG_PATH "error allocating char pointer type for the config path in 'configuration/path.c'."
#define MALLOC_ERROR_MSG_KBHIT_BUFF "error allocating char pointer type for the input buffer in 'utility/input.c'."
#define CLEAR_ERROR_MSG "error calling clear function in 'utility/utility.c'."
#define SLEEP_ERROR_MSG "error calling sleep function in 'utility/utility.c'."
#define ERROR_CREATING_DIRECTORY_MSG "Unable to create configuration path in 'configuration/configuration.c'"
#define CREATE_ERROR_MSG_SCORE_TABLE "error while creating score table file in 'score_table/open.c'"
#define FREAD_ERROR_NAMESIZE_MSG "error while reading the size of the name from score table file in 'score/io.c'"
#define FREAD_ERROR_NAME_MSG "error while reading the players name from score table file in 'score/io.c'"
#define FREAD_ERROR_SCORE_MSG "error while reading the players score from score table file in 'score/io.c'"
#define FREAD_ERROR_LEVEL_MSG "error while reading the players end level from score table file in 'score/io.c'"
#define FWRITE_ERROR_NAMESIZE_MSG "error while writing the size of the name from score table file in 'score/io.c'"
#define FWRITE_ERROR_NAME_MSG "error while writing the players name from score table file in 'score/io.c'"
#define FWRITE_ERROR_SCORE_MSG "error while writing the players score from score table file in 'score/io.c'"
#define FWRITE_ERROR_LEVEL_MSG "error while writing the players end level from score table file in 'score/io.c'"

#endif
