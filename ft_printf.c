#include "ft_printf.h"

static int		write_and_increment(char *to, char from)
{
	*to = from;
	return (1);
}

int 			ft_printf(const char * restrict param, ...)
{
    int			ret;
    va_list 	va_list;
	t_format	format;
	char 		buff[PRINTF_BUF + 1];

	ret = 0;
	va_start(va_list, param);
	va_end(va_list);
	while (*param && ret < PRINTF_BUF)
	{
		while (*param && *param != '%' && ret < PRINTF_BUF)
			ret += write_and_increment(&buff[ret], *param++);
		if (*param && *(++param) == '%')
			ret += write_and_increment(&buff[ret], *param++);
		else if (*param)
		{
			fill_zero(&format);
			param = fill_format(&format, (char *) param, va_list);
			ret += make_formatted_string(&buff[ret], &format, va_list);
		}
	}
	buff[ret] = '\0';
	write(1, buff, ret);
	return (ret);
}
