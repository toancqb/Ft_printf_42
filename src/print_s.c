/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:42:11 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 14:46:35 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_s(t_env *vn, va_list args, int *i)
{
	char	*buffer;
	char	*tmp;

	tmp = va_arg(args, char*);
	buffer = (tmp != NULL) ? ft_strdup(tmp) : NULL;
	flag_sc(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
