#include "../includes/ft_printf.h"

void print_xX(t_env *vn, va_list args, int *i)
{
	/*unsigned int d;
	char *str;

	d = va_arg(args, unsigned int);*/
	char *str;
	uintmax_t d;

	d = va_arg(args, uintmax_t);
	if (vn->conv_type == NULL)
		d = (int)d;
	else if (!ft_strcmp(vn->conv_type, "l"))
		d = (unsigned long)d;
	else if (!ft_strcmp(vn->conv_type, "ll"))
		d = (unsigned long long)d;
	else if (!ft_strcmp(vn->conv_type, "h"))
		d = (unsigned short)d;
	else if (!ft_strcmp(vn->conv_type, "hh"))
		d = (unsigned char)d;
	intdec_to_hex(vn->conv, d, &str);
	if (vn->sharp)
		vn->conv == 'x' ? sharp_xXo("0x", &str) : sharp_xXo("0X", &str);
	ft_putstr(str);
	*i += ft_strlen(str);
	free(str);
}
