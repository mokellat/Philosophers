FLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address
NAME = philo

SRC = 

all : $(NAME)

$(NAME): $(SRC) philosophers.c
	gcc $(FLAGS) -o $(NAME) philosophers.c $(SRC) -g

bonus:

run: all

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	rm -rf push_swap
	rm -rf $(CHECKER)
	rm -rf checker

re : fclean all bonus
.PHONY: clean fclean bonus