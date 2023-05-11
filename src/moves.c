/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:05:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/05/11 18:41:38 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **origin, t_stack **dest)
{
	t_stack	*temp;

	if (!*origin)
		return ;
	ft_reload_stack(origin, 'b');
	temp = *origin;
	if (!(*origin)->next)
		*origin = NULL;
	else
		*origin = (*origin)->next;
	if (*origin)
			(*origin)->back = NULL;
	if (!*dest)
	{
		*dest = temp;
		(*dest)->next = NULL;
	}
	else
	{
		ft_reload_stack(dest, 'b');
		(*dest)->back = temp;
		temp->next = *dest;
	}
}

void	ft_rotate(t_stack **origin)
{
	t_stack	*temp;

	if (!*origin)
		return ;
	if ((*origin)->next || (*origin)->back)
	{
		ft_reload_stack(origin, 'b');
		temp = *origin;
		*origin = (*origin)->next;
		(*origin)->back = NULL;
		ft_reload_stack(origin, 'n');
		temp->next = NULL;
		temp->back = *origin;
		(*origin)->next = temp;
	}
}

void	ft_r_rotate(t_stack **origin)
{
	t_stack	*temp;

	if (!*origin)
		return ;
	if ((*origin)->next || (*origin)->back)
	{
		ft_reload_stack(origin, 'n');
		temp = *origin;
		*origin = (*origin)->back;
		(*origin)->next = NULL;
		temp->back = NULL;
		ft_reload_stack(origin, 'b');
		(*origin)->back = temp;
		temp->next = *origin;
	}
}

void	ft_swap(t_stack **origin)
{
	int	temp_value;
	int	temp_index;

	if (!*origin)
		return ;
	if ((*origin)->next || (*origin)->back)
	{
		ft_reload_stack(origin, 'b');
		temp_index = (*origin)->index;
		temp_value = (*origin)->value;
		(*origin)->index = (*origin)->next->index;
		(*origin)->value = (*origin)->next->value;
		(*origin)->next->index = temp_index;
		(*origin)->next->value = temp_value;
	}
}
