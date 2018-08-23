#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utility/include/color.h"
#include "../utility/include/output.h"
#include "include/option.h"
#include "../include/btt2.h"

// The show function is a special one in the option_t type, it defines how
// the (option_t)->text is show in the terminal screen.
void
show_unselected_option (option_t * opt)
{
		char * black_space = center_output("", 16);
		char * text_area = center_output(opt->text, 46);
		printf(BBLACK BLACK "%s" BRED "%s\n" RESET,
		       black_space,
		       text_area);
	  free(black_space);
		free(text_area);
}

void
show_selected_option (option_t * opt)
{
		char * black_space = center_output("", 8);
		char * text_area = center_output(opt->text, 62);
		printf(BBLACK BLACK "%s" BRED WHITE BOLD "%s\n" RESET,
		       black_space,
		       text_area);
		free(black_space);
 		free(text_area);
}
