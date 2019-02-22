/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:54:29 by qtran             #+#    #+#             */
/*   Updated: 2019/02/10 20:54:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool is_conv(char c)
{
	char *s;

	s = "cspdiouxXf%";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

t_bool is_flag(char c)
{
	char *s;

	s = "-+#0 ";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

t_bool is_width_precision(char c)
{
	return (ft_isdigit(c));
}

void set_width_precision(t_env *vn, char **fmt)
{
	char *tmp;

	tmp = ft_strchr(*fmt, '.');
	if (tmp)
	{
		vn->point = 1;
		tmp++;
		vn->precision = ft_atoi(tmp);
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

void set_flag(t_env *vn, char c)
{
	if (c == '-')
	{
		vn->minus = 1;
		vn->zero = 0;
	}
	if (c == ' ')
		vn->space = 1;
	if (c == '#')
		vn->sharp = 1;
	if (c == '0' && vn->minus == 0)
		vn->zero = 1;
	if (c == '+')
	{
		vn->plus = 1;
		if (vn->conv == 'd' || vn->conv == 'f')
			vn->space = 0;
	}
}

t_bool set_conv_type(t_env *vn, char **fmt)
{
	char *str;

	str = ft_strsub(*fmt, 0, 2);
	if (!ft_strcmp(str, "ll")	|| !ft_strcmp(str, "hh"))
	{
		vn->conv_type = str;
		*fmt += ft_strlen(vn->conv_type);
		return (1);
	}
	free(str);
	str = ft_strsub(*fmt, 0, 1);
	if (!ft_strcmp(str, "l") || !ft_strcmp(str, "L")
		|| !ft_strcmp(str, "h"))
	{
		vn->conv_type = str;
		*fmt += ft_strlen(vn->conv_type);
		return (1);
	}
	free(str);
	vn->conv_type = NULL;
}

void set_conv(t_env *vn, char c)
{
	vn->conv = c;
}
