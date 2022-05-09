CC := gcc
SRC_DIR := ./src
INC_DIR := ./include
CFLAGS := -Wall -Wextra  -I/usr/include/SDL2 -I$(INC_DIR)
LDFLAGS := -lSDL2_image -lSDL2

SRCS := $(shell find $(SRC_DIR) -name '*.c')

OBJS := $(SRCS:.c=.o)
NAME := game

all:	$(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -rf $(OBJS)
fclean: clean

	rm -rf $(NAME)

re: fclean all