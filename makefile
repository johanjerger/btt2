SOURCE_FOLDER=src
TEST_FOLDER=test
BUILD_FOLDER=build
TEMPORAL_FOLDER=tmp
INSTALL_FOLDER=/usr/bin

DEBUG= -g
CFLAG= -Ofast -Wall -std=gnu11 -pedantic -Werror $(DEBUG)

btt2_character = character character_move character_attack
btt2_option = option option_show
btt2_option_list = option_list
btt2_menu = menu menu_show menu_option_change menu_execute
btt2_keymap = keymap keymap_exec
btt2_utility = utility input

btt2_test = main_test test character_test option_test \
										option_list_test menu_test keymap_test

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
		for file in $(btt2_character); do \
		gcc -c $(SOURCE_FOLDER)/character/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#OPTIONS
		for file in $(btt2_option); do \
		gcc -c $(SOURCE_FOLDER)/option/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#OPTIONS LIST
		for file in $(btt2_option_list); do \
		gcc -c $(SOURCE_FOLDER)/option_list/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#MENUS
		for file in $(btt2_menu); do \
		gcc -c $(SOURCE_FOLDER)/menu/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#KEYMAPS
		for file in $(btt2_keymap); do \
		gcc -c $(SOURCE_FOLDER)/keymap/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done
		#UTILITIES
		for file in $(btt2_utility); do \
		gcc -c $(SOURCE_FOLDER)/utility/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG); \
done

test.o: btt.o
		#TEST CLASES
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
