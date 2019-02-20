#include "../includes/ft_printf.h"

int ft_nbr_len_intmax(intmax_t d)
{
	int len;

	len = 0;
	if (d == 0)
		return (1);
	while (d != 0)
	{
		len++;
		d = d / 10;
	}
	return (len);
}

void	ft_putnbr_intmax(intmax_t n)
{
	intmax_t		lli;

	lli = n;
	if (lli < 0)
	{
		ft_putchar('-');
		lli = -lli;
	}
	if (lli > 9)
	{
		ft_putnbr_intmax(lli / 10);
		ft_putchar((lli % 10) + '0');
	}
	else
		ft_putchar(lli + '0');
}

void print_d(t_env *vn, va_list args, int *i)
{
	intmax_t d;

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
	ft_putnbr_intmax(d);
	*i += ft_nbr_len_intmax(d);
}
