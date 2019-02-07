/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:16:48 by qtran             #+#    #+#             */
/*   Updated: 2017/11/10 04:45:02 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp1;
	size_t			i;

	tmp = (unsigned char*)dst;
	tmp1 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp1[i];
		i++;
	}
	return (dst);
}
