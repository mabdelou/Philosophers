CC = gcc -Wall -Werror -Wextra

RM = rm -f
NAME = philo_bonus
FILES = ./src/main_bonus.c \
		./src/ft_atoi_bonus.c	\
		./src/ft_utilis_I_bonus.c \
		./src/ft_utilis_II_bonus.c	\
		./src/ft_utilis_III_bonus.c

all:  $(NAME)

$(NAME): $(FILES)
	$(CC) $(FILES)  -o $(NAME)
	

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus