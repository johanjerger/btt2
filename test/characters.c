#include<stdio.h>
#include<stdlib.h>
#include "../src/characters/includes/characters.h"
#include "../src/characters/includes/characters_generator.h"

int main()
{
  character p = drugo(2,5);

  printf("%d %d %d\n", p.body, p.posX, p.posY);
  printf("%d %d\n", p.move(&p), p.attack(&p));
  printf("%d %d\n", p.posX, p.posY);
  
  return 0;
}
