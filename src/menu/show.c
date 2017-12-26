#include <stdio.h>
#include "include/menu.h"
#include "../utility/include/utility.h"
#include "../option/include/option.h"
#include "../option_list/include/option_list.h"
#include "../../ascii_art/art.h"
#include "../score_table/include/score_table.h"

int show_main_menu(menu_t * menu)
{
        option_list_t * head = menu->options;

        btt_clear();
        printf(MAIN_ART);
        printf("\n\t\t\t\t  %s\n", menu->title);

        while(head->next != head) {
                (head->option)->show(head->option);
                head = head->next;
        }

        (head->option)->show(head->option);

        return 0;
}

int show_scores(menu_t * menu)
{
        score_table_t * scores;

        btt_clear();
        printf("\n\t\t\t\t  %s %s\n", menu->selected_option->option->text, menu->title);
        scores = new_score_table(menu->selected_option->option->text);
        scores->show(scores);

        return 0;
}
