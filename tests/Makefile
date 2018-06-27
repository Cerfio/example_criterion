##
## EPITECH PROJECT, 2018
## emacs
## File description:
## test_criterion
##

SRCS = 	src/test.c		\
	src/check_victory.c	\
	src/initialize_game.c	\
	src/loop_game.c		\
	src/replace_word.c	\

OBJS = $(SRCS:.c=.o)

CC := gcc

CPPFLAGS += -I include

CFLAGS += -Wall -Wextra

LDFLAGS += -lcriterion

NAME = test

NAME_COVERAGE = test_coverage

FILE_COVERAGE = .coverage.info

DIRECTORY_COVERAGE = out

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)
run:
	@ ./$(NAME) --verbose
cov:
	gcc $(SRCS) -I include -lcriterion --coverage -o $(NAME_COVERAGE)
	./$(NAME_COVERAGE)
	$(RM) $(NAME_COVERAGE)
	mv *.gcno coverage
	mv *.gcda coverage
	lcov --capture --directory coverage --output-file $(FILE_COVERAGE)
	genhtml $(FILE_COVERAGE) --output-directory $(DIRECTORY_COVERAGE)
	firefox $(addprefix $(DIRECTORY_COVERAGE)/, index.html)
clean:
	$(RM) $(OBJS)
	$(RM) coverage/*.gcno
	$(RM) coverage/*.gcda
fclean: clean
	$(RM) $(NAME)
	$(RM) $(FILE_COVERAGE)
	$(RM) -rf $(DIRECTORY_COVERAGE)
re: fclean all

.PHONY: clean fclean run re cov
