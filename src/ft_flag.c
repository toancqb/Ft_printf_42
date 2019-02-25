/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:43:33 by qtran             #+#    #+#             */
/*   Updated: 2019/02/23 17:43:35 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *ft_strnew_filled_char(int len, char c)
{
  char *str;

  str = (char*)malloc(sizeof(char) * (len + 1));
  str[len--] = '\0';
  while (len >= 0)
  {
    str[len] = c;
    len--;
  }
  return (str);
}

void pad_left(char **buffer, int width, char c)
{
  char *tmp[2];

  tmp[0] = ft_strnew_filled_char(width, c);
  tmp[1] = *buffer;
  *buffer = ft_strjoin(tmp[1], tmp[0]);
  free(tmp[0]);
  free(tmp[1]);
}

void pad_right(char **buffer, int width, char c)
{
  char *tmp[2];

  tmp[0] = ft_strnew_filled_char(width, c);
  tmp[1] = *buffer;
  *buffer = ft_strjoin(tmp[0], tmp[1]);
  free(tmp[0]);
  free(tmp[1]);
}

void unsigning(char **buffer)
{
  char *tmp;

  tmp = *buffer;
  *buffer = ft_strdup(++tmp);
  free(--tmp);
}

void flag_sc(t_env *vn, char **str)
{
	char *tmp;
	int len;
	char c;

  if ((*str) && vn->precision && vn->precision < (int)ft_strlen(*str))
	{
		tmp = ft_strdup(*str);
		*str = ft_strsub(tmp, 0, vn->precision);
		free(tmp);
	}
	c = ' ';
	if (*str)
    len = ft_strlen(*str);
	if ((*str) && vn->width > len)
	{
		len = vn->width - len;
		if (!vn->minus)
			pad_right(str, len, c);
		else
			pad_left(str, len, c);
	}
  if (!(*str))
    *str = ft_strdup("(null)");
}
