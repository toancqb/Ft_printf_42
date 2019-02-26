/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:41:36 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:41:38 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_nbr_len_intmax(intmax_t d)
{
	int len;

	len = 0;
	if (d < 0)
		len++;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		len++;
		d = d / 10;
	}
	return (len);
}

void	ft_putnbr_to_buf_intmax(char **buffer, intmax_t n, int index)
{
	intmax_t		lli;

	lli = n;
	if (lli < 0)
	{
		(*buffer)[0] = '-';
		lli = -lli;
	}
	if (lli > 9)
	{
		ft_putnbr_to_buf_intmax(buffer, lli / 10, index - 1);
		(*buffer)[index] = (lli % 10) + '0';
	}
	else
		(*buffer)[index] = lli + '0';
}

void flag_d_pos(t_env *vn, int d_pos, int len, char **buffer)
{
	d_pos = 0;
	len = ft_strlen(*buffer);
	if (vn->precision > len)
	{
		pad_right(buffer, vn->precision - len, '0');
		if (vn->plus)
		{
			pad_right(buffer, 1, '+');
			d_pos = 1;
		}
		else if (vn->space)
		{
			pad_right(buffer, 1, ' ');
			d_pos = 1;
		}
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
	if (!d_pos)
	{
		if (vn->plus)
			pad_right(buffer, 1, '+');
		else if (vn->space)
			pad_right(buffer, 1, ' ');
	}
}

void flag_d_neg(t_env *vn, int d_pos, int len, char **buffer)
{
	int check;

	if (d_pos)
	{
		flag_d_pos(vn, d_pos, len, buffer);
	}
	else
	{
		check = 0;
		len = ft_strlen(*buffer);
		unsigning(buffer);
		if (vn->precision > len - 1)
			pad_right(buffer, vn->precision - len + 1, '0');
		else
		{
			pad_right(buffer, 1, '-');
			check = 1;
		}
		len = ft_strlen(*buffer);
		vn->width -= (check == 0) ? 1 : 0;
		if (vn->width > len)
		{	
			if (check)
			{
				unsigning(buffer);
				check = 0;
			}
			if (vn->zero && !vn->point)
				pad_right(buffer, vn->width - len, '0');
			else if (!vn->minus)
				pad_right(buffer, vn->width - len, ' ');
			else if (vn->minus)
				pad_left(buffer, vn->width - len, ' ');
		}		
		if (!check)
			pad_right(buffer, 1, '-');
	}
}

void d_precision(t_env *vn, int d_pos, char **buffer)
{
	char *tmp;
	char c;
	int len;

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
	{
		pad_right(buffer, vn->precision - len, '0');		
    }
    if (vn->plus)
	{
		pad_right(buffer, 1, c);
	}
	else if (d_pos == 0)
		pad_right(buffer, 1, c);
	else if (vn->space && c == '+')
	{
		pad_right(buffer, 1, ' ');
	}
}

void d_width(t_env *vn, int d_pos, char **buffer)
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
	{
		if (d_pos == 1)
			pad_right(buffer, 1, '+');
		else
			pad_right(buffer, 1, '-');
	}
}

void flag_d(t_env *vn, int d_pos, char **buffer)
{
	d_precision(vn, d_pos, buffer);
	d_width(vn, d_pos, buffer);
}

void print_d(t_env *vn, va_list args, int *i)
{
	intmax_t d;
	char *buffer;
	int len;

	d = va_arg(args, intmax_t);
	if (vn->conv_type == NULL)
		d = (int)d;
	else if (!ft_strcmp(vn->conv_type, "l"))
		d = (long)d;
	else if (!ft_strcmp(vn->conv_type, "ll"))
		d = (long long)d;
	else if (!ft_strcmp(vn->conv_type, "h"))
		d = (short)d;
	else if (!ft_strcmp(vn->conv_type, "hh"))
		d = (signed char)d;
	len = ft_nbr_len_intmax(d);
	buffer = (char*)malloc(sizeof(char) * (len + 1));
	buffer[len] = '\0';
	ft_putnbr_to_buf_intmax(&buffer, d, len - 1);
	//flag_d(vn, (int)(d >= 0), len, &buffer);
	flag_d(vn, (int)(d >= 0), &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
