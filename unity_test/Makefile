CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 -D UNITY_INCLUDE_CONFIG_H

SRCS_DIR = ../get_next_line/

# NAME = utest_read_buf.exe
# NAME = test_lorem_ipsum.exe
# NAME = test_short_file.exe
NAME = test_stdin.exe
SRCS = get_next_line.c get_next_line_utils.c
# UTEST
UNIT = unity.c
TEST = $(NAME:%.exe=%.c)
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(UNIT:.c=.o) $(TEST:.c=.o) $(SRCS:.c=.o)

.PHONY: all clean fclean re test ftest memleak

all: test

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SRCS:.c=.o)
	rm -f *.exe

re: fclean all

test: $(NAME)
	clear
	-./$(NAME)

ftest: test
	make fclean

norm:
	norminette $(SRCS_DIR)

memleak: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME)
