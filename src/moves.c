/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:05:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/12 17:12:06 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **origin, t_stack **dest)
{
	t_stack	*temp;

	if (*origin)
	{
		while ((*origin)->back)
			*origin = (*origin)->back;
		temp = *origin;
		if (!(*origin)->next)
			*origin = NULL;
		else
			*origin = (*origin)->next;
		if (!*dest)
		{
			(*origin)->back = NULL;
			*dest = temp;
			(*dest)->next = NULL;
			(*dest)->back = NULL;
		}
		else
		{
			while ((*dest)->back)
				*dest = (*dest)->back;
			if (*origin)
				(*origin)->back = NULL;
			(*dest)->back = temp;
			temp->next = *dest;
		}
	}
}

void	ft_rotate(t_stack **origin)
{
	t_stack	*temp;

	if (*origin)
	{
		if ((*origin)->next || (*origin)->back)
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
}

void	ft_reverse_rotate(t_stack **origin)
{
	t_stack	*temp;

	if (*origin)
	{
		if ((*origin)->next || (*origin)->back)
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
}

void	ft_swap(t_stack **origin)
{
	int	temp;

	if (*origin)
	{
		if ((*origin)->next || (*origin)->back)
		{
			while ((*origin)->back)
				*origin = (*origin)->back;
			temp = (*origin)->value;
			(*origin)->value = (*origin)->next->value;
			(*origin)->next->value = temp;
		}
	}
}
