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

	b = (t_stack **)malloc(sizeof(t_stack *));
	a = (t_stack **)malloc(sizeof(t_stack *));
	if (!a || !b)
		return (0);
	if (argc <= 1)
		return (write(1, "Error\n", 7));
	else if (argc == 2)
		ft_printf("[NO IMPLEMENTADO]argv[1]:%s\n", argv[1]);
	else if (argc > 2)
		ft_procces_stack(a, argc, argv);
	ft_push(a, b);
	ft_push(a, b);
	ft_printf("   Stack A\n");
	ft_reload_stack(a);
	ft_printf("   Stack B\n");
	ft_reload_stack(b);
	return (0);
}
