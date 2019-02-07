#include "../includes/ft_printf.h"

int ft_printf(char *format, ...)
{
	va_list args;
	int count_printed;

	count_printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			handle_main_control(&format, args, &count_printed);
		}
		else if (*format != '%')
		{
			ft_putchar(*format);
			count_printed++;
			format++;
		}
	}
	va_end(args);
	return (count_printed);
}