#include "../includes/ft_printf.h"

void print_c(t_env *vn, va_list args, int *i)
{
	char *buffer;

	buffer = ft_strnew(1);
	buffer[0] = va_arg(args, int);
	flag_s(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
}
