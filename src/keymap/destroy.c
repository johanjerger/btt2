#include <stdio.h>
#include <stdlib.h>
#include "include/keymap.h"

void
keymap_destroy (keymap_t * keymap)
{
		keymap_t * head = keymap;
    head = head->next_key;

		while (head->next_key != head)
		{
        keymap_t * aux_head = head->next_key;
        free(head);
        head = aux_head;
		}

    free(head);
		free(keymap);
}
