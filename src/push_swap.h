/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:27:32 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/06 17:27:32 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//Includes
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"
//structs
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*back;
	int				index;
	long			value;
}t_stack;

//Prototypes
//ft_atoi.c
long	ft_atoi(const char *str);
int		ft_space(char c);
int		ft_isdigit(int c);
long	ft_conum(const char *str, int i);
//ft_split.c
char	**ft_split(char *str, char sep);
char	*ft_split_2(char *str, char sep, int init, int size);
int		ft_count_sep(char *str, int sep);
//process_arg.c
void	ft_procces_stack(t_stack **a, int argc, char **argv);
void	ft_procces_stack_one(t_stack **a, char **argv);
t_stack	*ft_t_stack_new(t_stack **a, long value);
void	ft_reload_stack(t_stack **a, char next_back);
//push_swap_utils.c
void	*ft_calloc(int nmemb, int size);
void	ft_bzero(void *s, int n);
//push_swap.c
int		main(int argc, char **argv);
void	ft_leaks(void);
void	ft_free_stack(t_stack **a);
//visualicer_stack.c
void	visualicer_stack(t_stack **stack);
//moves.c
void	ft_push(t_stack **origin, t_stack **dest);
void	ft_rotate(t_stack **origin);
void	ft_reverse_rotate(t_stack **origin);
void	ft_swap(t_stack **origin);
// //menu
// void	menu(t_stack **a, t_stack **b);
//next_move
int		ft_stack_index(t_stack **a, int index);
int		ft_stack_index2(t_stack **a, int index, int max, t_stack *dir);
int		ft_next_move(t_stack **a, t_stack **b, int index);
int		ft_stack_is_order(t_stack **a);
void	ft_order3(t_stack **a);
int	ft_push_a(t_stack **a, t_stack **b, int index);
#endif
