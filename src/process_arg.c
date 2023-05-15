/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:03:57 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/06 18:03:57 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_procces_stack(t_stack **a, int argc, char **argv)
{
	while (--argc != 0 && a)
		ft_stack_new(a, ft_atoi(argv[argc]));
}

//leaks
void	ft_procces_stack_one(t_stack **a, char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		;
	while (--i != -1 && ft_stack_new(a, ft_atoi(split[i])))
		;
}
//leaks

t_stack	*ft_stack_new(t_stack **a, long value)
{
	t_stack	*new;

	if (value <= -2147483647 || value >= 2147483648)
		return (ft_printf("Error\n"), ft_free_stack(a), exit(-1), NULL);
	new = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (new == NULL)
		return (NULL);
	new->back = NULL;
	new->next = *a;
	new->value = value;
	new->index = -1;
	if (*a != NULL)
		(*a)->back = new;
	*a = new;
	return (new);
}

int	ft_reload_stack(t_stack **a, char next_back)
{
	int	i;

	i = 1;
	if (!*a)
		return (0);
	if ((*a)->back && next_back == 'b')
	{
		while ((*a)->back)
		{
			(*a) = (*a)->back;
			i++;
		}
	}
	if ((*a)->next && next_back == 'n')
	{
		while ((*a)->next)
		{
			(*a) = (*a)->next;
			i++;
		}
	}
	return (i);
}

int	ft_stack_is_order(t_stack **a)
{
	ft_reload_stack(a, 'b');
	if (!*a)
		return (1);
	while ((*a)->next)
	{
		if ((*a)->index != (*a)->next->index - 1)
			return (0);
		*a = (*a)->next;
	}
	if ((*a)->back->index != (*a)->index - 1)
		return (0);
	return (1);
}
