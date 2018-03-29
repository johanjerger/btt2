#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/score.h"
#include "../utility/include/error.h"
#include "../utility/include/utility.h"

score_t *
score_read (FILE * score_table_file)
{
		size_t int_size = sizeof(int);
		size_t char_size = sizeof(char);
		int result;
	  int size_of_name, points, level;
		char * player_name;

		// Getting the lenght of the name the player logged for his score.
		result = fread(&size_of_name, int_size, 1, score_table_file);
		check_int_error(result, int_size, FREAD_ERROR, FREAD_ERROR_NAMESIZE_MSG);

		// Getting the name the player logged for his score.
		int to_alloc = char_size * size_of_name + 5;
		player_name = (char *) malloc(to_alloc);
		result = fread(player_name, char_size, size_of_name + 1, score_table_file);
		check_int_error(result, size_of_name+1, FREAD_ERROR, FREAD_ERROR_NAME_MSG);

		// Getting the score of the player.
		result = fread(&points, int_size, 1, score_table_file);
		check_int_error(result, int_size, FREAD_ERROR, FREAD_ERROR_SCORE_MSG);

		// Getting the level when the player end his play.
		result = fread(&level, int_size, 1, score_table_file);
		check_int_error(result, int_size, FREAD_ERROR, FREAD_ERROR_LEVEL_MSG);

		return new_score(player_name, points, level);
}

// TODO also check the fwrite function errors
void
score_write (FILE * score_table_file, score_t * score)
{
		int size_of_name = strlen(score->player_name);

		fwrite(&size_of_name, sizeof(int), 1, score_table_file);
		fwrite(score->player_name, sizeof(char), size_of_name + 1, score_table_file);
		fwrite(&(score->points), sizeof(int), 1, score_table_file);
		fwrite(&(score->level), sizeof(int), 1, score_table_file);
}
