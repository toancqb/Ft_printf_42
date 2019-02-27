/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:18:15 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 14:24:02 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_check_sign(const char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
			|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int				ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	sign = 1;
	ft_check_sign(str, &i, &sign);
	if (!ft_isdigit(str[i]))
		return (0);
	res = sign * ((int)str[i++] - '0');
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = res * 10 + sign * ((int)str[i++] - '0');
	}
	return (res);
}
