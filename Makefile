CC := gcc
# DIRS
SRC_DIR := ./src/
INC_DIR := ./include/
OBJ_DIR := ./objs/

#FLAGS
CFLAGS := -Wall -Wextra 
INC := -I/usr/include/SDL2 -I$(INC_DIR)
LDFLAGS := -lSDL2_image -lSDL2

#FILES
SRC_F := main.c state_manager.c
OBJ_F := $(SRC_F:.c=.o)

#PATHS
SRC = $(addprefix $(SRC_DIR), $(SRC_F))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_F))

NAME := game

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@gcc $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generated!"

clean:
	rm -rf $(OBJ)
fclean: clean

	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re