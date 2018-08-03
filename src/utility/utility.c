#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ioctl.h>
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

void
create_directory (char * path)
{
		if(mkdir(path, 740) == -1)
		{
				if(errno != EEXIST)
				{
						fprintf(stderr, "%s %s\n", "error in mkdir for path: ", path);
						exit(errno);
				}
		}
}

// This is a generic clear that generate and abstraction
// no mether if you are in Windows or Unix Systems.
void
btt_clear (void)
{
		btt_sleep(50);
		check_int_error(system("clear"), -1, CLEAR_ERROR, CLEAR_ERROR_MSG);
}

// This is a generic sleep that generate and abstraction
// no mether if you are in Windows or Unix Systems.
void
btt_sleep (int time)
{
		struct timespec ts;
		ts.tv_sec = time / 1000;
		ts.tv_nsec = (time % 1000) * 1000000;

		check_int_error(nanosleep(&ts, NULL), -1, SLEEP_ERROR, SLEEP_ERROR_MSG);
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
go_out_config (void)
{
		btt_clear();
		config_loop = false;
}

void
do_nothing (void)
{
		return;
}
