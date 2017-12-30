#include <stdio.h>
#include <stdlib.h>
#include "include/keymap.h"
#include "include/execute.h"
#include "include/append.h"
#include "../menu/include/menu.h"
#include "../menu/include/change_option.h"
#include "../menu/include/execute.h"
#include "../utility/include/utility.h"
#include "../utility/include/error.h"


keymap_t * new_keymap(char key, void (*action)())
{
        keymap_t * new_keymap;

        new_keymap = (keymap_t *) malloc(sizeof(keymap_t));
        check_error(new_keymap, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_KEYMAP);

        new_keymap->key = key;
        new_keymap->action = action;
        new_keymap->execute = execute_keymap_action;
        new_keymap->next_key = new_keymap;
        new_keymap->append = keymap_append;

        return new_keymap;
}

keymap_t * new_main_menu_keymap()
{
        keymap_t * keymap = new_keymap('w', select_previous_option);
        keymap->append(keymap, 's', select_next_option);
        keymap->append(keymap, 'k', execute_menu);
        keymap->append(keymap, (char) 777, do_nothing);

        return keymap;
}

keymap_t * new_difficult_menu_keymap()
{

        keymap_t * keymap = new_keymap('w', select_previous_option);
        keymap->append(keymap, 's', select_next_option);
        keymap->append(keymap, 'k', execute_menu);
        keymap->append(keymap, (char) 777, do_nothing);

        return keymap;
}

keymap_t * new_scores_keymap()
{

        keymap_t * keymap = new_keymap('a', select_previous_option);
        keymap->append(keymap, 'd', select_next_option);
        keymap->append(keymap, 'k', execute_menu);
        keymap->append(keymap, (char) 777, do_nothing);

        return keymap;
}
