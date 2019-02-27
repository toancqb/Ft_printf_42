/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:54:29 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 14:57:41 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	is_conv(char c)
{
	char	*s;

	s = "cspdiouUxXf%";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

t_bool	is_flag(char c)
{
	char	*s;

	s = "-+#0 ";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

t_bool	is_width_precision(char c)
{
	return (ft_isdigit(c) || (t_bool)(c == '.'));
}

void	set_width_precision(t_env *vn, char **fmt)
{
	char	*tmp;

	tmp = ft_strchr(*fmt, '.');
	if (tmp)
	{
		vn->point = 1;
		tmp++;
		vn->precision = ft_atoi(tmp);
		vn->zero = 0;
	}
	else
		vn->precision = 0;
	vn->width = ft_atoi(*fmt);
	tmp = *fmt;
	while (*tmp && (*tmp == '.' || ft_isdigit(*tmp)))
	{
		tmp++;
	}
	*fmt = tmp;
}
