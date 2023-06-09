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
FT_PRINTF		=	libftprintf.a
# COLORS
GREEN = `tput setaf 2`
RED = `tput setaf 1`
RESET = `tput sgr0`

INCLUDE			=	$(DIR_SRC)/push_swap.h

SRCS			=	$(DIR_SRC)/push_swap.c $(DIR_SRC)/push_swap_utils.c $(DIR_SRC)/process_arg.c $(DIR_SRC)/ft_split.c $(DIR_SRC)/ft_atoi.c \
					$(DIR_SRC)/moves.c $(DIR_SRC)/next_move.c $(DIR_SRC)/next_move_2.c

OBJS = $(SRCS:.c=.o)

$(TRUE).SILENT:

.PHONY: all test d re clean fclean

all: $(NAME)

$(DIR_FT_PRINTF)/$(FT_PRINTF):
	@make -C $(DIR_FT_PRINTF)

$(NAME): $(OBJS) $(DIR_FT_PRINTF)/$(FT_PRINTF)
	@gcc -o $@ $(OBJS) $(DIR_FT_PRINTF)/$(FT_PRINTF)
	@echo "$(GREEN)CREATE push_swap $(RESET)"

d: $(SRCS) $(DIR_FT_PRINTF)/$(FT_PRINTF)
	gcc -g3 -o debug $(SRCS) $(DIR_FT_PRINTF)/$(FT_PRINTF)
	@echo "$(GREEN)DEBUG$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s clean -C $(DIR_FT_PRINTF)
	@$(RM) $(OBJS) debug* push_swap.dSYM
	@echo "$(RED)REMOVE OBJECTS Push_swap$(RESET)\n"

fclean:	clean
	@make -s fclean -C $(DIR_FT_PRINTF)
	@$(RM) $(NAME)
	@echo "$(RED)DELETE Push_swap$(RESET)\n"

test:	all
		time python3 tester.py -n6
		time python3 tester.py -n100
		time python3 tester.py -n500

re:	fclean all

