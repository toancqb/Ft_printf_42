/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:34:33 by qtran             #+#    #+#             */
/*   Updated: 2019/02/10 20:34:34 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_env *init_env()
{
  t_env *vn;

  vn = (t_env*)malloc(sizeof(t_env));
  vn->conv = 0;
  vn->conv_type = "";
  vn->width = 0;
  vn->precision = 0;
  vn->sharp = 0;
  vn->zero = 0;
  vn->minus = 0;
  vn->plus = 0;
  vn->space = 0;
  vn->point = 0;
  return (vn);
}

void test_display_env(t_env *vn) //
{
  int c;
  c = vn->sharp == 0? 0 : 1;
  ft_putnbr(c);
  c = vn->zero == 0? 0 : 1;
  ft_putnbr(c);
  c = vn->minus == 0? 0 : 1;
  ft_putnbr(c);
  c = vn->plus == 0? 0 : 1;
  ft_putnbr(c);
  c = vn->space == 0? 0 : 1;
  ft_putnbr(c);
  c = vn->point == 0? 0 : 1;
  ft_putnbr(c); ft_putstr("\n");
  ft_putnbr(vn->width); ft_putchar('.');
  ft_putnbr(vn->precision);
  ft_putstr("\n");
  ft_putstr(vn->conv_type); ft_putstr("\n");
  ft_putchar(vn->conv); ft_putstr("\n");
}

void ft_error(char *str_error)
{
  ft_putstr(str_error);
	exit(1);
}
