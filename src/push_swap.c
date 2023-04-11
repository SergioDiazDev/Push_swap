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
	t_stack_a	a;

	if (argc <= 1)
		return (write(1, "Error\n", 7));
	else if (argc == 2)
		printf("argv[1]:%s\n", argv[1]);
	else if (argc > 2)
		ft_procces_stack_a(&a, argc, argv);
	visualicer_stack_a(&a);
	return (0);
}
