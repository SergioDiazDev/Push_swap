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
	char	**split;
	int		i;
	int		j;

	//atexit(ft_leaks);
	b = (t_stack **)malloc(sizeof(t_stack *));
	a = (t_stack **)malloc(sizeof(t_stack *));
	if (!a || !b)
		return (0);
	if (argc <= 1)
		return (write(1, "Error\n", 7));
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		ft_procces_stack_one(a, split);
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
	}
	else if (argc > 2)
		ft_procces_stack(a, argc, argv);
	////////////////////////////
	i = 0;
	while (i >= 0)
		i = ft_stack_index(a, i);
	if (i == -2)
		return (write(1, "Error-2\n", 9), ft_free_stack(a), ft_free_stack(b), 0);
	if (ft_stack_is_order(a))
		return (0);
	// ft_printf("STACK A\n");
	// visualicer_stack(a);
	j = 1;
	ft_reload_stack(a, 'b');
	while ((*a)->next)
	{
		j++;
		*a = (*a)->next;
	}
	i = 0;
	while (i < (j - 3))
		i = ft_next_move(a, b, i);
	ft_printf("\n\n\nSTACK A\n");
	visualicer_stack(a);
	ft_printf("STACK B\n");
	visualicer_stack(b);
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
	if (!a)
		return ;
	if (*a)
	{
		ft_reload_stack(a, 'n');
		while ((*a)->back)
		{
			(*a) = (*a)->back;
			free((*a)->next);
		}
		free(*a);
	}
	free(a);
}
