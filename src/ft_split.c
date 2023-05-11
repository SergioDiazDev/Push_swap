/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:28:37 by sdiaz-ru          #+#    #+#             */
/*   Updated: 2023/05/11 19:17:34 by sdiaz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char *str, char sep)
{
	int		init;
	int		end;
	int		i;
	int		word;
	char	**result;

	word = ft_count_sep(str, sep);
	result = ft_calloc(sizeof(char **), word + 2);
	result[word + 2] = NULL;
	if (!result)
		return (NULL);
	init = 0;
	i = -1;
	while (++i <= word)
	{
		while (str[init] == sep)
			init++;
		end = init + 1;
		while (str[end] != sep && str[end])
			end++;
		if (!str[end - 1])
			return (result);
		result[i] = ft_split_2(str, sep, init, end - init);
		init = end;
	}
	return (result);
}

char	*ft_split_2(char *str, char sep, int init, int size)
{
	int		j;
	char	*result;

	j = -1;
	result = ft_calloc(sizeof(char *), (size) + 1);
	while (str[init] != sep && str[++j])
	{
		result[j] = str[init];
		init++;
	}
	result[init] = 0;
	return (result);
}

int	ft_count_sep(char *str, int sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			if (str[i + 1] != sep && str[i + 1])
				count++;
		}
		i++;
	}
	return (count);
}
