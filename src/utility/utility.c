#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/error.h"
#include "include/utility.h"
#include "include/color.h"


void check_error(void * value, void * error, int error_code, char * error_msg)
{
        if(value == error) {
                fprintf(stderr, RED "\nerror -> %d\nmsg  -> %s\n" RESET,
                        error_code, error_msg);
                exit(error_code);
        }
}

void clear()
{
        btt_sleep(25);
        if((system("clear")) == -1) {
                fprintf(stderr, RED "\nerror -> %d\nmsg  -> %s\n" RESET,
                        CLEAR_ERROR, CLEAR_ERROR_MSG);
                exit(CLEAR_ERROR);
        }
}


void btt_sleep(int time)
{
        struct timespec ts;
        ts.tv_sec = time / 1000;
        ts.tv_nsec = (time % 1000) * 1000000;

        if((nanosleep(&ts, NULL)) == -1) {
                fprintf(stderr, RED "\nerror -> %d\nmsg  -> %s\n" RESET,
                        SLEEP_ERROR, SLEEP_ERROR_MSG);
                exit(SLEEP_ERROR);
        }
}


void go_out()
{
        clear();
        exit(0);
}
