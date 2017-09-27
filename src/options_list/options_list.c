#include <stdlib.h>
#include "includes/options_list.h"

options_list * new_options_list(option ** options, int size)
{
        size--;
        options_list * new_options_list[size];

        for(int i = 0; i <= size; i++) {
                new_options_list[i] = malloc(sizeof(options_list));
        }

        new_options_list[0]->option = options[0];
        new_options_list[0]->next_option = new_options_list[1];
        new_options_list[0]->previous_option = new_options_list[size];

        for(int i = 1; i < size; i++) {
                new_options_list[i]->option = options[i];
                new_options_list[i]->next_option = new_options_list[i+1];
                new_options_list[i]->previous_option = new_options_list[i-1];
        }

        new_options_list[size]->option = options[size];
        new_options_list[size]->next_option = new_options_list[0];
        new_options_list[size]->previous_option = new_options_list[size - 1];

        return new_options_list[0];
}
