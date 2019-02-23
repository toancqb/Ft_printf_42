/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:41:52 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:41:57 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void sharp_xXo(char *str1, char **str2)
{
  char *tmp;

  tmp = *str2;
  if (ft_strcmp(*str2, "0"))
  {
    *str2 = ft_strjoin(str1, tmp);
    free(tmp);
  }
}

void flag_unsigned_nbr(t_env *vn, char **buffer)
{
	int len;

	if (!ft_strcmp(*buffer, "0"))
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

void print_o(t_env *vn, va_list args, int *i)
{
	uintmax_t d;
	char *buffer;

	d = va_arg(args, uintmax_t);
	intdec_to_oct(d, &buffer);
	if (vn->sharp)
		sharp_xXo("0", &buffer);
	flag_unsigned_nbr(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}

void print_percent(t_env *vn, int *i)
{
		char *buffer;

		buffer = ft_strnew(1);
		buffer[0] = '%';
		flag_sc(vn, &buffer);
		ft_putstr(buffer);
		*i += ft_strlen(buffer);
}
