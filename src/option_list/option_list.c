#include <stdlib.h>
#include "include/option_list.h"
#include "include/append.h"
#include "include/select.h"
#include "include/destroy.h"
#include "../option/include/option.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"

// This includes are to create the menus
#include "../include/scores_menu.h"

option_list_t * new_option_list(option_t * opt)
{
        option_list_t * new_option_list;

        new_option_list = (option_list_t *) malloc(sizeof(option_list_t));
        check_error(new_option_list, NULL, MALLOC_ERROR,
                    MALLOC_ERROR_MSG_OPTION_LIST);

        new_option_list->option = opt;
        new_option_list->next = new_option_list;
        new_option_list->previous = new_option_list;
        new_option_list->append = option_list_append;
        new_option_list->select_next = option_list_select_next;
        new_option_list->select_previous = option_list_select_previous;
        new_option_list->destroy = option_list_destroy;

        return new_option_list;
}

option_list_t * new_main_menu_options_list()
{
        option_t * start_option = new_option("START", go_out);
        option_t * scores_option = new_option("SCORES", scores_menu);
        option_t * configuration_option = new_option("CONFIG", go_out);
        option_t * exit_option = new_option("EXIT", go_out);

        start_option->select(start_option);

        option_list_t * option_list = new_option_list(start_option);
        option_list->append(option_list, scores_option);
        option_list->append(option_list, configuration_option);
        option_list->append(option_list, exit_option);

        return option_list;
}

option_list_t * new_scores_options_list()
{
        option_t * easy_scores_option = new_option("EASY", go_out);
        option_t * normal_scores_option = new_option("NORMAL", go_out);
        option_t * hard_scores_option = new_option("HARD", go_out);
        option_t * very_hard_scores_option = new_option("VERY HARD", go_out);
        option_t * hopeless_scores_option = new_option("HOPELESS", go_out);

        easy_scores_option->select(easy_scores_option);

        option_list_t * option_list = new_option_list(easy_scores_option);
        option_list->append(option_list, normal_scores_option);
        option_list->append(option_list, hard_scores_option);
        option_list->append(option_list, very_hard_scores_option);
        option_list->append(option_list, hopeless_scores_option);

        return option_list;
}
