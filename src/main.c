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
	int nbr = 30;

	str = "ahihi";
	i = ft_printf("abc %s %c %d %x\n", str, 'g', nbr, nbr);
	printf("printed %d %d %x\n", i, nbr, nbr);

	return (0);
}
