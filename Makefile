NAME = philo
SRCS = main.c init.c \
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m- philo compiled!\033[0m"

clean:
	rm -f $(OBJS)
	@echo "\033[1;33m- Object files removed!\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;31m- philo deleted!\033[0m"

re: fclean all 

.PHONY: all clean fclean re
