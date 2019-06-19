#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int 	main()
{
	int ret;

	printf("Max integer = %lld\n\n", INT_MAX);
	ft_printf("-- MY FUNCTION\n");
	ret = ft_printf("Hello, World!%%%++#0013.7hhX\nIt's good %19.12lld\n", INT_MAX, LONG_LONG_MAX);
	ft_putstr("ret = ");
	ft_putnbr(ret);
	ft_putendl("\n\n-- ORIGINAL");
	   ret = printf("Hello, World!%%%++#0013.7hhX\nIt's good %19.12lld\n", INT_MAX, LONG_LONG_MAX);
	ft_putstr("ret = ");
	ft_putnbr(ret);
	write(1, "\n\n", 2);
	system("leaks -q ft_printf");
    return (0);
}