/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:41:44 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:41:46 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

double pow_i(double f, int precision)
{
  int i;

  i = 0;
  while (i < precision)
  {
    f = f * 10;
    i++;
  }
  return (f);
}

int get_len_double(double f, int precision)
{
  int len;
  intmax_t d;

  f = pow_i(f, precision);
  d = (intmax_t)f;
  len = (d < 0) ? 1 : 0;
  if (d == 0)
    return (1);
  while (d != 0)
  {
    len++;
    d = d / 10;
  }
  return (len);
}

void get_float_width_precision(double f, int w, int p, char **str)
{
  intmax_t d;
  int len;
  int i;
  int c;

  c = 0;
  (void)w;
  len = get_len_double(f, p);
  d = (intmax_t)pow_i(f, p);
  *str = (char*)malloc(sizeof(char) * (len + 2));
  (*str)[len + 1] = '\0';
  if (d < 0)
  {
      d = -d;
      (*str)[0] = '-';
      c = -1;
  }
  if (p == 0)
    (*str)[len--] = '\0';
  i = get_len_double(f, 0);
  while (len + c >= 0)
  {
    if (len == i && p != 0)
    {
      (*str)[len--] = '.';
      continue ;
    }
    (*str)[len] = d % 10 + '0';
    d = d / 10;
    len--;
  }
}

void flag_f(t_env *vn, double f, char **str)
{
  int len;
  char c;
  char *tmp[2];

  c = ' ';
  len = get_len_double(f, vn->precision);
  if (vn->precision)
    len++;
  if (vn->width > len)
  {
    len = vn->width - len;
    if (vn->minus == 1)
    {
      tmp[0] = *str;
      tmp[1] = ft_strnew_filled_char(len, c);
      *str = ft_strjoin(*str, tmp[1]);
      free(tmp[0]);
      free(tmp[1]);
    }
    else
    {
      if (vn->plus || vn->space)
        len--;
      while (len > 0)
      {
        ft_putchar(c);
        len--;
      }
    }
  }
}

void print_f(t_env *vn, va_list args, int *i)
{
  double f;
  char *buffer;

  f = 0.0;
  if (vn->conv_type == NULL)
    f = va_arg(args, double);
  else if (!ft_strcmp(vn->conv_type, "L"))
    f = va_arg(args, long double);
  if (!vn->point && !vn->precision)
    vn->precision = 6;
  get_float_width_precision(f, vn->width, vn->precision, &buffer);
  if (f > 0 && vn->plus)
    pad_right(&buffer, 1, '+');
  else if (f > 0 && vn->space)
    pad_right(&buffer, 1, ' ');
  flag_f(vn, f, &buffer);
  ft_putstr(buffer);
  *i += ft_strlen(buffer);
  free(buffer);
}
