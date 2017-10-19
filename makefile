SOURCE_FOLDER=src
TEST_FOLDER=test
BUILD_FOLDER=build
TEMPORAL_FOLDER=tmp
INSTALL_FOLDER=/usr/bin

DEBUG= -g
CFLAG= -Ofast -Wall -std=gnu11 -pedantic -Werror $(DEBUG)

btt2_characters = characters characters_moves characters_attacks
btt2_options = options options_shows
btt2_options_list = options_list
btt2_menus = menus menus_shows menus_options_change menus_execute
btt2_keymaps = keymaps keymaps_exec
btt2_utilities = utilities inputs

btt2_tests = main_test test characters_test options_test \
										options_list_test menus_test keymaps_test

.PHONY: all clean clean-test folders install uninstall reinstall lines test test-run
.IGNORE: clean clean-test

all: clean folders main.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/btt2 $(CFLAG)

test: clean folders test.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/btt2test $(CFLAG)

main.o: btt.o
		#MAIN
		gcc -c $(SOURCE_FOLDER)/main.c -o $(TEMPORAL_FOLDER)/main.o $(CFLAG)

btt.o:
		#CHARACTERS
		for file in $(btt2_characters); do \
		gcc -c $(SOURCE_FOLDER)/characters/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#OPTIONS
		for file in $(btt2_options); do \
		gcc -c $(SOURCE_FOLDER)/options/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#OPTIONS LIST
		for file in $(btt2_options_list); do \
		gcc -c $(SOURCE_FOLDER)/options_list/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#MENUS
		for file in $(btt2_menus); do \
		gcc -c $(SOURCE_FOLDER)/menus/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#KEYMAPS
		for file in $(btt2_keymaps); do \
		gcc -c $(SOURCE_FOLDER)/keymaps/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#UTILITIES
		for file in $(btt2_utilities); do \
		gcc -c $(SOURCE_FOLDER)/utilities/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done

test.o: btt.o
		#TEST CLASES
		for file in $(btt2_tests); do \
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
