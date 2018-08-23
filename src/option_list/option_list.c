#include <stdlib.h>
#include <string.h>
#include "include/option_list.h"
#include "include/append.h"
#include "include/select.h"
#include "include/destroy.h"
#include "../option/include/option.h"
#include "../utility/include/utility.h"
#include "../utility/include/output.h"
#include "../utility/include/error.h"
#include "../include/menus.h"
#include "../include/btt2.h"
#include "../difficult/include/difficult_setters.h"

option_list_t *
new_option_list (option_t * opt)
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

option_list_t *
new_main_menu_options_list (void)
{
		option_t * start_option = new_option("START", difficult_menu);
		option_t * scores_option = new_option("SCORES", scores_menu);
		option_t * configuration_option = new_option("CONFIG", config_menu);
		option_t * exit_option = new_option("EXIT", go_out);
		start_option->select(start_option);
		option_list_t * option_list = new_option_list(start_option);
		option_list->append(option_list, scores_option);
		option_list->append(option_list, configuration_option);
		option_list->append(option_list, exit_option);

		return option_list;
}

option_list_t *
new_difficult_options_list (void)
{
		option_t * easy_option = new_option("EASY", set_easy_difficult);
		option_t * normal_option = new_option("NORMAL", set_normal_difficult);
		option_t * hard_option = new_option("HARD", set_hard_difficult);
		option_t * very_hard_option = new_option("VERY HARD", set_very_hard_difficult);
		option_t * hopeless_option = new_option("HOPELESS", set_hopeless_difficult);
		option_t * return_option = new_option("RETURN", go_out_difficult);
		easy_option->select(easy_option);
		option_list_t * option_list = new_option_list(easy_option);
		option_list->append(option_list, normal_option);
		option_list->append(option_list, hard_option);
		option_list->append(option_list, very_hard_option);
		option_list->append(option_list, hopeless_option);
		option_list->append(option_list, return_option);

		return option_list;
}

option_list_t *
new_scores_options_list (void)
{
		option_t * easy_option = new_option("EASY", go_out_scores);
		option_t * normal_option = new_option("NORMAL", go_out_scores);
		option_t * hard_option = new_option("HARD", go_out_scores);
		option_t * very_hard_option = new_option("VERY HARD", go_out_scores);
		option_t * hopeless_option = new_option("HOPELESS", go_out_scores);
		easy_option->select(easy_option);
		option_list_t * option_list = new_option_list(easy_option);
		option_list->append(option_list, normal_option);
		option_list->append(option_list, hard_option);
		option_list->append(option_list, very_hard_option);
		option_list->append(option_list, hopeless_option);

		return option_list;
}

option_list_t *
new_config_options_list (void)
{
		option_t * up_option = new_option("UP", key_menu);
		option_t * down_option = new_option("DOWN", key_menu);
		option_t * left_option = new_option("LEFT", key_menu);
		option_t * right_option = new_option("RIGHT", key_menu);
		option_t * return_option = new_option("RETURN", go_out_config);
		up_option->select(up_option);
		option_list_t * option_list = new_option_list(up_option);
		option_list->append(option_list, down_option);
		option_list->append(option_list, left_option);
		option_list->append(option_list, right_option);
		option_list->append(option_list, return_option);

		return option_list;
}
