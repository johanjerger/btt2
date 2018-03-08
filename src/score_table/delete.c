#include <stdio.h>
#include <stdbool.h>
#include "include/score_table.h"

// REFACTOR NEEDED

void
score_table_delete (score_table_t * score_table)
{

		if (remove(score_table->file_name) == 0)
				printf("Deleted successfully");
		else
				printf("Unable to delete the file");
}
