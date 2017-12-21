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

void btt_clear()
{
        btt_sleep(25);
#ifdef _WIN32
        if((system("cls")) == -1) {
#elif __unix__
        if((system("clear")) == -1) {
#endif
                fprintf(stderr, RED "\nerror -> %d\nmsg  -> %s\n" RESET,
                        CLEAR_ERROR, CLEAR_ERROR_MSG);
                exit(CLEAR_ERROR);
        }
}


void btt_sleep(int time)
{
  #ifdef _WIN32
        Sleep(time);
  #elif __unix__
        struct timespec ts;
        ts.tv_sec = time / 1000;
        ts.tv_nsec = (time % 1000) * 1000000;

        if((nanosleep(&ts, NULL)) == -1) {
                fprintf(stderr, RED "\nerror -> %d\nmsg  -> %s\n" RESET,
                        SLEEP_ERROR, SLEEP_ERROR_MSG);
                exit(SLEEP_ERROR);
        }
  #endif
}


void go_out()
{
        btt_clear();
        exit(0);
}
