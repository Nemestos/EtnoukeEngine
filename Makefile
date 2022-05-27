CC := gcc
# DIRS
SRC_DIR := ./src
INC_DIR := ./include
OBJ_DIR := ./objs
TESTS_DIR := ./tests

#FLAGS

INC := -I/usr/include/SDL2 -I$(INC_DIR)
LDFLAGS := -lSDL2_image -lSDL2
LDFLAGSTEST := -lcriterion
CFLAGS := -Wall -Wextra $(INC) -std=c17
TESTCFLAGS := $(CFLAGS) --coverage 

#FILES
MAIN := $(SRC_DIR)/main.c
SRC :=  $(SRC_DIR)/state_manager.c
OBJ := $(SRC:.c=.o)\
		$(MAIN:.c=.o)

#FILE TESTS
SRCTEST := $(TESTS_DIR)/state_manager_test.c

#PATHS

NAME := game
TESTNAME :=game_tests

all: $(NAME)

$(NAME): $(OBJ)
	@echo -ne "[1;36m"
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
	@echo -ne "[0m"
coverage.info: test
	lcov --capture --directory . --output-file coverage.info

report: coverage.info ## Generate report
	genhtml coverage.info --output-directory out

clean-test:
	@echo -e "[1;33mCleaning tests files :[0m"

	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf out/
	@echo -e "[0m"

clean:
	@echo -e "[1;33mCleaning generated files :[0m"
	rm -rf $(OBJ)
	@echo -e "[0m"

fclean: clean clean-test
	@echo -e "[1;33mCleaning files :[0m"

	rm -rf $(NAME)
	rm -rf $(TESTNAME)
	@echo -e "[0m"

re: fclean all

test:	$(OBJTEST) clean-test
	$(CC) $(SRC) $(SRCTEST) $(TESTCFLAGS) $(LDFLAGSTEST) -o $(TESTNAME)
	./$(TESTNAME)



.PHONY: all clean fclean re test