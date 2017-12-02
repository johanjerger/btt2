#ifndef BTT2_CH_H
#define BTT2_CH_H

/*
 *  Struct that contains the attributes of the characters
 *  it contains the character representation, the position
 *  in the matrix and how its moves and attacks.
 */

  typedef struct _character
  {
    char body;
    int pos_x;
    int pos_y;
    int (*move) (struct _character *);
    int (*attack) (struct _character *);
  } character;

  character * drugo (int, int);

  character * pterodactyl (int, int);

#endif
