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
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (a == NULL)
		return (0);
	if (argc <= 1)
		return (write(1, "Error\n", 7));
	else if (argc == 2)
		ft_printf("[NO IMPLEMENTADO]argv[1]:%s\n", argv[1]);
	else if (argc > 2)
		ft_procces_stack(a, argc, argv);
	ft_printf("   Stack A\n");
	return (0);
}
