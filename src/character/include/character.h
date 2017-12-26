#ifndef BTT2_CH_H
#define BTT2_CH_H

/*
 *  Struct that contains the attributes of the characters
 *  it contains the character representation, the position
 *  in the matrix and how its moves and attacks.
 */

 #include <stdint.h>

  typedef struct _character
  {
    uint8_t body;
    uint16_t pos_x;
    uint16_t pos_y;
    int (*move) (struct _character *);
    int (*attack) (struct _character *);
  } character_t;

  character_t * new_drugo (uint16_t, uint16_t);

  character_t * new_ptero (uint16_t, uint16_t);

#endif
