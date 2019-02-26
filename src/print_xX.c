/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:42:48 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:42:50 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void sharping(char c, char **buffer)
{
	char *tmp;

	tmp = *buffer;
	*buffer = (c == 'x') ? ft_strjoin("0x", tmp) : ft_strjoin("0X", tmp);
	free(tmp);
}

void sharp_xX(t_env *vn, char **buffer)
{
  int len;

  if (ft_strcmp(*buffer, "0"))
  {
    len = ft_strlen(*buffer);
    vn->width -= 2;
	if (vn->width > len && vn->zero)
	{
		if (!vn->point)
			pad_right(buffer, vn->width - len, '0');
    	sharping(vn->conv, buffer);
	}
    else if (vn->width > len)
    {
    	sharping(vn->conv, buffer);
      	if (vn->minus)
			pad_left(buffer, vn->width - len, ' ');
		else
			pad_right(buffer, vn->width - len, ' ');
    }
    else
    	sharping(vn->conv, buffer);
  }
  else if (!ft_strcmp(*buffer, "0") && (!vn->precision && vn->point))
  {
	free(*buffer);
	*buffer = ft_strdup("");
  }
}

void flag_x(t_env *vn, char **buffer)
{
	int len;

	/*if (!ft_strcmp(*buffer, "0"))
	{
		free(*buffer);
		*buffer = ft_strdup("");
	}*/
	if (!ft_strcmp(*buffer, "0") && (!vn->precision && vn->point))
  	{
		free(*buffer);
		*buffer = ft_strdup("");
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
}

void print_xX(t_env *vn, va_list args, int *i)
{
	char *buffer;
	uintmax_t d;

	d = va_arg(args, uintmax_t);
	if (vn->conv_type == NULL)
		d = (int)d;
	else if (!ft_strcmp(vn->conv_type, "l"))
		d = (unsigned long)d;
	else if (!ft_strcmp(vn->conv_type, "ll"))
		d = (unsigned long long)d;
	else if (!ft_strcmp(vn->conv_type, "h"))
		d = (unsigned short)d;
	else if (!ft_strcmp(vn->conv_type, "hh"))
		d = (unsigned char)d;
	intdec_to_hex(vn->conv, d, &buffer);
	//if (vn->sharp)
	//	vn->conv == 'x' ? sharp_xX("0x", &buffer) : sharp_xX("0X", &buffer);
	if (vn->sharp)
		sharp_xX(vn, &buffer);
	else
		flag_x(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
