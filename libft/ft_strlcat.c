/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:28:05 by qtran             #+#    #+#             */
/*   Updated: 2017/11/08 17:05:27 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;
	int k;
	int n;

	n = size;
	k = 0;
	i = 0;
	while (n-- != 0 && dst[i] != '\0')
		i++;
	j = i;
	n = size - i;
	if (n == 0)
		return (i + ft_strlen(src));
	while (src[k] != '\0')
	{
		if (n != 1)
		{
			dst[i++] = src[k];
			n--;
		}
		k++;
	}
	dst[i] = '\0';
	return (j + k);
}
