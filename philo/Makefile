NAME = philo
HEADER_FILE = philo.h
INC_DIR = ./includes/
SRC_DIR = ./srcs/
CFLAGS = -Wall -Wextra -Werror
SRC_FILES =			$(SRC_DIR)main.c \
					$(SRC_DIR)ft_bmp_save.c \
					$(SRC_DIR)ft_check_map.c \
					$(SRC_DIR)ft_game_init.c 

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