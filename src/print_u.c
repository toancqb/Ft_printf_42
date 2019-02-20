#include "../includes/ft_printf.h"

int ft_nbr_len_uintmax(uintmax_t d)
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

void	ft_putnbr_uintmax(uintmax_t n)
{
	uintmax_t		lli;

	lli = n;
	if (lli < 0)
	{
		ft_putchar('-');
		lli = -lli;
	}
	if (lli > 9)
	{
		ft_putnbr_uintmax(lli / 10);
		ft_putchar((lli % 10) + '0');
	}
	else
		ft_putchar(lli + '0');
}

void print_uU(t_env *vn, va_list args, int *i)
{
	uintmax_t d;

  if (vn->conv == 'U')
    vn->conv_type = ft_strdup("l");
	d = va_arg(args, uintmax_t);
	if (vn->conv_type == NULL)
		d = (unsigned int)d;
	else if (!ft_strcmp(vn->conv_type, "l"))
		d = (unsigned long)d;
	else if (!ft_strcmp(vn->conv_type, "ll"))
		d = (unsigned long long)d;
	else if (!ft_strcmp(vn->conv_type, "h"))
		d = (unsigned short)d;
	else if (!ft_strcmp(vn->conv_type, "hh"))
		d = (unsigned char)d;
	ft_putnbr_uintmax(d);
	*i += ft_nbr_len_uintmax(d);
}
