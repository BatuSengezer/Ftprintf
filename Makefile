NAME			=	libftprintf.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar -rcs
RM				=	rm -rf

SRCS 			=	ft_printf.c \
					utils.c \
					print_char.c \
					print_str.c \
					print_num.c \
					print_hex.c \
					print_ptr.c \
					format_identifier.c
					
OBJS			=	$(SRCS:.c=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
					$(AR) $(NAME) $(OBJS)
			
clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re

