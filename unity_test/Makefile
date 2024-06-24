CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 -D UNITY_INCLUDE_CONFIG_H

SRCS_DIR = ../get_next_line/
TEST_DIR = ../unity_test/

# NAME = test_lorem_ipsum.exe
# NAME = test_short_file.exe
NAME = test_empty_file.exe
# NAME = test_stdin.exe
SRCS = get_next_line.c get_next_line_utils.c
HEAD = get_next_line.h
UNIT = unity.c
TEST = $(NAME:%.exe=%.c)
SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
OBJS = $(UNIT:.c=.o) $(TEST:.c=.o) $(SRCS:.c=.o)

.PHONY: all clean fclean bclean re test ftest memleak cpybonus

all: test

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SRCS:.c=.o)
	rm -f *.exe

bclean:
	rm -f $(wildcard $(SRCS_DIR)*_bonus.*)

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

cpybonus: $(SRCS)
	cp ../get_next_line/get_next_line.c ../get_next_line/get_next_line_bonus.c
	sed -i 's/get_next_line.c....../get_next_line_bonus.c/' ../get_next_line/get_next_line_bonus.c
	cp ../get_next_line/get_next_line_utils.c ../get_next_line/get_next_line_utils_bonus.c
	sed -i 's/get_next_line_utils.c....../get_next_line_utils_bonus.c/' ../get_next_line/get_next_line_utils_bonus.c
	cp ../get_next_line/get_next_line.h ../get_next_line/get_next_line_bonus.h
	sed -i 's/get_next_line.h....../get_next_line_bonus.h/' ../get_next_line/get_next_line_bonus.h
	sed -i 's/GET_NEXT_LINE_H/GET_NEXT_LINE_BONUS_H/g' ../get_next_line/get_next_line_bonus.h

franc: bclean
	cd $(SRCS_DIR)
	francinette
	cd $(TEST_DIR)

