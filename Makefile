CC := clang
CFLAGS += -Wall -Wextra -pedantic -std=gnu11
LDFLAGS +=

MAKE := make

NAME = pendu

SRCS = src/main.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

tests: all
	$(MAKE) -C ./tests/ fclean
	$(MAKE) -C ./tests/
	$(MAKE) -C ./tests/ run

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./tests/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re tests
