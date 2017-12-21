#ifndef BTT2_SCT_H
#define BTT2_SCT_H

#include "../../score/include/score.h"

  typedef struct _score_table
  {
    char * file_name;
    char * title;
    void (*add) (score_t *);
    void (*show) (struct _score_table *);
    void (*open) (FILE *);
    void (*close) (FILE *);
  } score_table_t;

  score_table_t * new_score_table(char * name);

#endif
