/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:45:46 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/12 16:09:59 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	menu(t_stack **a, t_stack **b)
{
	char	op;

	while (42)
	{
		ft_printf("   Stack A\n");
		ft_reload_stack(a);
		ft_printf("   Stack B\n");
		ft_reload_stack(b);
		ft_printf("1 pa\n");
		ft_printf("2 pb\n");
		ft_printf("3 sa\n");
		ft_printf("4 sb\n");
		ft_printf("5 ss\n");
		ft_printf("6 ra\n");
		ft_printf("7 rb\n");
		ft_printf("8 rr\n");
		ft_printf("9 rra\n");
		ft_printf("0 rrb\n");
		ft_printf("p rrr\n");
		op = getchar();
		switch(op)
		{
			case '1':
				ft_push(a, b);
				break;
			case '2':
				ft_push(b, a);
				break;
			case '3':
				ft_swap(a);
				break;
			case '4':
				ft_swap(b);
				break;
			case '5':
				ft_swap(a);
				ft_swap(b);
				break;
			case '6':
				ft_rotate(a);
				break;
			case '7':
				ft_rotate(b);
				break;
			case '8':
				ft_rotate(a);
				ft_rotate(b);
				break;
			case '9':
				ft_reverse_rotate(a);
				break;
			case '0':
				ft_reverse_rotate(b);
				break;
			case 'p':
				ft_reverse_rotate(a);
				ft_reverse_rotate(b);
				break;
			default:
				ft_printf("Error\n");
				break;
		}
	}
}
