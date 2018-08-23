#ifndef BTT2_KM_H
#define BTT2_KM_H

#include "../../menu/include/menu.h"

typedef struct _keymap
{
        char key;
        struct _keymap * next_key;
        void (*action)();
        void (*execute)(menu_t *, struct _keymap *);
        void (*append)(struct _keymap *, char, void (*)());
        void (*destroy)(struct _keymap *);
} keymap_t;

keymap_t * new_keymap(char, void (*)());

keymap_t * new_main_menu_keymap (void);

keymap_t * new_difficult_menu_keymap (void);

keymap_t * new_scores_keymap (void);

keymap_t * new_config_menu_keymap (void);

#endif
