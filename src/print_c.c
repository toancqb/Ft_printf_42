/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:41:29 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 14:46:06 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_null(t_env *vn, int *i)
{
	char		c;

	c = 0;
	if (!vn->minus)
	{
		while (--vn->width > 0 && ++(*i))
			ft_putchar(' ');
		write(1, &c, 1);
		(*i)++;
	}
	else if (vn->minus)
	{
		write(1, &c, 1);
		(*i)++;
		while (--vn->width > 0 && ++(*i))
			ft_putchar(' ');
	}
	return (1);
}

void	print_c(t_env *vn, va_list args, int *i)
{
	char	*buffer;

	buffer = ft_strnew(1);
	buffer[0] = va_arg(args, int);
	if (buffer[0] == '\0')
		print_null(vn, i);
	flag_sc(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
