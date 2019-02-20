/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:38:58 by qtran             #+#    #+#             */
/*   Updated: 2019/02/10 15:39:00 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(int argc, char *argv[])
{
	char *str;
	int i;
	long long nbr = 1075642223238565640;

	str = "ahihi";
	i = ft_printf("abc %#llo %#lx\n", nbr, 0);

	printf("printed %d %#llo %#x\n", i, nbr, 0);

	//printf("%d\n", ft_atoi("0.2"));

	return (0);
}
