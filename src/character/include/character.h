#ifndef BTT2_CH_H
#define BTT2_CH_H

#include <stdint.h>

// Struct that contains the attributes of the characters
// it contains the character representation, the position
// in the matrix and how its moves and attacks.
typedef struct _character
{
        int body;
        int pos_x;
        int pos_y;
        void (*move)(struct _character *);
        void (*attack)(struct _character *);
} character_t;

character_t * new_drugo (int, int);

character_t * new_ptero (int, int);

#endif
