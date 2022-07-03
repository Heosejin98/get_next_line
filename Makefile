NAME		= get_next_line.a

SRCS		= get_next_line.c \
			get_next_line_utils.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all	:	$(NAME)

HEADERS = get_next_line.h

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o	: %.c
	gcc -D BUFFER_SIZE=13 -c $^  -o $@

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re