/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:34 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/04/17 13:55:24 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*aux;

	aux = malloc(nmemb * size);
	if (!aux)
		return (NULL);
	ft_bzero(aux, nmemb * size);
	return (aux);
}

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
