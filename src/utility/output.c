#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#if defined(__unix__) || defined( __CYGWIN__)
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ioctl.h>
#endif
#include "../include/btt2.h"

char *
center_output (char * word, int output_space)
{
		output_space = (term_columns/(120.0/output_space));
		int to_print_hlen = output_space / 2;
		int len = strlen(word);
		int hlen = floor(len/2);
		char * to_print = (char *) malloc(sizeof(char) * output_space + 1);

		for (int i = 0; i != output_space; i++) to_print[i] = ' ';
		to_print[output_space] = '\0';
		for(int i = to_print_hlen - hlen; i != to_print_hlen + hlen; i++)
		{
				to_print[i] = word[i + hlen - to_print_hlen];
		}
		if ((len % 2) != 0) to_print[to_print_hlen + hlen] = word[len - 1];

		return to_print;
}

char *
left_output (char * word, int output_space)
{
		output_space = (term_columns/(120.0/output_space));
		int len = strlen(word);
		char * to_print = (char *) malloc(sizeof(char) * output_space + 1);

		for (int i = 0; i != output_space; i++) to_print[i] = ' ';
		to_print[output_space] = '\0';
		for(int i = 0; i != len; i++)
		{
				to_print[i] = word[i];
		}

		return to_print;
}

char *
right_output (char * word, int output_space)
{
		output_space = (term_columns/(120.0/output_space));
		int len = strlen(word);
		char * to_print = (char *) malloc(sizeof(char) * output_space + 1);

		for (int i = 0; i != output_space; i++) to_print[i] = ' ';
		to_print[output_space] = '\0';
		for(int i = output_space - len; i != output_space; i++)
		{
				to_print[i] = word[i - (output_space - len)];
		}

		return to_print;
}

void
set_screen (void)
{
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

		term_lines = w.ws_row;
		term_columns = w.ws_col;
}
