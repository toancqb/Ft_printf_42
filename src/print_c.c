#include "../includes/ft_printf.h"

void print_c(t_env *vn, va_list args, int *i)
{
	char *str;

	str = ft_strnew(1);
	str[0] = va_arg(args, int);
	ft_putstr(str);
	*i += ft_strlen(str);
}
