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

void	ft_stack_index(t_stack **a)
{
	int	min;

	ft_reload_stack(a, 'b');
	min = (*a)->value;
	while ((*a)->next)
	{
		if (min > (*a)->next->value)
			min = (*a)->next->value;
		*a = (*a)->next;
	}
	printf("min:%d\n", min);
}
