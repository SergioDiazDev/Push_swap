/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualicer_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:00:00 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/14 01:00:24 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualicer_stack(t_stack **stack)
{
	if (*stack)
	{
		ft_reload_stack(stack, 'b');
		while ((*stack)->next)
		{
			printf("a->value:(%ld)\n", (*stack)->value);
			ft_printf("a->index:(%d)\n", (*stack)->index);
			ft_printf("a->next:(%p)\n", (*stack)->next);
			ft_printf("a->back:(%p)\n\n", (*stack)->back);
			(*stack) = (*stack)->next;
		}
		if (stack)
		{
			printf("a->value:(%ld)\n", (*stack)->value);
			ft_printf("a->index:(%d)\n", (*stack)->index);
			ft_printf("a->next:(%p)\n", (*stack)->next);
			ft_printf("a->back:(%p)\n\n", (*stack)->back);
		}
	}
}
