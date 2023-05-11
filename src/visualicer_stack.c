/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualicer_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:00:00 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/05/11 18:42:32 by sdiaz-ru         ###   ########.fr       */
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
			printf("a->index:(%d)\n", (*stack)->index);
			printf("a->next:(%p)\n", (*stack)->next);
			printf("a->back:(%p)\n\n", (*stack)->back);
			(*stack) = (*stack)->next;
		}
		if (stack)
		{
			printf("a->value:(%ld)\n", (*stack)->value);
			printf("a->index:(%d)\n", (*stack)->index);
			printf("a->next:(%p)\n", (*stack)->next);
			printf("a->back:(%p)\n\n", (*stack)->back);
		}
	}
}
