#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
        #include <windows.h>
#elif __unix__
        #include <time.h>
        #include <sys/stat.h>
#endif
#include <errno.h>
#include "../include/btt2.h"
#include "include/error.h"
#include "include/utility.h"
#include "include/color.h"


void check_error(void * value, void * error, int error_code, char * error_msg)
{
        if(value == error) {
                fprintf(stderr, RED "\nerror -> %d\nmsg   -> %s\n" RESET,
                        error_code, error_msg);
                exit(error_code);
        }
}


void check_int_error(int value, int error, int error_code, char * error_msg)
{
        if(value == error) {
                fprintf(stderr, RED "\nerror -> %d\nmsg   -> %s\n" RESET,
                        error_code, error_msg);
                exit(error_code);
        }
}

#ifdef _WIN32

void create_directory(char * path)
{
        check_int_error(CreateDirectory(path, NULL), 0,
                        ERROR_CREATING_DIRECTORY, ERROR_CREATING_DIRECTORY_MSG);
}

#elif __unix__

// !!!!! THIS FUNCTION NEEDS TO BE REFACTORED !!!!!

void create_directory(char * path)
{
        if(mkdir(path, 0777) != EEXIST)
                if(mkdir(path, 0777) != EEXIST)
                        fprintf(stderr, "%s\n", "error");
}

#endif


/*
 * This is a generic clear that generate and abstraction
 * no mether if you are in Windows or Unix Systems.
 */

#ifdef _WIN32
void btt_clear()
{
        btt_sleep(25);
        check_int_error(system("cls"), -1, CLEAR_ERROR, CLEAR_ERROR_MSG);
}

#elif __unix__

void btt_clear()
{
        btt_sleep(25);
        check_int_error(system("clear"), -1, CLEAR_ERROR, CLEAR_ERROR_MSG);
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

        check_int_error(nanosleep(&ts, NULL), -1, SLEEP_ERROR, SLEEP_ERROR_MSG);
}
#endif

void go_out()
{
        btt_clear();
        game = false;
}

void go_out_scores()
{
        btt_clear();
        scores = false;
}

void go_out_difficult()
{
        btt_clear();
        difficult = false;
}

void do_nothing()
{
        return;
}
