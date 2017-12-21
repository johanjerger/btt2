#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifdef _WIN32
        #include <conio.h>
#elif __unix__
        #include <termios.h>
        #include <unistd.h>
        #include <errno.h>
        #include <fcntl.h>
#endif
#include "include/error.h"
#include "include/utility.h"
#include "include/input.h"

/*
 * This is a generic getch that generate and abstraction
 * no mether if you are in Windows or Unix Systems.
 */

#ifdef _WIN32
char btt_getch(void)
{
        return _getch();
}

#elif __unix__

char btt_getch(void)
{
        struct termios oldattr, newattr;
        short ch;
        tcgetattr(1, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(1, TCSANOW, &newattr);
        ch = getchar();
        tcsetattr(1, TCSANOW, &oldattr);
        return tolower(ch);
}
#endif


/*
 * This is a generic kbhit that generate and abstraction
 * no mether if you are in Windows or Unix Systems.
 */

#ifdef _WIN32
char btt_kbhit()
{
        return _kbhit();
}

#elif __unix__

char btt_kbhit()
{
        struct termios oldt, newt;
        char out;
        char * ch = (char *) malloc(KBHIT_BUFFER);
        short oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        if(!(fscanf(stdin,"%s", ch))) {
                fprintf(stderr, "error -> %d\n", EIO);
                exit(1);
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        out = ch[0];

        free(ch);

        return tolower(out);
}
#endif
