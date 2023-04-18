/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:59:28 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/13 15:59:28 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_index(t_stack **a, int index)
{
	int	min;

	ft_reload_stack(a, 'b');
	while ((*a)->index != -1 && (*a)->next)
		(*a) = (*a)->next;
	min = (*a)->value;
	if ((*a)->index != -1)
		return (0);
	ft_reload_stack(a, 'b');
	while ((*a)->next)
	{
		if (min > (*a)->next->value && (*a)->next->index == -1)
			min = (*a)->next->value;
		*a = (*a)->next;
	}
	ft_reload_stack(a, 'b');
	if (min == (*a)->value)
		(*a)->index = index;
	while ((*a)->next)
	{
		if (min == (*a)->next->value)
			(*a)->next->index = index;
		*a = (*a)->next;
	}
	return (1);
}
