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
	if (argc <= 1)
		return (0);
	a = (t_stack **)malloc(sizeof(t_stack *));
	if (!a)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		ft_procces_stack_one(a, split);
		if (!split)
			return (ft_printf("Error\n"), ft_free_stack(a), 0);
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
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
	j = 1;
	ft_reload_stack(a, 'b');
	while ((*a)->next)
	{
		j++;
		*a = (*a)->next;
	}
	if (j == 1 || ft_stack_is_order(a))
		return (ft_free_stack(a), 0);
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (!b)
		return (0);
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

	i = (j / 2);
	while (i > 0)
	{
		ft_reload_stack(a, 'b');
		if ((*a)->index < (j / 2))
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
	ft_reload_stack(a, 'b');
	ft_reload_stack(b, 'b');
	j -= 1;
	while (j > (j / 2))
		j = ft_next_move_menos(a, b, j);
	ft_order3(a);
	while (i >= 0)
		i = ft_push_a(a, b, i);
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
