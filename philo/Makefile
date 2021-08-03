NAME = philo
HEADER_FILE = philo.h
INC_DIR = ./includes/
SRC_DIR = ./srcs/
CFLAGS = -Wall -Wextra -Werror -pthread -O3
CC = gcc
SRC_FILES =			$(SRC_DIR)main.c \
					$(SRC_DIR)ft_eat.c \
					$(SRC_DIR)ft_isnum.c \
					$(SRC_DIR)ft_printstatus.c \
					$(SRC_DIR)ft_threads.c

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(SRC_FILES) $(INC_DIR)$(HEADER_FILE)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
