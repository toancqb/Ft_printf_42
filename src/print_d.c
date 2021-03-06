/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:41:36 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 15:03:30 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_intmax_neg(char **buffer, intmax_t n)
{
	char		*tmp;
	intmax_t	m;

	m = INT64_MIN;
	if (n == m)
	{
		tmp = *buffer;
		*buffer = ft_strdup("-9223372036854775808");
		free(tmp);
	}
}

void	d_precision(t_env *vn, int d_pos, char **buffer)
{
	char	*tmp;
	char	c;
	int		len;

	if (vn->point && !vn->precision && !ft_strcmp(*buffer, "0"))
	{
		tmp = *buffer;
		*buffer = ft_strdup("");
		free(tmp);
	}
	if (d_pos == 0)
		unsigning(buffer);
	c = (d_pos == 1) ? '+' : '-';
	len = ft_strlen(*buffer);
	if (vn->precision > len)
		pad_right(buffer, vn->precision - len, '0');
	if (vn->plus)
		pad_right(buffer, 1, c);
	else if (d_pos == 0)
		pad_right(buffer, 1, c);
	else if (vn->space && c == '+')
		pad_right(buffer, 1, ' ');
}

void	d_width(t_env *vn, int d_pos, char **buffer)
{
	int len;
	int check;

	check = 0;
	if ((vn->plus && vn->zero) || (d_pos == 0 && vn->zero))
	{
		unsigning(buffer);
		check = 1;
		vn->width--;
	}
	len = ft_strlen(*buffer);
	if (vn->width > len)
	{
		if (vn->zero && !vn->point)
			pad_right(buffer, vn->width - len, '0');
		else if (!vn->minus)
			pad_right(buffer, vn->width - len, ' ');
		else if (vn->minus)
			pad_left(buffer, vn->width - len, ' ');
	}
	if (check == 1)
		(d_pos == 1) ? pad_right(buffer, 1, '+') : pad_right(buffer, 1, '-');
}

void	flag_d(t_env *vn, int d_pos, char **buffer)
{
	d_precision(vn, d_pos, buffer);
	d_width(vn, d_pos, buffer);
}

void	print_d(t_env *vn, va_list args, int *i)
{
	intmax_t	d;
	char		*buffer;

	d = va_arg(args, intmax_t);
	if (vn->conv_type == NULL)
		d = (int)d;
	else if (!ft_strcmp(vn->conv_type, "l") || !ft_strcmp(vn->conv_type, "z"))
		d = (long)d;
	else if (!ft_strcmp(vn->conv_type, "j"))
		d = (intmax_t)d;
	else if (!ft_strcmp(vn->conv_type, "ll"))
		d = (long long)d;
	else if (!ft_strcmp(vn->conv_type, "h"))
		d = (short)d;
	else if (!ft_strcmp(vn->conv_type, "hh"))
		d = (signed char)d;
	buffer = (char*)malloc(sizeof(char) * (ft_nbr_len_intmax(d) + 1));
	buffer[ft_nbr_len_intmax(d)] = '\0';
	(d == INT64_MIN) ? ft_intmax_neg(&buffer, d)
		: ft_putnbr_to_buf_intmax(&buffer, d, ft_nbr_len_intmax(d) - 1);
	flag_d(vn, (int)(d >= 0), &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
