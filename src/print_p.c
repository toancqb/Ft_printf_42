/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:42:03 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 14:47:11 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	sharp_p(char *str1, char **str2)
{
	char *tmp;

	tmp = *str2;
	*str2 = ft_strjoin(str1, tmp);
	free(tmp);
}

void	print_p(t_env *vn, va_list args, int *i)
{
	char		*buffer;
	uintmax_t	d;

	(void)vn;
	d = va_arg(args, uintmax_t);
	intdec_to_hex('x', d, &buffer);
	sharp_p("0x", &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
