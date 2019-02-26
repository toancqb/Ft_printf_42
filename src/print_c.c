/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:41:29 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:41:31 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void print_c(t_env *vn, va_list args, int *i)
{
	char *buffer;

	buffer = ft_strnew(1);
	buffer[0] = va_arg(args, int);
	flag_sc(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	if (buffer[0] == '\0')
		(*i)++;
	free(buffer);
}
