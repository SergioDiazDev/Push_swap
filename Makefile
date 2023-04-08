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
DIR_SRC			=	./src
DIR_FT_PRINTF	=	./ft_printf
# COLORS
GREEN = `tput setaf 2`
RED = `tput setaf 1`
RESET = `tput sgr0`

INCLUDE			=	$(DIR_SRC)/push_swap.h

SRCS			=	$(DIR_SRC)/push_swap.c $(DIR_SRC)/push_swap_utils.c $(DIR_SRC)/process_arg.c \

OBJS			=	$(SRCS:.c=.o)

$(FALSE).SILENT:

all:		make_printf $(NAME)

make_printf:
				@$(MAKE) -C $(DIR_FT_PRINTF)

$(NAME):	$(OBJS)
				@gcc $(CFLAGS) -o $(NAME) $(SRCS) $(DIR_FT_PRINTF)/libftprintf.a
				@echo "$(GREEN)CREATE push_swap $(RESET)"

clean:
				@$(MAKE) -s clean -C $(DIR_FT_PRINTF)
				@$(RM) $(OBJS)
				@echo "$(RED)REMOVE OBJECTS Push_swap$(RESET)\n"

fclean:		clean
				@$(MAKE) -s fclean -C $(DIR_FT_PRINTF)
				@$(RM) $(NAME)
				@echo "$(RED)DELETE Push_swap$(RESET)\n"
			
re:		fclean all

.PHONY: 	all make_printf $(NAME) re clean fclean
