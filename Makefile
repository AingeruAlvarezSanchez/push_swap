NAME = push_swap

RM = rm -rf
CC = clang
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -g3
FILES = push_swap			\
		check_errors		\
		push_swap_utils1	\
		push_swap_moves1	\
		push_swap_moves2	\
		push_swap_moves3

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(MAKE)  -C ./libft
	$(MAKE)  -C ./libft bonus
	mv ./libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)

clean:
	$(RM) $(OBJS)

all: $(NAME)

re: clean all

fclean: clean
	$(RM) $(NAME) libft.a

.PHONY: all re clean fclean

