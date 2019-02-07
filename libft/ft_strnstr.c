/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:52:52 by qtran             #+#    #+#             */
/*   Updated: 2017/11/21 15:45:44 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	count;
	char	*tmp;

	if (little[0] != '\0')
	{
		count = ft_strlen(little) - 1;
		tmp = (char*)big;
		while (tmp - big + ft_strlen(little) <= ft_strlen(big) && count < len)
		{
			count++;
			j = 0;
			while (little[j] != '\0')
			{
				if (*(tmp + j) != little[j])
					break ;
				if (++j == ft_strlen(little))
					return (tmp);
			}
			tmp++;
		}
		return (0);
	}
	else
		return ((char*)big);
}
