#ifndef BTT2_UTL_H
#define BTT2_UTL_H

#include "../../option/include/option.h"

void check_error(void *, void *, int, char *);
void check_int_error(int, int, int, char *);
void create_directory(char *);
void btt_clear (void);
void btt_sleep(int);
void go_out (option_t *, ...);
void go_out_scores (option_t *, ...);
void go_out_difficult (option_t *, ...);
void go_out_config (option_t *, ...);
void do_nothing (void);
char * center_output(char *, int);
void set_screen (void);

#endif
