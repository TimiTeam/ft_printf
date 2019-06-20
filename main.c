#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define LONG_LONG_MAX 9223372036854775807
#define LONG_LONG_MIN -9223372036854775807


int 	main()
{
	int ret;

	printf("Max integer = %lld\n\n", INT_MAX);
	ft_printf("-- MY FUNCTION\n");
	ret = ft_printf("Hello, World!%%%++#0013.7hhX\nIt's good %1.1lld\n", INT_MAX, LONG_LONG_MIN);
	ft_putstr("ret = ");
	ft_putnbr(ret);
	ft_putendl("\n\n-- ORIGINAL");
	   ret = printf("Hello, World!%%%++#0013.7hhX\nIt's good %1.1lld\n", INT_MAX, LONG_LONG_MIN);
	ft_putstr("ret = ");
	ft_putnbr(ret);
	write(1, "\n\n", 2);
    return (0);
}
