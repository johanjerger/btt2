#include <stdio.h>
#include <string.h>
#include "include/menu.h"
#include "../utility/include/utility.h"
#include "../option/include/option.h"
#include "../option_list/include/option_list.h"
#include "../../ascii_art/art2.h"
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
		//printf(BRED BOLD "\t\t%26s%-20s\n" RESET, menu->title, "");
		option_list_t * head = menu->options;
		while(head->next != menu->options)
		{
				printf("\t\t" BRED "                                              " RESET "\n");
				(head->option)->show(head->option);
				head = head->next;
		}
		printf("\t\t" BRED "                                              " RESET "\n");
		(head->option)->show(head->option);
		printf("\t\t" BRED "                                              " RESET "\n");
}

void
show_scores (menu_t * menu)
{
		print_art();
		char * score_table_name = menu->selected_option->option->text;
		char * menu_name = menu->title;
		int len = strlen(score_table_name) + strlen(menu_name);
		char * word = (char *) malloc(len * sizeof(char) + 5);
		strcpy(word, score_table_name);
		strcat(word, " ");
		strcat(word, menu_name);
		char to_print[] = "                                                               ";
		center_output(to_print, word);
		printf(BRED BLACK "\n\t%s\n" RESET, to_print);
		score_table_t * scores;
		scores = new_score_table(score_table_name);
		scores->show(scores);
}
