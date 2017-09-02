#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "includes/colors.h"


int clear()
{
        if((system("clear")) == -1) {
                fprintf(stderr, RED "Error calling system \"clear\" function\n" RESET);
        }

        return 0;
}


int sleep(int time)
{
        /*
           timespec struct is use for
           every "sleep" time during
           the game.
         */

        struct timespec ts;
        ts.tv_sec = time / 1000;
        ts.tv_nsec = (time % 1000) * 1000000;

        if((nanosleep(&ts, NULL)) == -1) {
                fprintf(stderr, RED "Error calling stdlib \"nanosleep\" function\n" RESET);
        }

        return 0;
}