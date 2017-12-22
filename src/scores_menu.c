#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"
#include "score_table/include/score_table.h"

void scores_menu()
{
        menu_t * scores_menu = new_scores_menu();
        keymap_t * scores_keymap = new_scores_keymap();
        scores_menu->show(scores_menu);

        while(true) {
                char key;
                key = btt_getch();

                scores_keymap->exec(scores_menu, scores_keymap, key);
                scores_menu->show(scores_menu);
        }

        scores_menu->destroy(scores_menu);
        free(scores_menu);
        free(scores_keymap);
}
