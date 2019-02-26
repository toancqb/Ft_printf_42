/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:39:06 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 14:55:58 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	args;
	int		count_printed;

	count_printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			process_main(&format, args, &count_printed);
		}
		else if (*format != '%')
		{
			ft_putchar(*format);
			count_printed++;
			format++;
		}
	}
	va_end(args);
	return (count_printed);
}
