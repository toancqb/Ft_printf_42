#include "../includes/ft_printf.h"

void print_o(t_env *vn, va_list args, int *i)
{
	uintmax_t d;
	char *str;

	d = va_arg(args, uintmax_t);
	intdec_to_oct(d, &str);
	if (vn->sharp)
		sharp_xXo("0", &str);
	ft_putstr(str);
	*i += ft_strlen(str);
	free(str);
}

void print_percent(int *i)
{
		ft_putchar('%');
		*i++;
}

void ft_error(char *str_error)
{
	perror(str_error);
	exit(1);
}
