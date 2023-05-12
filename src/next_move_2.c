/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:42:39 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/05/12 10:45:32 by sdiaz-ru         ###   ########.fr       */
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
