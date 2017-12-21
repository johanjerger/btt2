#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
        #include <windows.h>
#elif __unix__
        #include <time.h>
#endif
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


/*
 * This is a generic clear that generate and abstraction
 * no mether if you are in Windows or Unix Systems.
 */

#ifdef _WIN32
void btt_clear()
{
        btt_sleep(25);
        if((system("cls")) == -1) {
                fprintf(stderr, RED "\nerror -> %d\nmsg  -> %s\n" RESET,
                        CLEAR_ERROR, CLEAR_ERROR_MSG);
                exit(CLEAR_ERROR);
        }
}

#elif __unix__

void btt_clear()
{
        btt_sleep(25);
        if((system("clear")) == -1) {
                fprintf(stderr, RED "\nerror -> %d\nmsg  -> %s\n" RESET,
                        CLEAR_ERROR, CLEAR_ERROR_MSG);
                exit(CLEAR_ERROR);
        }
}

#endif


/*
 * This is a generic sleep that generate and abstraction
 * no mether if you are in Windows or Unix Systems.
 */

#ifdef _WIN32
void btt_sleep(int time)
{
        Sleep(time);
}

#elif __unix__

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
#endif


void go_out()
{
        btt_clear();
        exit(0);
}
