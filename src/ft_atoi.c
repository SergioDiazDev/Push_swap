/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:20:20 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/11 12:47:46 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

long	ft_conum(const char *str, int i)
{
	long	num;

	num = 0;
	while (ft_space(str[i]) && str[i])
		i++;
	while (ft_isdigit(str[i]))
	{
		num += (str[i] - '0');
		num *= 10;
		i++;
	}
	return (num / 10);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signo;

	i = 0;
	signo = 1;
	while (!ft_isdigit(str[i]) && str[i])
		i++;
	if (i == 0)
		;
	else if (i == 1)
		i -= 1;
	else
		i -= 2;
	if ((str[i] == '-' || str[i] == '+') && i >= 1)
		return (0);
	if (i >= 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	return ((ft_conum(str, i) * signo));
}
