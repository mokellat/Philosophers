FLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address
NAME = philo

SRC = assign_fun.c utils.c error.c
	

all : $(NAME)

$(NAME): $(SRC) philosophers.c
	gcc $(FLAGS) -o $(NAME) philosophers.c $(SRC) -g -lpthread

bonus:

run: all

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	rm -rf philo

re : fclean all bonus
.PHONY: clean fclean bonus