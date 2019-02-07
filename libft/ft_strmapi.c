/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:09:13 by qtran             #+#    #+#             */
/*   Updated: 2017/11/10 04:41:04 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	return (str);
}
