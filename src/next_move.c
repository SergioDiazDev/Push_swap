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
		if (max > (*a)->next->value && (*a)->next->index == -1)
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
	if ((*a)->index == index)
		return (ft_printf("pb\n"), ft_push(a, b), index + 1);
	if ((*a)->next->index == index)
		return (ft_printf("sa\npb\n"), ft_swap(a), ft_push(a, b), index + 1);
	ft_reload_stack(a, 'n');
	if ((*a)->index == index)
		return (ft_printf("rra\npb\n"), ft_r_rotate(a), ft_push(a, b), index + 1);
	return (ft_rr_or_r(a, index, 'a'), index);
}

int	ft_stack_is_order(t_stack **a)
{
	ft_reload_stack(a, 'b');
	if (!*a)
		return (1);
	while ((*a)->next)
	{
		if ((*a)->index != (*a)->next->index - 1)
			return (0);
		*a = (*a)->next;
	}
	if ((*a)->back->index != (*a)->index - 1)
		return (0);
	return (1);
}

void	ft_order3(t_stack **a)
{
	if (ft_stack_is_order(a))
		return ;
	ft_reload_stack(a, 'b');
	if ((*a)->value < (*a)->next->value)
	{
		ft_printf("rra\n");
		ft_r_rotate(a);
		if (ft_stack_is_order(a))
			return ;
		return ((void)ft_printf("sa\n"), ft_swap(a));
	}
	if ((*a)->next->value > (*a)->next->next->value)
		return ((void)ft_printf("sa\nrra\n"), ft_swap(a), ft_r_rotate(a));
	if ((*a)->value > (*a)->next->next->value)
		return ((void)ft_printf("ra\n"), ft_rotate(a));
	return ((void)ft_printf("sa\n"), ft_swap(a));
}

int	ft_push_a(t_stack **a, t_stack **b, int index)
{
	ft_reload_stack(a, 'b');
	ft_reload_stack(b, 'b');
	if (!*b)
		return (-2);
	if ((*b)->index == index)
		return (ft_printf("pa\n"), ft_push(b, a), index - 1);
	if ((*b)->next->index == index)
		return (ft_printf("sb\npa\n"), ft_swap(b), ft_push(b, a), index - 1);
	ft_reload_stack(b, 'n');
	if ((*b)->index == index)
		return (ft_printf("rrb\npa\n"), ft_r_rotate(b), ft_push(b, a), index - 1);
	return (ft_rr_or_r(b, index, 'b'), index);
}

void	ft_rr_or_r(t_stack **a, int index, char a_b)
{
	int	rr;
	int	r;

	rr = 0;
	r = 0;
	ft_reload_stack(a, 'b');
	while ((*a)->index != index)
	{
		r++;
		*a = (*a)->next;
	}
	ft_reload_stack(a, 'n');
	while ((*a)->index != index)
	{
		rr++;
		*a = (*a)->back;
	}
	if (rr > r)
		return ((void)ft_printf("r%c\n", a_b), ft_rotate(a));
	else
		return ((void)ft_printf("rr%c\n", a_b), ft_r_rotate(a));
}

int	ft_next_move_menos(t_stack **a, t_stack **b, int index)
{
	ft_reload_stack(a, 'b');
	ft_reload_stack(b, 'b');
	if (!*a)
		return (-2);
	if ((*a)->index == index)
		return (ft_printf("pb\n"), ft_push(a, b), index - 1);
	if ((*a)->next->index == index)
		return (ft_printf("sa\npb\n"), ft_swap(a), ft_push(a, b), index - 1);
	ft_reload_stack(a, 'n');
	if ((*a)->index == index)
		return (ft_printf("rra\npb\n"), ft_r_rotate(a), ft_push(a, b), index - 1);
	return (ft_rr_or_r(a, index, 'a'), index);
}
