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

void	ft_procces_stack_a(t_stack_a *a, int argc, char **argv)
{
	while (--argc)
	{
		a->value = ft_atoi(argv[argc]);
		ft_printf("a=");
	}
}
