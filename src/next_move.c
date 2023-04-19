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
	int		min;
	t_stack	*dir;

	ft_reload_stack(a, 'b');
	while ((*a)->index != -1 && (*a)->next)
		(*a) = (*a)->next;
	min = (*a)->value;
	dir = (*a);
	if ((*a)->index != -1)
		return (-1);
	ft_reload_stack(a, 'b');
	while ((*a)->next)
	{
		if (min > (*a)->next->value && (*a)->next->index == -1)
		{
			dir = (*a)->next;
			min = (*a)->next->value;
		}
		*a = (*a)->next;
	}
	return (ft_stack_index2(a, index, min, dir));
}

int	ft_stack_index2(t_stack **a, int index, int min, t_stack *dir)
{
	ft_reload_stack(a, 'b');
	if (min == (*a)->value)
	{
		if (min == (*a)->value && (*a) != dir)
			return (-2);
		(*a)->index = index;
	}
	while ((*a)->next)
	{
		if (min == (*a)->next->value)
			(*a)->next->index = index;
		if (min == (*a)->next->value && (*a)->next != dir)
			return (-2);
		*a = (*a)->next;
	}
	return (index + 1);
}

int	ft_next_move(t_stack **a, t_stack **b, int index)
{
	ft_reload_stack(a, 'b');
	ft_reload_stack(b, 'b');
	if ((*a)->index == index)
		ft_push(a, b);
	else if ((*a)->next->index == index)
	{
		ft_swap(a);
		ft_push(a, b);
		ft_printf("holaaaaa\n");
	}
	else
	{
		ft_reload_stack(a, 'n');
		if ((*a)->index == index)
		{
			ft_reverse_rotate(a);
			ft_push(a, b);
		}
	}
	return (0);
}
