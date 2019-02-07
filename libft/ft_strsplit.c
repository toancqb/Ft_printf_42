/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:34:34 by qtran             #+#    #+#             */
/*   Updated: 2017/11/21 16:16:53 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s || !(tab = (char **)malloc(sizeof(char *)
					* (ft_count_(s, c) + 1))) || !tab)
		return (NULL);
	tab[ft_count_(s, c)] = 0;
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != '\0' && s[j] != c)
				j++;
			tab[len++] = ft_strsub(s, i, j - i);
			i = j;
		}
		else
			i++;
	}
	return (tab);
}
