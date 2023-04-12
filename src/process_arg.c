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

void	ft_procces_stack(t_stack **a, int argc, char **argv)
{
	while (--argc != 0)
		ft_t_stack_new(a, ft_atoi(argv[argc]));
}

t_stack	*ft_t_stack_new(t_stack **a, int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->back = NULL;
	new->next = *a;
	new->value = value;
	if (*a != NULL)
		(*a)->back = new;
	*a = new;
	return (new);
}

void	ft_reload_stack(t_stack **a)
{
	if (*a)
	{
		while ((*a)->back)
			(*a) = (*a)->back;
		visualicer_stack(a);
	}
}
