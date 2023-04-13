/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:23:49 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/06 17:23:49 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	atexit(ft_leaks);
	b = (t_stack **)malloc(sizeof(t_stack *));
	a = (t_stack **)malloc(sizeof(t_stack *));
	if (!a || !b)
		return (0);
	if (argc <= 1)
		return (write(1, "Error\n", 7));
	else if (argc == 2)
		ft_procces_stack_one(a, ft_split(argv[1], ' '));
	else if (argc > 2)
		ft_procces_stack(a, argc, argv);
	menu(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}

void	ft_leaks(void)
{
	system("leaks push_swap");
}

void	ft_free_stack(t_stack **a)
{
	if (*a)
	{
		ft_reload_stack(a, 'n');
		while ((*a)->back)
		{
			(*a) = (*a)->back;
			free((*a)->next);
		}
		free((*a));
	}
	free(a);
}
