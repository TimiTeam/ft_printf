#include "ft_printf.h"

static int 		get_digit_size(char *digit)
{
	int 		size;

	size = 0;
	while (digit[size] && ft_isdigit(digit[size]))
		size++;
	return (size);
}

static char		*get_value_width_or_accur(char *p, int *to, va_list va_list)
{
	int 		dig_size;

	dig_size = 0;
	if (ft_isdigit(*p))
	{
		dig_size = get_digit_size(p);
		*to = ft_atoi(p);
	}
	else if (*p == '*')
	{
		dig_size = 1;
		*to = va_arg(va_list, int);
	}
	else
		*to = 1;
	while (dig_size && dig_size--)
		p++;
	return (p);
}

char			*width_and_accuracy(t_format *f, char *p, va_list va_list)
{
	if (!f || !p || !va_list)
		return (NULL);
	if (ft_isdigit(*p) || *p == '*')
		p = get_value_width_or_accur(p, &f->width, va_list);
	if (*p == '.')
		p = get_value_width_or_accur(++p, &f->accuracy, va_list);
	return (p);
}
