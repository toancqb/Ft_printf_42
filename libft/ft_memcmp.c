/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:41:57 by qtran             #+#    #+#             */
/*   Updated: 2017/11/10 04:44:13 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (tmp1 == NULL && tmp2 == NULL)
		return (0);
	else
	{
		i = 0;
		while (i < n)
		{
			if (tmp1[i] != tmp2[i])
				return (tmp1[i] - tmp2[i]);
			i++;
		}
		return (0);
	}
}
