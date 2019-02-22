#include "../includes/ft_printf.h"

void print_xX(t_env *vn, va_list args, int *i)
{
	char *buffer;
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
	intdec_to_hex(vn->conv, d, &buffer);
	if (vn->sharp)
		vn->conv == 'x' ? sharp_xXo("0x", &buffer) : sharp_xXo("0X", &buffer);
	ft_putstr(buffer);
	*i += ft_strlen(buffer);
	free(buffer);
}
