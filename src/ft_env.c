/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:34:33 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 16:00:45 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_env		*init_env(void)
{
	t_env	*vn;

	vn = (t_env*)malloc(sizeof(t_env));
	vn->conv = 0;
	vn->conv_type = "";
	vn->width = 0;
	vn->precision = 0;
	vn->sharp = 0;
	vn->zero = 0;
	vn->minus = 0;
	vn->plus = 0;
	vn->space = 0;
	vn->point = 0;
	return (vn);
}

void		set_flag(t_env *vn, char c)
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

t_bool		set_conv_type(t_env *vn, char **fmt)
{
	char	*str;

	str = ft_strsub(*fmt, 0, 2);
	if (!ft_strcmp(str, "ll") || !ft_strcmp(str, "hh"))
	{
		vn->conv_type = str;
		*fmt += ft_strlen(vn->conv_type);
		return (1);
	}
	free(str);
	str = ft_strsub(*fmt, 0, 1);
	if (!ft_strcmp(str, "l") || !ft_strcmp(str, "L")
			|| !ft_strcmp(str, "h")
			|| !ft_strcmp(str, "j") || !ft_strcmp(str, "z"))
	{
		vn->conv_type = str;
		*fmt += ft_strlen(vn->conv_type);
		return (1);
	}
	free(str);
	vn->conv_type = NULL;
	return (0);
}

void		set_conv(t_env *vn, char c)
{
	vn->conv = c;
}

void		ft_error(char *str_error)
{
	ft_putstr(str_error);
	exit(1);
}
