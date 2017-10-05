SOURCE_FOLDER=src
TEST_FOLDER=test
BUILD_FOLDER=build
BUILD_TEST_FOLDER=build_test
TEMPORAL_FOLDER=tmp
INSTALL_FOLDER=/usr/bin

CFLAG=-O3 -Wall -std=gnu11
# DEBUG=-g


.PHONY: all clean clean-test folders install uninstall reinstall lines test test-run
all: clean folders main.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/btt2 $(CFLAG) $(DEBUG)

main.o:
		#MAIN
		gcc -c $(SOURCE_FOLDER)/main.c -o $(TEMPORAL_FOLDER)/main.o $(CFLAG) $(DEBUG)

		#CHARACTERS
		gcc -c $(SOURCE_FOLDER)/characters/characters_generator.c -o $(TEMPORAL_FOLDER)/characters_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_moves.c -o $(TEMPORAL_FOLDER)/characters_moves.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_attacks.c -o $(TEMPORAL_FOLDER)/characters_attacks.o $(CFLAG) $(DEBUG)

		#OPTIONS
		gcc -c $(SOURCE_FOLDER)/options/options_generator.c -o $(TEMPORAL_FOLDER)/options_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/options/options_shows.c -o $(TEMPORAL_FOLDER)/options_shows.o $(CFLAG) $(DEBUG)

		#OPTIONS LIST
		gcc -c $(SOURCE_FOLDER)/options_list/options_list.c -o $(TEMPORAL_FOLDER)/options_list.o $(CFLAG) $(DEBUG)

		#MENUS
		gcc -c $(SOURCE_FOLDER)/menus/menus_generator.c -o $(TEMPORAL_FOLDER)/menus_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/menus/menus_shows.c -o $(TEMPORAL_FOLDER)/menus_shows.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/menus/menus_options_change.c -o $(TEMPORAL_FOLDER)/menus_options_change.o $(CFLAG) $(DEBUG)

		#KEYMAPS
		gcc -c $(SOURCE_FOLDER)/keymaps/keymaps.c -o $(TEMPORAL_FOLDER)/keymaps.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/keymaps/keymaps_exec.c -o $(TEMPORAL_FOLDER)/keymaps_exec.o $(CFLAG) $(DEBUG)

		#UTILITIES
		gcc -c $(SOURCE_FOLDER)/utilities/utilities.c -o $(TEMPORAL_FOLDER)/utilities.o $(CFLAG) $(DEBUG)

clean:
		-rm -r $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders:
		-mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

install: $(BUILD_FOLDER)/btt2
		cp -p $(BUILD_FOLDER)/btt2 $(INSTALL_FOLDER)

uninstall: $(INSTALL_FOLDER)/btt2
		rm $(INSTALL_FOLDER)/btt2

reinstall: uninstall install

lines:
		@ printf "	.c files               "
		@ find $(SOURCE_FOLDER)/ -name '*.c' | xargs wc -l | grep total
		@ printf "	.h files      	       "
		@ find $(SOURCE_FOLDER)/ -name '*.h' | xargs wc -l | grep total

compile_install: all install

# TEST SECTION

test-run: test
			@ ./$(BUILD_TEST_FOLDER)/btt2test

test: clean-test folders-test test.o $(TEMPORAL_FOLDER) $(BUILD_TEST_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_TEST_FOLDER)/btt2test $(CFLAG) $(DEBUG)

test.o:

		#TEST CLASES
	  gcc -c $(TEST_FOLDER)/main_test.c -o $(TEMPORAL_FOLDER)/main_test.o $(CFLAG) $(DEBUG)
		gcc -c $(TEST_FOLDER)/test.c -o $(TEMPORAL_FOLDER)/test.o $(CFLAG) $(DEBUG)

		#CHARACTERS TEST
		gcc -c $(TEST_FOLDER)/characters_test.c -o $(TEMPORAL_FOLDER)/characters_test.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_generator.c -o $(TEMPORAL_FOLDER)/characters_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_moves.c -o $(TEMPORAL_FOLDER)/characters_moves.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_attacks.c -o $(TEMPORAL_FOLDER)/characters_attacks.o $(CFLAG) $(DEBUG)

		#OPTIONS TEST
		gcc -c $(TEST_FOLDER)/options_test.c -o $(TEMPORAL_FOLDER)/options_test.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/options/options_generator.c -o $(TEMPORAL_FOLDER)/options_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/options/options_shows.c -o $(TEMPORAL_FOLDER)/options_shows.o $(CFLAG) $(DEBUG)

		#OPTIONS LIST TEST
		gcc -c $(TEST_FOLDER)/options_list_test.c -o $(TEMPORAL_FOLDER)/options_list_test.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/options_list/options_list.c -o $(TEMPORAL_FOLDER)/options_list.o $(CFLAG) $(DEBUG)

		#MENUS TEST
		gcc -c $(TEST_FOLDER)/menus_test.c -o $(TEMPORAL_FOLDER)/menus_test.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/menus/menus_generator.c -o $(TEMPORAL_FOLDER)/menus_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/menus/menus_shows.c -o $(TEMPORAL_FOLDER)/menus_shows.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/menus/menus_options_change.c -o $(TEMPORAL_FOLDER)/menus_options_change.o $(CFLAG) $(DEBUG)

		#KEYMAPS
		gcc -c $(TEST_FOLDER)/keymaps_test.c -o $(TEMPORAL_FOLDER)/keymaps_test.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/keymaps/keymaps.c -o $(TEMPORAL_FOLDER)/keymaps.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/keymaps/keymaps_exec.c -o $(TEMPORAL_FOLDER)/keymaps_exec.o $(CFLAG) $(DEBUG)

		#UTILITIES
		gcc -c $(SOURCE_FOLDER)/utilities/utilities.c -o $(TEMPORAL_FOLDER)/utilities.o $(CFLAG) $(DEBUG)

clean-test:
	  -rm -r $(TEMPORAL_FOLDER) $(BUILD_TEST_FOLDER)

folders-test:
		-mkdir $(TEMPORAL_FOLDER) $(BUILD_TEST_FOLDER)
