# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:12:22 by aalvarez          #+#    #+#              #
#    Updated: 2022/01/11 10:18:31 by aalvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c	\
		ft_isdigit.c \
		ft_strlen.c		\
		ft_strlcpy.c	\
		ft_split.c 

SRC_BONUS = ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstlast_count.c		\
			ft_lstsmallest.c		\
			ft_lstadd_back.c

INCLUDES = libft.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ = $(SRC:.c=.o)

CC = gcc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	@$(AR) $(NAME) $(OBJ)

bonus: $(OBJ_BONUS) $(INCLUDES)
	@$(AR) $(NAME) $(OBJ_BONUS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $(SRC) $(SRC_BONUS)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
