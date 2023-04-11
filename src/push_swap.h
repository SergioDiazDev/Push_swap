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
# include <stdio.h>
# include "../ft_printf/ft_printf.h"
//structs
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*back;
	int				index;
	int				value;
}t_stack;

//Prototypes
//ft_atoi.c
int		ft_atoi(const char *str);
int		ft_space(char c);
int		ft_isdigit(int c);
long	ft_conum(const char *str, int i);
//ft_split.c
char	**ft_split(char *str, char sep);
char	*ft_split_2(char *str, char sep, int init, int size);
int		ft_count_sep(char *str, int sep);
//process_arg.c
void	ft_procces_stack(t_stack *a, int argc, char **argv);
t_stack	*ft_t_stack_new(t_stack *a, int value);
void	ft_reload_stack(t_stack *a);
//push_swap_utils.c
void	*ft_calloc(int nmemb, int size);
void	ft_bzero(void *s, int n);
//push_swap.c
int		main(int argc, char **argv);
//visualicer_stack.c
void	visualicer_stack(t_stack *stack);
//moves.c
void	ft_push(t_stack *origin, t_stack *dest);
void	ft_rotate(t_stack *origin, t_stack *dest);
void	ft_reverse_rotate(t_stack *origin, t_stack *dest);
void	ft_swap(t_stack *origin, t_stack *dest);
#endif
