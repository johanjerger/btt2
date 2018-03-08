#include <stdio.h>
#include "include/menu.h"
#include "../utility/include/utility.h"
#include "../option/include/option.h"
#include "../option_list/include/option_list.h"
#include "../../ascii_art/art.h"
#include "../score_table/include/score_table.h"

void
print_art (void)
{
		btt_clear();
		printf(MAIN_ART);
}

void
show_standard_menu (menu_t * menu)
{
		print_art();
		printf("\n\t\t\t\t  %s\n", menu->title);
		option_list_t * head = menu->options;
		while(head->next != menu->options)
		{
				(head->option)->show(head->option);
				head = head->next;
		}
		(head->option)->show(head->option);
}

void
show_scores (menu_t * menu)
{
		print_art();
		char * score_table_name = menu->selected_option->option->text;
		printf("\n\t\t\t\t  %s %s\n", score_table_name, menu->title);
		score_table_t * scores;
		scores = new_score_table(score_table_name);
		scores->show(scores);
}
