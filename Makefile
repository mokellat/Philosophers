FLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address
NAME = philo

SRC = assign_fun.c utils.c mutex.c thread.c utils_.c
	

all : $(NAME)

$(NAME): $(SRC) philosophers.c
	gcc -o $(NAME) philosophers.c $(SRC) -g -lpthread $(DFLAGS)

bonus:

run: all

clean :
	rm -rf *.o *.dSYM

fclean : clean
	rm -rf $(NAME)
	rm -rf philo

re : fclean all bonus
.PHONY: clean fclean bonus