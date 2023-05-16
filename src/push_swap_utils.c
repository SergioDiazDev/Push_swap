/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:34 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/05/16 15:02:39 by sdiaz-ru         ###   ########.fr       */
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
			if ((*a)->split)
				ft_free_split((*a)->split);
		}
		free(*a);
	}
	free(a);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
