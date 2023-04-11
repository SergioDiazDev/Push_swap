/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:05:52 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/11 15:48:13 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *origin, t_stack *dest)
{
	t_stack	*aux;

	aux = origin->next;
	origin = origin->next;
	dest = aux;
}

void	ft_rotate(t_stack *origin, t_stack *dest)
{
	t_stack	*aux;

	aux = origin->next;
	origin = origin->next;
	dest = aux;
	free(aux);
}

void	ft_reverse_rotate(t_stack *origin, t_stack *dest)
{
	t_stack	*aux;

	aux = origin->next;
	origin = origin->next;
	dest = aux;
	free(aux);
}

void	ft_swap(t_stack *origin, t_stack *dest)
{
	t_stack	*aux;

	aux = origin->next;
	origin = origin->next;
	dest = aux;
	free(aux);
}
