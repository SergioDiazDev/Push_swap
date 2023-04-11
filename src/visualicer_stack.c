/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualicer_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:00:00 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/11 13:22:47 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualicer_stack_a(t_stack_a *stack)
{
	t_stack_a	*a;

	a = stack;
	while (!a)
	{
		ft_printf("a->value:(%d)", a->value);
		ft_printf("a->index:(%d)",a->index);
		ft_printf("a->next:(%p)", a->next);
		a = a->next;
	}
}
