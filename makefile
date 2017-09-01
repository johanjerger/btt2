SOURCE_FOLDER=src
TEST_FOLDER=test
BUILD_FOLDER=build
BUILD_TEST_FOLDER=build_test
TEMPORAL_FOLDER=tmp
INSTALL_FOLDER=/usr/bin

CFLAG=-O3 -Wall -std=c11 
# DEBUG=-g


.PHONY: all clean clean_test folders install uninstall reinstall lines test
all: clean folders main.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/btt2 $(CFLAG) $(DEBUG)

main.o:
		gcc -c $(SOURCE_FOLDER)/main.c -o $(TEMPORAL_FOLDER)/main.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_generator.c -o $(TEMPORAL_FOLDER)/characters_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_moves.c -o $(TEMPORAL_FOLDER)/characters_moves.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_attacks.c -o $(TEMPORAL_FOLDER)/characters_attacks.o $(CFLAG) $(DEBUG)

clean:
		-rm -r $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders:
		-mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders-test:
		-mkdir $(TEMPORAL_FOLDER) $(BUILD_TEST_FOLDER)

install: $(BUILD_FOLDER)/btt2
		cp -p $(BUILD_FOLDER)/btt2 $(INSTALL_FOLDER)

uninstall: $(INSTALL_FOLDER)/btt2
		rm $(INSTALL_FOLDER)/btt2

reinstall: uninstall install

lines:
		@ printf "	.c files               "
		@ wc -l $(SOURCE_FOLDER)/*.c | grep total
		@ printf "	.h files      		"
		@ wc -l $(SOURCE_FOLDER)/include/* | grep total

compile_install: all install

# TEST SECTION

test: clean-test folders-test test.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_TEST_FOLDER)/btt2test $(CFLAG) $(DEBUG)

test.o:
		gcc -c $(TEST_FOLDER)/characters.c -o $(TEMPORAL_FOLDER)/characters.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_generator.c -o $(TEMPORAL_FOLDER)/characters_generator.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_moves.c -o $(TEMPORAL_FOLDER)/characters_moves.o $(CFLAG) $(DEBUG)
		gcc -c $(SOURCE_FOLDER)/characters/characters_attacks.c -o $(TEMPORAL_FOLDER)/characters_attacks.o $(CFLAG) $(DEBUG)

clean-test:
	  -rm -r $(TEMPORAL_FOLDER) $(BUILD_TEST_FOLDER)