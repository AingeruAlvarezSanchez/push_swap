NAME = push_swap

RM = rm -rf
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -g3
FILES = push_swap			\
		check_errors		\
		short_cases		\
		push_swap_utils		\
		push_swap_moves1	\
		push_swap_moves2	\
		push_swap_moves3

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(MAKE)  -C ./libft
	@$(MAKE)  -C ./libft bonus
	@mv ./libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)
	@mkdir -p objs
	@mkdir -p bins
	@mv ./libft.a ./bins
	@mv ./libft/*.o ./objs
	@mv ./*.o ./objs
	@echo "##### PUSH SWAP SUCESFULLY COMPILED #####"

clean:
	@$(RM) ./objs
	@echo "##### ALL OBJECTS PURGED #####"

fclean: clean
	@$(RM) ./bins
	@$(RM) ./push_swap
	@echo "##### ALL EXECUTABLES PURGED #####"

all: $(NAME)

re: clean all

.PHONY: all re clean fclean
