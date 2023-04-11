/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:05:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/12 01:11:30 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **origin, t_stack **dest)
{
	t_stack	*temp;

	temp = *origin;
	ft_t_stack_new(dest, (*origin)->value);
	*origin = (*origin)->next;
	temp->next = (*origin != NULL) ? (*origin)->next : NULL;
	
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
