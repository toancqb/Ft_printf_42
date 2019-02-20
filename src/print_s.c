#include "../includes/ft_printf.h"

void print_s(t_env *vn, va_list args, int *i)
{
	char *str;

	str = va_arg(args, char*);
	ft_putstr(str);
	*i += ft_strlen(str);
}
