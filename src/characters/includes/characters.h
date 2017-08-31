#ifndef BTT2_CH_H
#define BTT2_CH_H

/*
 *  Struct that contains the attributes of the characters
 *  it contains the character representation, the position
 *  in the matrix and how its moves and attacks.
 */

typedef struct
{
  char body;
  int posX;
  int posY;
  int(*move)(character);
  int(*attack)(character);
} character;

#endif
