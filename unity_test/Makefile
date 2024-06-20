CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42

SRCS_DIR = ../get_next_line/

NAME = test.exe
SRCS = get_next_line.c get_next_line_utils.c
TEST = test_get_next_line.c
# UTEST
UNIT = unity.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(UNIT:.c=.o) $(TEST:.c=.o) $(SRCS:.c=.o)

.PHONY: all clean fclean re test ftest memleak

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(UNIT:.c=.o) $(TEST:.c=.o)

fclean: clean
	rm -f $(SRCS:.c=.o)
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	clear
	-./$(NAME)

ftest: test
	make fclean

memleak: $(NAME)
	valgrind -s --leak-check=full ./$(NAME)
