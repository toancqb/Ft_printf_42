/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:42:03 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:42:06 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void print_p(t_env *vn, va_list args, int *i)
{
	char *buffer;
	uintmax_t d;

	(void)vn;
	d = va_arg(args, uintmax_t);
	intdec_to_hex('x', d, &buffer);
	sharp_xXo("0x", &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
