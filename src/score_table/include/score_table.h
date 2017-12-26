#ifndef BTT2_SCT_H
#define BTT2_SCT_H

#include <stdio.h>
#include <stdlib.h>
#include "../../score/include/score.h"

#define SCORE_TABLE_PATH "C:\\Users\\juancruz.ocampos\\Documents\\juan\\bttconfig\\"
#define SCORE_TABLE_SIZE 10

  typedef struct _score_table
  {
    char * file_name;
    char * title;
    void (*add) (struct _score_table *, score_t *);
    void (*show) (struct _score_table *);
    FILE * (*open) (struct _score_table *);
  } score_table_t;

  score_table_t * new_score_table(char *, char *);

#endif
