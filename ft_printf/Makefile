# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 11:10:38 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/04/10 00:45:49 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar -rc
RM				=	rm -fr
# COLORS
GREEN			=	`tput setaf 2`
RED				=	`tput setaf 1`
RESET			=	`tput sgr0`
INCLUDE			=	ft_printf.h

SRCS			=	ft_printf.c ft_itoa.c ft_writes.c ft_putbase.c

OBJS = $(SRCS:.c=.o)

$(TRUE).SILENT:

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $?
	@echo "$(GREEN)CREATE ft_Printf $(RESET)\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)REMOVE OBJECT ft_Printf $(RESET)\n"

fclean:
	@$(RM) $(NAME)
	@echo "$(RED)DELETE ft_Printf $(RESET)\n"

re: fclean all