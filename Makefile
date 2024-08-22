NAME = pipex
SRCS = pipex.c
CFLAGS = -Werror -Wextra -Wall
OBJS = $(SRCS:.c=.o)

.PHONY = clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libft.a

sub :
	make -C ./libft
	make -C ./libft clean

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all