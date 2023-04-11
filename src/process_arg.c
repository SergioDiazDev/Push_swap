/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:03:57 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/06 18:03:57 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_procces_stack_a(t_stack_a *a, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		ft_lstadd_front(&a, ft_t_stack_a_new(ft_atoi(argv[i])));
		ft_printf("a:%d\n", a->value);
	}
}

t_stack_a	*ft_t_stack_a_new(int value)
{
	t_stack_a	*newlist;

	newlist = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (newlist == NULL)
		return (NULL);
	newlist->value = value;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstadd_front(t_stack_a **lst, t_stack_a *new)
{
	new->next = *lst;
	*lst = new;
}
