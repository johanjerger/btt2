#ifndef BTT2_UTL_H
#define BTT2_UTL_H

#define BUFFER_SIZE 256

#include "../../menus/includes/menus.h"

  int clear();

  int btt_sleep(int);

  char getch();

  char kbhit();

  int go_out(menu *);

#endif
