#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/btt2.h"
#include "menu/include/menu.h"
#include "keymap/include/keymap.h"
#include "utility/include/input.h"
#include "score_table/include/score_table.h"

void scores_menu()
{
        menu_t * scores_menu = new_scores_menu();
        keymap_t * scores_keymap = new_scores_keymap();

        scores = true;
        while(scores) {
                scores_menu->show(scores_menu);
                char key;
                key = btt_getch();
                scores_keymap->execute(scores_menu, scores_keymap, key);
        }
}
