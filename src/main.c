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

void ft_test1()
{
	char *str;
	int i,j;

	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x", 0, 0);

printf("\n----------\n");

	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("@moulitest: %5.x %5.0x", 0, 0);
printf("\n----------\n");
	ft_printf("@moulitest: %.10o\n", 42);
	printf("@moulitest: %.10o", 42);
printf("\n----------\n");

	ft_printf("%#010x\n", 42);
	printf("%#010x\n", 42);
	ft_printf("%#10x\n", 42);
	printf("%#10x\n", 42);

printf("\n----------\n");

  ft_printf("%10s is a string\n", "this");
	printf("%10s is a string", "this");

printf("\n----------\n");

	ft_printf("%10s is a string\n", "");
	printf("%10s is a string", "");

printf("\n----------\n");

	//ft_printf("%lld\n", -9223372036854775808);
	//printf("%lld\n", -9223372036854775808);

printf("\n----------\n");

str = NULL;
	i = ft_printf("%s\n", str);
	j = printf("%s\n", str);
	printf("--ft %d-==-%d\n", i, j);

printf("\n----------\n");
}

void ft_test2()
{
	int i,j;

	i = ft_printf("%+5.d\n", 0);
	j = printf("%+5.d\n", 0);
	printf("--ft %d==%d\n", i, j);
	i = ft_printf("%0+5d\n", -42);
	j = printf("%0+5d\n", -42);
	printf("--ft %d==%d\n", i, j);
	i = ft_printf("%05d\n", -42);
	j = printf("%05d\n", -42);
	printf("--ft %d==%d\n", i, j);
	i = ft_printf("%03d\n", 0);
	j = printf("%03d\n", 0);
	printf("--ft %d==%d\n", i, j);
	i = ft_printf("%03d\n", 1);
	j = printf("%03d\n", 1);
	printf("--ft %d==%d\n", i, j);

}

int main(void)
{
	ft_test2();
	return (0);
}