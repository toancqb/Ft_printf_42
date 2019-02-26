/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:56:50 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 16:27:56 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_nbr_len_intmax(intmax_t d)
{
	int	len;

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

void	ft_minus_f(char **str, int len, char c)
{
	char	*tmp[2];

	tmp[0] = *str;
	tmp[1] = ft_strnew_filled_char(len, c);
	*str = ft_strjoin(*str, tmp[1]);
	free(tmp[0]);
	free(tmp[1]);
}

void	setuping(int dk, intmax_t *d, char **str, int *c)
{
	if (dk)
	{
		*d = -(*d);
		(*str)[0] = '-';
		*c = -1;
	}
}

void	ft_clr(char **buffer)
{
	free(*buffer);
	*buffer = ft_strdup("");
}
