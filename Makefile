CC := gcc
# DIRS
SRC_DIR := ./src
INC_DIR := ./include
OBJ_DIR := ./objs
TESTS_DIR := ./tests

#FLAGS

INC := -I/usr/include/SDL2 -I$(INC_DIR)
LDFLAGS := -lSDL2_image -lSDL2
LDFLAGSTEST := $(LDFLAGS) -lcriterion
CFLAGS := -Wall -Wextra $(INC) -std=c17
TESTCFLAGS := $(CFLAGS) --coverage 

#FILES
MAIN := $(SRC_DIR)/main.c

SRC :=  $(SRC_DIR)/etn_state_manager.c\
		$(SRC_DIR)/etn_errors.c\
		$(SRC_DIR)/etn_graphics.c\
		$(SRC_DIR)/etn_engine.c

SRCTEST := $(TESTS_DIR)/state_manager_test.c


OBJ := $(SRC:.c=.o)\
		$(MAIN:.c=.o)

OBJTEST := $(SRC:.c=.o)\
		$(SRCTEST:.c=.o)


#FILE TESTS

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