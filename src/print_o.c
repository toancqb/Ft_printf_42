#include "../includes/ft_printf.h"

void print_o(t_env *vn, va_list args, int *i)
{
	uintmax_t d;
	char *buffer;

	d = va_arg(args, uintmax_t);
	intdec_to_oct(d, &buffer);
	if (vn->sharp)
		sharp_xXo("0", &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}

void print_percent(int *i)
{
		ft_putchar('%');
		*i++;
}
