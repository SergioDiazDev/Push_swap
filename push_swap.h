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

//push_swap.c
int	main(int argc, char **argv);
//process_arg.c
void	ft_procces_stack_a(t_stack_a *a, int argc, char **argv);

#endif
