#include "../includes/ft_printf.h"

void intdec_to_hex(char c, int d, char **str)
{
  int d_cpy;
  int len;

  d_cpy = d;
  len = (d == 0) ? 1 : 0;
  while (d_cpy != 0)
  {
    len++;
    d_cpy /= 16;
  }
  *str = (char*)malloc(sizeof(char) * (len + 1));
  (*str)[len--] = '\0';
  while (len >= 0)
  {
    d_cpy = d % 16;
    if (d_cpy < 10)
      (*str)[len] = d_cpy + '0';
    else
      (*str)[len] = (c == 'x')?
           (d_cpy - 10) + 'a' : (d_cpy - 10) + 'A';
    d /= 16;
    len--;
  }
}

void intdec_to_oct(int d, char **str)
{
  int d_cpy;
  int len;

  d_cpy = d;
  len = (d == 0) ? 1 : 0;
  while (d_cpy != 0)
  {
    len++;
    d_cpy /= 8;
  }
  *str = (char*)malloc(sizeof(char) * (len + 1));
  (*str)[len--] = '\0';
  while (len >= 0)
  {
    (*str)[len] = d % 8 + '0';
    d /= 8;
    len--;
  }
}