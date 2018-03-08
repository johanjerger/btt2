#ifndef BTT2_KM_H
#define BTT2_KM_H

#include "../../menu/include/menu.h"

typedef struct _keymap
{
        char key;
        struct _keymap * next_key;
        void (*action)();
        void (*execute)(menu_t *, struct _keymap *, char);
        void (*append)(struct _keymap *, char, void (*)());
} keymap_t;

keymap_t * new_keymap(char, void (*)());

keymap_t * new_main_menu_keymap();

keymap_t * new_difficult_menu_keymap();

keymap_t * new_scores_keymap();

#endif
