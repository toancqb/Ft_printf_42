/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:54:29 by qtran             #+#    #+#             */
/*   Updated: 2019/02/10 20:54:48 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool is_conv(char c)
{
	char *s;

	s = "cspdiouxX";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

void set_conv(t_env *vn, char c)
{
	vn->conv = c;
}
