# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:10:38 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/04/08 14:28:59 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
COMPILE_NAME	=	main.out
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar -crs
RM				=	rm -fr
# COLORS
GREEN = `tput setaf 2`
RED = `tput setaf 1`
RESET = `tput sgr0`
INCLUDE			=	ft_printf.h

SRC				=	ft_printf.c ft_itoa.c ft_writes.c ft_putbase.c

$(FALSE).SILENT:

OBJ				=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)CREATED ft_printf $(RESET)\n"

re:		fclean all

clean: 
		@$(RM) $(OBJ)
		@echo "$(RED)REMOVE OBJECT ft_Printf $(RESET)\n"

fclean:		
			@$(RM) $(NAME)
			@echo "$(RED)DELETE ft_Printf $(RESET)\n"

.PHONY: 	all $(NAME) re clean fclean 
