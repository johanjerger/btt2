#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/score.h"

score_t *
score_read (FILE * score_table_file)
{
		int size_of_name, points, level;
		char * player_name;

		fread(&size_of_name, sizeof(int), 1, score_table_file);
		player_name = (char *) malloc(sizeof(char) * size_of_name + 5);
		fread(player_name, sizeof(char), size_of_name + 1, score_table_file);
		fread(&points, sizeof(int), 1, score_table_file);
		fread(&level, sizeof(int), 1, score_table_file);

		return new_score(player_name, points, level);
}


void
score_write (FILE * score_table_file, score_t * score)
{
		int size_of_name = strlen(score->player_name);

		fwrite(&size_of_name, sizeof(int), 1, score_table_file);
		fwrite(score->player_name, sizeof(char), size_of_name + 1, score_table_file);
		fwrite(&(score->points), sizeof(int), 1, score_table_file);
		fwrite(&(score->level), sizeof(int), 1, score_table_file);
}
