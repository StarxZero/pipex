# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 13:53:52 by czheng-c          #+#    #+#              #
#    Updated: 2023/06/02 16:06:19 by czheng-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra

NAME = libft.a

SRCS = $(shell find . -name "*.c" ! -name "ft_lst*.c")

SRCS_BONUS = $(shell find . -name "ft_lst*.c")

OBJ := $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

.PHONY  : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJ)  libft.h get_next_line_bonus.h
	ar -rc $(NAME) $^
	ranlib $(NAME)

bonus : $(OBJ) $(OBJ_BONUS)
	ar -rc $(NAME) $^
	ranlib $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
