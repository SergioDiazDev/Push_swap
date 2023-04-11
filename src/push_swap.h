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
typedef struct s_stack_a
{
	struct s_stack_a	*next;
	int					index;
	int					value;
}t_stack_a;

typedef struct s_stack_b
{
	struct t_stack_b	*next;
	int					index;
	int					value;	
}t_stack_b;

//Prototypes
//ft_atoi.c
int			ft_atoi(const char *str);
int			ft_space(char c);
int			ft_isdigit(int c);
long		ft_conum(const char *str, int i);
//ft_split.c
char		**ft_split(char *str, char sep);
char		*ft_split_2(char *str, char sep, int init, int size);
int			ft_count_sep(char *str, int sep);
//process_arg.c
void		ft_procces_stack_a(t_stack_a *a, int argc, char **argv);
t_stack_a	*ft_t_stack_a_new(int value);
void		ft_lstadd_front(t_stack_a **lst, t_stack_a *new);
//push_swap_utils.c
void		*ft_calloc(int nmemb, int size);
void		ft_bzero(void *s, int n);
//push_swap.c
int			main(int argc, char **argv);
//visualicer
void		visualicer_stack_a(t_stack_a *stack);

#endif
