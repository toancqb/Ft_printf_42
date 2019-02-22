#include "../includes/ft_printf.h"

void flag_s(t_env *vn, char **str)
{
	char *tmp;
	int len;
	char c;

	if (vn->precision)
	{
		tmp = ft_strdup(*str);
		*str = ft_strsub(tmp, 0, vn->precision);
		free(tmp);
	}
	c = ' ';
	len = ft_strlen(*str);
	if (vn->width > len)
	{
		len = vn->width - len;
		if (!vn->minus)
			pad_right(str, len, c);
		else
			pad_right(str, len, c);
	}
}

void print_s(t_env *vn, va_list args, int *i)
{
	char *buffer;

	buffer = va_arg(args, char*);
	flag_s(vn, &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
}
