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

LIBFT			=	libft/libft.a

all:				$(NAME)
					@echo all done

$(NAME):			$(OBJS)
					make -C libft
					cp	$(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)

$(OBJS): 			$(SRCS)
					$(CC) $(CFLAGS) -c $(SRCS)
			
clean:
					make -C libft clean
					$(RM) $(OBJS)
					@echo clean done

fclean:				clean
					make -C libft fclean
					$(RM) $(NAME)
					@echo fclean done

re:					fclean all
					@echo re done

.PHONY:				all clean fclean re libft

