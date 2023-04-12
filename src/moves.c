/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:05:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/12 13:50:16 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **origin, t_stack **dest)
{
	t_stack	*temp;

	while ((*origin)->back)
		*origin = (*origin)->back;
	temp = *origin;
	ft_t_stack_new(dest, (*origin)->value);
	if (!(*origin)->next)
	{
		ft_printf("ULTIMO");
		(*origin) = NULL;
	}
	else
	{
		*origin = (*origin)->next;
		(*origin)->back = NULL;
	}
	free(temp);
}

void	ft_rotate(t_stack **origin, t_stack **dest)
{
	(void) origin;
	(void) dest;
}

void	ft_reverse_rotate(t_stack **origin, t_stack **dest)
{
	(void) origin;
	(void) dest;
}

void	ft_swap(t_stack **origin, t_stack **dest)
{
	(void) origin;
	(void) dest;
}
