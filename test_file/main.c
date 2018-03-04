#include <stdio.h>
#include "../ft_printf.h"

int ft_test(char const *format, ...)
{
	int i = 0;
	va_list ar;

	va_start(ar, format);
	printf("%d: %s\n",i++, format);
	
	printf("%d: %s\n", i++, va_arg(ar, char*));
	printf("%d: %s\n", i++, va_arg(ar, char*));


	va_end(ar);

}

int	main(int argc, char *argv[])
{

	ft_test("abc", "xyz");	

	return (0);
}
