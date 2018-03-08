#include <stdio.h>
#include "include/option.h"
#include "include/show.h"
#include "../utility/include/color.h"

// The select and unselect functions, they are only to "bautify" a little
// bit more the code of the program. If they don't exist, every time you
// want to select or unselect a option_t type in the code you need to include
// the option/select.h file, and thats a lot of useless code.
void
select_option (option_t * option)
{
		option->show = show_selected_option;
}

void
unselect_option (option_t * option)
{
		option->show = show_unselected_option;
}
