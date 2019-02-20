#include "../includes/ft_printf.h"

void print_p(t_env *vn, va_list args, int *i)
{
	int d;
	//char *str;

	d = va_arg(args, int);
	//intdec_to_hex(d, &str);
	//ft_putstr(str);
	//*i += ft_strlen(str);
	//free(str);
	ft_putnbr(d);
	//*i += ft_nbr_len(d);
}
