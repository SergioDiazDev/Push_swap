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

//atexit(ft_leaks);
int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;
	int		j;

	a = (t_stack **)malloc(sizeof(t_stack *));
	if (!a)
		return (0);
	if (!ft_arg_process(argc, argv, a))
		return (ft_free_stack(a), 0);
	j = ft_reload_stack(a, 'b');
	if (j == 1 || ft_stack_is_order(a))
		return (ft_free_stack(a), 0);
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
		return (ft_free_stack(a), 0);
	if (j <= 50)
		ft_sort_50(a, b, j);
	else
	{
		ft_sort_all(a, b, j, j - 1);
		while (j >= 0)
			j = ft_push_a(a, b, j - 1) + 1;
	}
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

void	ft_sort_all(t_stack **a, t_stack **b, int j, int i)
{
	double	x;
	double	y;

	x = 0.8;
	y = 0.2;
	while (x > 0.1)
	{
		while (i > j * x)
		{
			ft_reload_stack(a, 'b');
			if ((*a)->index < j * y - 1)
			{
				ft_printf("pb\n");
				ft_push(a, b);
				i--;
			}
			ft_rr_or_r_2(a, j * y - 1);
		}
		ft_sort_all_2(&x, &y, j);
	}
	i = --j;
	while (j > (j / 2))
		j = ft_next_move_menos(a, b, j);
}

void	ft_sort_all_2(double *x, double *y, int j)
{
	if (j > 250)
	{
		*x -= 0.1;
		*y += 0.1;
	}
	else
	{
		*x -= 0.2;
		*y += 0.2;
	}
}

int	ft_arg_process(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**split;

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
		return (ft_printf("Error\n"), 0);
	return (1);
}
