#include <stdio.h>
#include <stdbool.h>
#include "../utility/include/color.h"
#include "../utility/include/utility.h"
#include "include/option.h"

// The show function is a special one in the option_t type, it defines how
// the (option_t)->text is show in the terminal screen.
void
show_unselected_option (option_t * opt)
{
		printf(BRED BLACK "\t\t%s\n" RESET, center_output(opt->text, 46));
}

void
show_selected_option (option_t * opt)
{
		printf(BRED BOLD "\t%s\n" RESET, center_output(opt->text, 62));
}
