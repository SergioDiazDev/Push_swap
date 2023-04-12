/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:05:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/12 15:40:07 by sdiaz-ru         ###   ########.fr       */
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

void	ft_rotate(t_stack **origin)
{
	t_stack	*temp;

	if (*origin)
	{
		while ((*origin)->back)
			*origin = (*origin)->back;
		temp = *origin;
		*origin = (*origin)->next;
		(*origin)->back = NULL;
		while ((*origin)->next)
			*origin = (*origin)->next;
		temp->next = NULL;
		temp->back = *origin;
		(*origin)->next = temp;
	}
}

void	ft_reverse_rotate(t_stack **origin)
{
	t_stack	*temp;

	if (*origin)
	{
		while ((*origin)->next)
			*origin = (*origin)->next;
		temp = *origin;
		*origin = (*origin)->back;
		(*origin)->next = NULL;
		temp->back = NULL;
		while ((*origin)->back)
			*origin = (*origin)->back;
		(*origin)->back = temp;
		temp->next = *origin;
	}
}

void	ft_swap(t_stack **origin)
{
	int	temp;

	while ((*origin)->back)
		*origin = (*origin)->back;
	temp = (*origin)->value;
	(*origin)->value = (*origin)->next->value;
	(*origin)->next->value = temp;
}
