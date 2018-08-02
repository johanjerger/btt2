#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "include/error.h"
#include "include/utility.h"
#include "include/input.h"

// The getch function reads a character from the STDIN
// without the need of the enter key, also, for requirement
// purpose, lowercase all the inputs.
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

// The kbhit function reads a character from the STDIN if
// this is filled, this avoid the need of stop the game.
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
		
		char out = getchar();

		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		fcntl(STDIN_FILENO, F_SETFL, oldf);

		return tolower(out);
}
