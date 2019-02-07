/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:25:23 by qtran             #+#    #+#             */
/*   Updated: 2017/11/13 16:42:54 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))) || !str)
		return (NULL);
	str[len1 + len2] = '\0';
	i = -1;
	while (++i < len1)
	{
		str[i] = (char)s1[i];
	}
	j = 0;
	while (j < len2)
	{
		str[i + j] = (char)s2[j];
		j++;
	}
	return (str);
}
