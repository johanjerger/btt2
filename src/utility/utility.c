#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/utility.h"
#include "include/color.h"


void check_error(void * value, void * error, int error_code, char * error_msg)
{
  if(value == error) {
    fprintf(stderr, RED "error -> %d\nmsg  -> %s\n" RESET,
            error_code, error_msg);
    exit(error_code);
  }
}

void clear()
{
        btt_sleep(25);
        if((system("clear")) == -1) {
                fprintf(stderr, RED "Error calling system \"clear\" function\n" RESET);
        }
}


void btt_sleep(int time)
{
        struct timespec ts;
        ts.tv_sec = time / 1000;
        ts.tv_nsec = (time % 1000) * 1000000;

        if((nanosleep(&ts, NULL)) == -1) {
                fprintf(stderr, RED "Error calling stdlib \"nanosleep\" function\n" RESET);
        }
}


void go_out()
{
        exit(0);
}
