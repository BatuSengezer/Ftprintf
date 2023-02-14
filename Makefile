CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= libftprintf.a

SRCS	= 

OBJS	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) #this might not be necessary or -o $@ can be enough

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re