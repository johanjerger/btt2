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

// This is a generic getch that generate and abstraction
// no mether if you are in Windows or Unix Systems.
#ifdef _WIN32

char
btt_getch (void)
{
		return tolower(_getch());
}

#elif __unix__

char
btt_getch (void)
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

// This is a generic kbhit that generate and abstraction
// no mether if you are in Windows or Unix Systems.
#ifdef _WIN32
char
btt_kbhit (void)
{
		return tolower(_kbhit());
}

#elif __unix__

char
btt_kbhit (void)
{
		struct termios oldt, newt;
		short oldf;

		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
		oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
		fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

		char * input_buffer = (char *) malloc(KBHIT_BUFFER * sizeof(char));
		check_error(input_buffer, NULL, MALLOC_ERROR, MALLOC_ERROR_MSG_KBHIT_BUFF);
		check_int_error(fscanf(stdin,"%s", input_buffer), 0, EIO, SCANF_ERROR_MSG);

		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		fcntl(STDIN_FILENO, F_SETFL, oldf);

		char out = input_buffer[0];
		free(input_buffer);

		return tolower(out);
}

#endif
