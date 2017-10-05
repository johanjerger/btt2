#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "includes/utilities.h"
#include "includes/colors.h"


int clear()
{
        if((system("clear")) == -1) {
                fprintf(stderr, RED "Error calling system \"clear\" function\n" RESET);
        }

        return 0;
}


int btt_sleep(int time)
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

char kbhit()
{
        struct termios oldt, newt;
        char ch[20];
        short oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        if(!(scanf("%s", ch))) {
                fprintf(stderr, "error -> %d\n", EIO);
                exit(1);
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if(ch[0] != EOF) {
                return ch[0];
        }

        return 0;
}
