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
	char			**split;
}t_stack;

//Prototypes
//ft_atoi.c
long	ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_space(char c);
long	ft_conum(char *str, int i);
//ft_split.c
char	**ft_split(char *str, char sep);
char	*ft_split_2(char *str, char sep, int init, int size);
int		ft_count_sep(char *str, int sep);
//moves.c
void	ft_push(t_stack **origin, t_stack **dest);
void	ft_rotate(t_stack **origin);
void	ft_r_rotate(t_stack **origin);
void	ft_swap(t_stack **origin);
//next_move_2
int		ft_push_a(t_stack **a, t_stack **b, int index);
int		ft_next_move_menos(t_stack **a, t_stack **b, int index);
void	ft_rr_or_r_2(t_stack **a, double x);
//next_move
int		ft_stack_index(t_stack **a, int index);
int		ft_stack_index2(t_stack **a, int index, int max, t_stack *dir);
int		ft_next_move(t_stack **a, t_stack **b, int index);
void	ft_order3(t_stack **a);
void	ft_rr_or_r(t_stack **a, int index, char a_b);
//process_arg.c
void	ft_procces_stack(t_stack **a, int argc, char **argv);
void	ft_procces_stack_one(t_stack **a, char **argv);
t_stack	*ft_stack_new(t_stack **a, long value);
int		ft_reload_stack(t_stack **a, char next_back);
int		ft_stack_is_order(t_stack **a);
//push_swap_utils.c
void	*ft_calloc(int nmemb, int size);
void	ft_bzero(void *s, int n);
void	ft_leaks(void);
void	ft_free_stack(t_stack **a);
void	ft_free_split(char **split);
//push_swap.c
int		main(int argc, char **argv);
void	ft_sort_50(t_stack **a, t_stack **b, int j);
void	ft_sort_all(t_stack **a, t_stack **b, int j, int i);
void	ft_sort_all_2(double *x, double *y, int j);
int		ft_arg_process(int argc, char **argv, t_stack **a);
//visualicer_stack.c
//void	visualicer_stack(t_stack **stack);
// //menu
// void	menu(t_stack **a, t_stack **b);
#endif
