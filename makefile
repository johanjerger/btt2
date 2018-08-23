SOURCE_FOLDER=src
TEST_FOLDER=test
BUILD_FOLDER=build
TEMPORAL_FOLDER=tmp
INSTALL_FOLDER=/usr/bin

DEBUG= -g
CFLAG= -Ofast -Wall -std=gnu11 -pedantic -Werror $(DEBUG)

btt2_character = move attack
btt2_keymap = execute append destroy
btt2_menu = show change_option execute destroy
btt2_difficult = difficult_setters
btt2_option = show select destroy
btt2_option_list = append select destroy
btt2_score = show io compare
btt2_score_table = add show open
btt2_configuration = configuration keys path get_home key_setters free_environment_variables
btt2_utility = utility input output

btt2_test = main_test test character_test option_test \
										option_list_test menu_test keymap_test

.PHONY: all clean clean-test folders install uninstall reinstall lines test test-run
.IGNORE: clean clean-test

all: clean folders main.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/btt2 $(CFLAG)

test: clean folders test.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/btt2test $(CFLAG)

main.o: btt.o
		# MAIN
		gcc -c $(SOURCE_FOLDER)/main.c -o $(TEMPORAL_FOLDER)/main.o $(CFLAG)

btt.o:
		# CHARACTERS
		gcc -c $(SOURCE_FOLDER)/character/character.c -o $(TEMPORAL_FOLDER)/character.o $(CFLAG)
		for file in $(btt2_character); do \
		gcc -c $(SOURCE_FOLDER)/character/$$file.c -o $(TEMPORAL_FOLDER)/character_$$file.o $(CFLAG); \
done
		# OPTIONS
		gcc -c $(SOURCE_FOLDER)/option/option.c -o $(TEMPORAL_FOLDER)/option.o $(CFLAG)
		for file in $(btt2_option); do \
		gcc -c $(SOURCE_FOLDER)/option/$$file.c -o $(TEMPORAL_FOLDER)/option_$$file.o $(CFLAG); \
done
		# OPTIONS LIST
		gcc -c $(SOURCE_FOLDER)/option_list/option_list.c -o $(TEMPORAL_FOLDER)/option_list.o $(CFLAG)
		for file in $(btt2_option_list); do \
		gcc -c $(SOURCE_FOLDER)/option_list/$$file.c -o $(TEMPORAL_FOLDER)/option_list_$$file.o $(CFLAG); \
done
		# MENUS
		gcc -c $(SOURCE_FOLDER)/menu/menu.c -o $(TEMPORAL_FOLDER)/menu.o $(CFLAG)
		for file in $(btt2_menu); do \
		gcc -c $(SOURCE_FOLDER)/menu/$$file.c -o $(TEMPORAL_FOLDER)/menu_$$file.o $(CFLAG); \
done
		# KEYMAPS
		gcc -c $(SOURCE_FOLDER)/keymap/keymap.c -o $(TEMPORAL_FOLDER)/keymap.o $(CFLAG)
		for file in $(btt2_keymap); do \
		gcc -c $(SOURCE_FOLDER)/keymap/$$file.c -o $(TEMPORAL_FOLDER)/keymap_$$file.o $(CFLAG); \
done
		# SCORE
		gcc -c $(SOURCE_FOLDER)/score/score.c -o $(TEMPORAL_FOLDER)/score.o $(CFLAG)
		for file in $(btt2_score); do \
		gcc -c $(SOURCE_FOLDER)/score/$$file.c -o $(TEMPORAL_FOLDER)/score_$$file.o $(CFLAG); \
done
		# SCORE TABLE
		gcc -c $(SOURCE_FOLDER)/score_table/score_table.c -o $(TEMPORAL_FOLDER)/score_table.o $(CFLAG)
		for file in $(btt2_score_table); do \
		gcc -c $(SOURCE_FOLDER)/score_table/$$file.c -o $(TEMPORAL_FOLDER)/score_table_$$file.o $(CFLAG); \
done
		# UTILITIES
		for file in $(btt2_utility); do \
		gcc -c $(SOURCE_FOLDER)/utility/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		# CONFIGURATION
		for file in $(btt2_configuration); do \
		gcc -c $(SOURCE_FOLDER)/configuration/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		# DIFFICULT
		for file in $(btt2_difficult); do \
		gcc -c $(SOURCE_FOLDER)/difficult/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		# MENUES
		gcc -c $(SOURCE_FOLDER)/difficult_menu.c -o $(TEMPORAL_FOLDER)/difficult_menu.o $(CFLAG)
		gcc -c $(SOURCE_FOLDER)/scores_menu.c -o $(TEMPORAL_FOLDER)/scores_menu.o $(CFLAG)
		gcc -c $(SOURCE_FOLDER)/config_menu.c -o $(TEMPORAL_FOLDER)/config_menu.o $(CFLAG)
		gcc -c $(SOURCE_FOLDER)/key_menu.c -o $(TEMPORAL_FOLDER)/key_menu.o $(CFLAG)
		gcc -c $(SOURCE_FOLDER)/game.c -o $(TEMPORAL_FOLDER)/game.o $(CFLAG)

test.o: btt.o
		# TEST CLASES
		for file in $(btt2_test); do \
		gcc -c $(TEST_FOLDER)/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done

install: $(BUILD_FOLDER)/btt2 ; cp -p $(BUILD_FOLDER)/btt2 $(INSTALL_FOLDER)

uninstall: $(INSTALL_FOLDER)/btt2 ; rm $(INSTALL_FOLDER)/btt2

reinstall: uninstall install

clean: ; -rm -r $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders: ; -mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

lines:
		@ printf "	.c files              "
		@ find $(SOURCE_FOLDER)/ -name '*.c' | xargs wc -l | grep total
		@ printf "	.h files      	       "
		@ find $(SOURCE_FOLDER)/ -name '*.h' | xargs wc -l | grep total
		@ printf "	.c test files          "
		@ find $(TEST_FOLDER)/ -name '*.c' | xargs wc -l | grep total
		@ printf "	.h test files 	        "
		@ find $(TEST_FOLDER)/ -name '*.h' | xargs wc -l | grep total

compile_install: all install

# TEST SECTION

test-run: test
			@ ./$(BUILD_FOLDER)/btt2test
