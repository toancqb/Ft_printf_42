#include "../includes/ft_printf.h"

void print_s(va_list args, int *i)
{
	char *str;

	str = va_arg(args, char*);
	ft_putstr(str);
	*i += ft_strlen(str);
}

void print_c(va_list args, int *i)
{
	char *str;

	str = ft_strnew(1);
	str[0] = va_arg(args, int);
	ft_putstr(str);
	*i += ft_strlen(str);
}

int ft_nbr_len(int d)
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

void print_d(va_list args, int *i)
{
	int d;

	d = va_arg(args, int);
	ft_putnbr(d);
	*i += ft_nbr_len(d);
}

void print_p(va_list args, int *i)
{
	int d;
	//char *str;

	d = va_arg(args, int);
	//intdec_to_hex(d, &str);
	//ft_putstr(str);
	//*i += ft_strlen(str);
	//free(str);
	ft_putnbr(d);
	*i += ft_nbr_len(d);
}

void print_xX(t_env *vn, va_list args, int *i)
{
	int d;
	char *str;

	d = va_arg(args, int);
	intdec_to_hex(vn->conv, d, &str);
	ft_putstr(str);
	*i += ft_strlen(str);
	free(str);
}

void print_o(t_env *vn, va_list args, int *i)
{
	int d;
	char *str;

	d = va_arg(args, int);
	intdec_to_oct(d, &str);
	ft_putstr(str);
	*i += ft_strlen(str);
	free(str);
}

void ft_error(char *str_error)
{
	perror(str_error);
	exit(1);
}
