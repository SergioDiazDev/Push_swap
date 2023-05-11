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

void	ft_procces_stack_one(t_stack **a, char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		ft_printf("argv[i]:%s\n", argv[i]);
	while (--i != -1 && ft_stack_new(a, ft_atoi(argv[i])))
		;
}

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

void	ft_reload_stack(t_stack **a, char next_back)
{
	if (!*a)
		return ;
	if ((*a)->back && next_back == 'b')
		while ((*a)->back)
			(*a) = (*a)->back;
	if ((*a)->next && next_back == 'n')
		while ((*a)->next)
			(*a) = (*a)->next;
}
