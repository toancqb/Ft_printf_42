#include "../includes/ft_printf.h"

void print_p(t_env *vn, va_list args, int *i)
{
	char *buffer;
	uintmax_t d;

	d = va_arg(args, uintmax_t);
	intdec_to_hex('x', d, &buffer);
	sharp_xXo("0x", &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
