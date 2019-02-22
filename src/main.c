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
	float f = 51923.141593;
	int d = 1234567;
	//long long nbr = 1075642223238565640;

	str = "ahihi";
	//i = ft_printf("abc %#llo %p\n", nbr, &nbr);

	i = ft_printf("---%-10.1f---%-+ 10.0f\n", f, f);
	printf("printed %d \n---%-10.1f---%-+ 10.0f\n", i, f, f);

	i = ft_printf("integer %%d: %d %+o\n", d, d);
	printf("printed %d integer %%d: %d %+o\n", i, d, d);

	i = ft_printf("___%0 4c___\n", 'T');
	printf("___%0 4c___printed %d \n", 'T', i);

	//printf("%d\n", ft_atoi("0.2"));

	return (0);
}
