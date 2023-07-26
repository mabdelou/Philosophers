CC = gcc -Wall -Werror -Wextra -lpthread

RM = rm -f
NAME = philo
FILES = ./src/main.c \
		./src/ft_atoi.c	\
		./src/ft_utilis_I.c \
		./src/ft_utilis_II.c	\
		./src/ft_utilis_III.c

all:  $(NAME)

$(NAME): $(FILES)
	$(CC) $(FILES)  -o $(NAME)
	

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus