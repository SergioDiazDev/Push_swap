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
	int		j;

	//atexit(ft_leaks);
	a = (t_stack **)malloc(sizeof(t_stack *));
	if (!a)
		return (0);
	if (!ft_arg_process(argc, argv, a))
		return (0);
	j = ft_reload_stack(a, 'b');
	if (j == 1 || ft_stack_is_order(a))
		return (ft_free_stack(a), 0);
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
		return (ft_free_stack(a), 0);
	if (j <= 50)
		ft_sort_50(a, b, j);
	else
		ft_sort_all(a, b, j);
	return (ft_free_stack(a), ft_free_stack(b), 0);
}

void	ft_sort_50(t_stack **a, t_stack **b, int j)
{
	int	i;

	i = 0;
	while (i < (j - 3))
		i = ft_next_move(a, b, i);
	if (j == 2)
		return (ft_swap(a), (void)ft_printf("sa\n"));
	ft_order3(a);
	j = j - 4;
	while (j >= 0)
		j = ft_push_a(a, b, j);
}

void	ft_sort_all(t_stack **a, t_stack **b, int j)
{
	int	i;

	i = (j / 2) - 1;
	while (i > 0)
	{
		ft_reload_stack(a, 'b');
		if ((*a)->index < (j / 2) - 1)
		{
			ft_printf("pb\n");
			ft_push(a, b);
			i--;
		}
		else
		{
			ft_printf("ra\n");
			ft_rotate(a);
		}
	}
	i = j - 1;
	j -= 1;
	while (j > (j / 2))
		j = ft_next_move_menos(a, b, j);
	while (i >= 0)
		i = ft_push_a(a, b, i);
}

int	ft_arg_process(int argc, char **argv, t_stack **a)
{
	char	**split;
	int		i;

	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		ft_procces_stack_one(a, split);
		i = -1;
	}
	else if (argc > 2)
		ft_procces_stack(a, argc, argv);
	if (!a)
		return (ft_printf("Error\n"), 0);
	i = 0;
	while (i >= 0)
		i = ft_stack_index(a, i);
	if (i == -2)
		return (ft_printf("Error\n"), ft_free_stack(a), 0);
	return (1);
}
