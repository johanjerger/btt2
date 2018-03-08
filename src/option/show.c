#include <stdio.h>
#include "../utility/include/color.h"
#include "include/option.h"

// The show function is a special one in the option_t type, it defines how
// the (option_t)->text is show in the terminal screen.
void
show_unselected_option (option_t * opt)
{
		printf("\t\t\t\t    %s\n", opt->text);
}

void
show_selected_option (option_t * opt)
{
		printf(YELLOW "\t\t\t\t    %s\n" RESET, opt->text);
}
