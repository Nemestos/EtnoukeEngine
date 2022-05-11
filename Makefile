CC := gcc
# DIRS
SRC_DIR := ./src
INC_DIR := ./include
OBJ_DIR := ./objs
TESTS_DIR := ./tests

#FLAGS
TESTCFLAGS := $(CFLAGS) --coverage
INC := -I/usr/include/SDL2 -I$(INC_DIR)
LDFLAGS := -lSDL2_image -lSDL2
LDFLAGSTEST := -lcriterion
CFLAGS := -Wall -Wextra $(INC)

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

clean:
	@echo -e "[1;33mCleaning .o :[0m"
	rm -rf $(OBJ)
	@echo -e "[0m"
fclean: clean
	@echo -e "[1;33mCleaning files :[0m"

	rm -rf $(NAME)
	rm -rf $(TESTNAME)
	@echo -e "[0m"

re: fclean all

test:	$(OBJTEST)
	$(CC) $(SRC) $(SRCTEST) $(CFLAGS) $(LDFLAGSTEST) -o $(TESTNAME)
	./$(TESTNAME)



.PHONY: all clean fclean re test