#include "../includes/ft_printf.h"

int ft_nbr_len_intmax(intmax_t d)
{
	int len;

	len = 0;
	if (d < 0)
		len++;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		len++;
		d = d / 10;
	}
	return (len);
}

void	ft_putnbr_to_buf_intmax(char **buffer, intmax_t n, int index)
{
	intmax_t		lli;

	lli = n;
	if (lli < 0)
	{
		(*buffer)[0] = '-';
		lli = -lli;
	}
	if (lli > 9)
	{
		ft_putnbr_to_buf_intmax(buffer, lli / 10, index - 1);
		(*buffer)[index] = (lli % 10) + '0';
	}
	else
		(*buffer)[index] = lli + '0';
}

void flag_d(t_env *vn, int d_pos, int len, char **buffer)
{
	if (d_pos && vn->plus)
    pad_right(buffer, 1, '+');
  else if (d_pos && vn->space)
    pad_right(buffer, 1, ' ');
	if (vn->width > len)
	{
		if (vn->zero && !vn->point)
			pad_right(buffer, vn->width - len, '0');
		else if (!vn->minus)
			pad_right(buffer, vn->width - len, ' ');
		else if (vn->minus)
			pad_left(buffer, vn->width - len, ' ');
	}
}

void print_d(t_env *vn, va_list args, int *i)
{
	intmax_t d;
	char *buffer;
	int len;

	d = va_arg(args, intmax_t);
	if (vn->conv_type == NULL)
		d = (int)d;
	else if (!ft_strcmp(vn->conv_type, "l"))
		d = (long)d;
	else if (!ft_strcmp(vn->conv_type, "ll"))
		d = (long long)d;
	else if (!ft_strcmp(vn->conv_type, "h"))
		d = (short)d;
	else if (!ft_strcmp(vn->conv_type, "hh"))
		d = (signed char)d;
	len = ft_nbr_len_intmax(d);
	buffer = (char*)malloc(sizeof(char) * (len + 1));
	buffer[len] = '\0';
	ft_putnbr_to_buf_intmax(&buffer, d, len - 1);
	flag_d(vn, (int)(d > 0), len, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
