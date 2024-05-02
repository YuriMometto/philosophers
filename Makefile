NAME= philos.a

CC= cc

SRCS= philosophers.c erros.c

OBJS= $(SRCS:.c=.o)

CFLAGS= -Wall -Wextra -Werror

INCLUDE= -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:	$(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
