/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:57:36 by qtran             #+#    #+#             */
/*   Updated: 2017/11/10 05:01:19 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long int		lli;

	lli = n;
	if (lli < 0)
	{
		ft_putchar('-');
		lli = -lli;
	}
	if (lli > 9)
	{
		ft_putnbr(lli / 10);
		ft_putchar((lli % 10) + '0');
	}
	else
		ft_putchar(lli + '0');
}
