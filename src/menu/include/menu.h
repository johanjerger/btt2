#ifndef BTT2_MN_H
#define BTT2_MN_H

#include "../../option_list/include/option_list.h"

// Struct that contains the attributes of the menus
// it contains the menus representation, the options
// and the uses functions.
typedef struct _menu
{
        char * title;
        option_list_t * options;
        option_list_t * selected_option;
        void (*show)(struct _menu *);
        void (*next_option)(struct _menu *);
        void (*previous_option)(struct _menu *);
        void (*destroy)(struct _menu *);
} menu_t;

menu_t * new_menu (char *, option_list_t *, void (*show_menu)(menu_t *));

menu_t * new_main_menu (void);

menu_t * new_difficult_menu (void);

menu_t * new_scores_menu (void);

#endif
