/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:42:39 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/05/18 12:42:23 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_rr_or_r_2(t_stack **a, double x)
{
	int	rr;
	int	r;

	rr = 1;
	r = 0;
	ft_reload_stack(a, 'b');
	while ((*a)->index < x)
	{
		r++;
		*a = (*a)->next;
	}
	ft_reload_stack(a, 'n');
	while ((*a)->index < x)
	{
		rr++;
		*a = (*a)->back;
	}
	if (rr <= r)
		return ((void)ft_printf("r%c\n", 'a'), ft_rotate(a));
	else
		return ((void)ft_printf("rr%c\n", 'a'), ft_r_rotate(a));
}
