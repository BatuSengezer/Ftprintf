# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 18:18:45 by bsengeze          #+#    #+#              #
#    Updated: 2023/03/21 00:34:24 by bsengeze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror 
AR				=	ar -rcs
RM				=	rm -rf

SRCS 			=	ft_printf.c
OBJS			=	$(SRCS:.c=.o)

LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)
					@echo all done

$(NAME):			$(OBJS)
					make -C $(LIBFT_PATH)
					cp	$(LIBFT) $(NAME)
					mv	$(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)

$(OBJS): 			$(SRCS)
					$(CC) $(CFLAGS) -c $(SRCS)
			
clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)
					@echo clean done

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)
					@echo fclean done

re:					fclean all
					@echo re done

.PHONY:				all clean fclean re libft
