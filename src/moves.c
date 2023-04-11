/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:05:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/11 21:03:23 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *origin, t_stack *dest)
{
	if (!dest)
	{
		ft_printf("A\n");
		ft_reload_stack(origin);
		origin = origin->next;
		//dest->next = NULL;
		ft_printf("B\n");
		ft_reload_stack(dest);
	}
	
}

void	ft_rotate(t_stack *origin, t_stack *dest)
{
	if (!dest)
	{
		origin->next->back = NULL;
		origin->next = NULL;
	}
}

void	ft_reverse_rotate(t_stack *origin, t_stack *dest)
{
	if (!dest)
	{
		origin->next->back = NULL;
		origin->next = NULL;
	}
}

void	ft_swap(t_stack *origin, t_stack *dest)
{
	if (!dest)
	{
		origin->next->back = NULL;
		origin->next = NULL;
	}
}
