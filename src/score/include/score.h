#ifndef BTT2_SC_H
#define BTT2_SC_H

#include <stdint.h>
#include <stdbool.h>

  typedef struct _score
  {
    char * player_name;
    uint32_t points;
    int level;
    bool (*compare) (struct _score *, struct _score *);
    void (*show) (struct _score *);
  } score_t;

  score_t * new_score(char *, uint32_t, int);

#endif
