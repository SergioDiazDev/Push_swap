# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 17:22:47 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/04/06 17:22:47 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -fr
INCLUDE			=	push_swap.h
SRCS			=	push_swap.c

@OBJS			=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@gcc -o $(NAME) $(SRCS) $(CFLAGS) 
			@echo push_swap compilado


clean:	
		@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME) 
			@echo Todo limpio
			
re:		fclean all

.PHONY: 	all re clean fclean
