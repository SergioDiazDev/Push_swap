/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualicer_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:00:00 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/12 00:36:35 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualicer_stack(t_stack **stack)
{
	while (*stack)
	{
		ft_printf("a->value:(%d)\n", (*stack)->value);
		ft_printf("a->index:(%d)\n", (*stack)->index);
		ft_printf("a->next:(%p)\n", (*stack)->next);
		ft_printf("a->back:(%p)\n\n", (*stack)->back);
		(*stack) = (*stack)->next;
	}
}
