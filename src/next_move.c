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
	int		max;
	t_stack	*dir;

	ft_reload_stack(a, 'b');
	while ((*a)->index != -1 && (*a)->next)
		(*a) = (*a)->next;
	max = (*a)->value;
	dir = (*a);
	if ((*a)->index != -1)
		return (-1);
	ft_reload_stack(a, 'b');
	while ((*a)->next)
	{
		if (max < (*a)->next->value && (*a)->next->index == -1)
		{
			dir = (*a)->next;
			max = (*a)->next->value;
		}
		*a = (*a)->next;
	}
	return (ft_stack_index2(a, index, max, dir));
}

int	ft_stack_index2(t_stack **a, int index, int max, t_stack *dir)
{
	ft_reload_stack(a, 'b');
	if (max == (*a)->value)
	{
		if (max == (*a)->value && (*a) != dir)
			return (-2);
		(*a)->index = index;
	}
	while ((*a)->next)
	{
		if (max == (*a)->next->value)
			(*a)->next->index = index;
		if (max == (*a)->next->value && (*a)->next != dir)
			return (-2);
		*a = (*a)->next;
	}
	return (index + 1);
}

int	ft_next_move(t_stack **a, t_stack **b, int index)
{
	ft_reload_stack(a, 'b');
	ft_reload_stack(b, 'b');
	if (!*a)
		return (-2);
	printf("Ñ\n");
	if ((*a)->index == index)
		return (ft_push(a, b), index + 1);
	if ((*a)->next->index == index)
		return (ft_swap(a), ft_push(a, b), index + 1);
	ft_reload_stack(a, 'n');
	if ((*a)->index == index)
		return (ft_reverse_rotate(a), ft_push(a, b), index + 1);
	return (ft_rotate(a), index);
}
