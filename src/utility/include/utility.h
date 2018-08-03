#ifndef BTT2_UTL_H
#define BTT2_UTL_H

void check_error(void *, void *, int, char *);
void check_int_error(int, int, int, char *);
void create_directory(char *);
void btt_clear (void);
void btt_sleep(int);
void go_out (void);
void go_out_scores (void);
void go_out_difficult (void);
void go_out_config (void);
void do_nothing (void);
char * center_output(char *, int);
void set_screen (void);

#endif
