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

void	ft_procces_stack(t_stack *a, int argc, char **argv)
{
	int		i;

	i = 1;
	a->next = NULL;
	a->back = NULL;
	a->value = ft_atoi(argv[1]);
	while (++i < argc)
	{
		ft_t_stack_new(a, ft_atoi(argv[i]));
		a = a->next;
	}
}

t_stack	*ft_t_stack_new(t_stack *a, int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->back = a;
	new->next = NULL;
	new->value = value;
	a->next = new;
	return (new);
}

void	ft_reload_stack(t_stack *a)
{
	if (a)
	{
		while (a->back)
			a = a->back;
		visualicer_stack(a);
	}
}
