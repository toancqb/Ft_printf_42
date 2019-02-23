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

void sharp_xXo(char *str1, char **str2)
{
  char *tmp;

  tmp = *str2;
  if (ft_strcmp(*str2, "0"))
  {
    *str2 = ft_strjoin(str1, tmp);
    free(tmp);
  }
}

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

void flag_sc(t_env *vn, char **str)
{
	char *tmp;
	int len;
	char c;

	if (vn->precision > ft_strlen(*str))
	{
		tmp = ft_strdup(*str);
		*str = ft_strsub(tmp, 0, vn->precision);
		free(tmp);
	}
	c = ' ';
	len = ft_strlen(*str);
	if (vn->width > len)
	{
		len = vn->width - len;
		if (!vn->minus)
			pad_right(str, len, c);
		else
			pad_right(str, len, c);
	}
}
