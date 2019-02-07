/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:35:19 by qtran             #+#    #+#             */
/*   Updated: 2017/11/10 04:39:01 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i++;
	j = ft_strlen((char *)s) - 1;
	while (s[j] != '\0' &&
	((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t')) && j > i)
		j--;
	if (i == j)
	{
		if (!(str = (char *)malloc(sizeof(char))) || !str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	return (ft_strsub(s, i, j - i + 1));
}
