/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:42:41 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:42:43 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_nbr_len_uintmax(uintmax_t d)
{
	int len;

	len = 0;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		len++;
		d = d / 10;
	}
	return (len);
}

void	ft_putnbr_to_buf_uintmax(char **buffer, uintmax_t n, int index)
{
	uintmax_t		lli;

	lli = n;
	if (lli > 9)
	{
		ft_putnbr_to_buf_uintmax(buffer, lli / 10, index - 1);
		(*buffer)[index] = (lli % 10) + '0';
	}
	else
		(*buffer)[index] = lli + '0';
}

void print_uU(t_env *vn, va_list args, int *i)
{
	uintmax_t d;
	char *buffer;
	int len;

  if (vn->conv == 'U')
    vn->conv_type = ft_strdup("l");
	d = va_arg(args, uintmax_t);
	if (vn->conv_type == NULL)
		d = (unsigned int)d;
	else if (!ft_strcmp(vn->conv_type, "l"))
		d = (unsigned long)d;
	else if (!ft_strcmp(vn->conv_type, "j"))
		d = (uintmax_t)d;
	else if (!ft_strcmp(vn->conv_type, "ll"))
		d = (unsigned long long)d;
	else if (!ft_strcmp(vn->conv_type, "h"))
		d = (unsigned short)d;
	else if (!ft_strcmp(vn->conv_type, "hh"))
		d = (unsigned char)d;
	len = ft_nbr_len_uintmax(d);
	buffer = (char*)malloc(sizeof(char) * (len + 1));
	buffer[len] = '\0';
	ft_putnbr_to_buf_uintmax(&buffer, d, len - 1);
	flag_unsigned_nbr(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
