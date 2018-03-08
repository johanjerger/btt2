#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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

void
check_error (void * value, void * error, int error_code, char * error_msg)
{
		if(value == error)
		{
				fprintf(stderr, RED "\nerror -> %d\nmsg   -> %s\n" RESET,
				        error_code, error_msg);
				exit(error_code);
		}
}

void
check_int_error (int value, int error, int error_code, char * error_msg)
{
		if(value == error)
		{
				fprintf(stderr, RED "\nerror -> %d\nmsg   -> %s\n" RESET,
				        error_code, error_msg);
				exit(error_code);
		}
}

#ifdef _WIN32

void
create_directory (char * path)
{
		check_int_error(CreateDirectory(path, NULL), 0,
		                ERROR_CREATING_DIRECTORY, ERROR_CREATING_DIRECTORY_MSG);
}

#elif __unix__

// !!!!! THIS FUNCTION NEEDS TO BE REFACTORED !!!!!
void
create_directory (char * path)
{
		if(mkdir(path, 440) == -1)
				if(errno != EEXIST)
						fprintf(stderr, "%s %s\n", "error in mkdir for path: ", path);
}

#endif

// This is a generic clear that generate and abstraction
// no mether if you are in Windows or Unix Systems.
#ifdef _WIN32

void
btt_clear (void)
{
		btt_sleep(25);
		check_int_error(system("cls"), -1, CLEAR_ERROR, CLEAR_ERROR_MSG);
}

#elif __unix__

void
btt_clear (void)
{
		btt_sleep(25);
		check_int_error(system("clear"), -1, CLEAR_ERROR, CLEAR_ERROR_MSG);
}

#endif

// This is a generic sleep that generate and abstraction
// no mether if you are in Windows or Unix Systems.
#ifdef _WIN32

void
btt_sleep (int time)
{
		Sleep(time);
}

#elif __unix__

void
btt_sleep (int time)
{
		struct timespec ts;
		ts.tv_sec = time / 1000;
		ts.tv_nsec = (time % 1000) * 1000000;

		check_int_error(nanosleep(&ts, NULL), -1, SLEEP_ERROR, SLEEP_ERROR_MSG);
}

#endif

void
center_output (char * to_print, char * word)
{
		int to_print_hlen = strlen(to_print) / 2;
		int len = strlen(word);
		int hlen = floor(len/2);
		for(int i = to_print_hlen - hlen; i < to_print_hlen + hlen; i++)
		{
				to_print[i] = word[i + hlen - to_print_hlen];
		}
		if ((len % 2) != 0) to_print[to_print_hlen + hlen] = word[len - 1];
}

void
go_out (void)
{
		btt_clear();
		main_loop = false;
}

void
go_out_scores (void)
{
		btt_clear();
		scores_loop = false;
}

void
go_out_difficult (void)
{
		btt_clear();
		difficult_loop = false;
}

void
do_nothing (void)
{
		return;
}
