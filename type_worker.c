#include "ft_printf.h"

int 			make_char(char buff[], t_format *f, va_list args)
{
	int 		ret;

	ret = 0;
	return (ret);
}

int 			make_string(char buff[], t_format *f, va_list args)
{
	int 		ret;

	ret = 0;
	return (ret);
}


int 			is_it_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'c' || c == 's' || c == 'p' || c == 'f')
		return (1);
	return (0);
}

int 			make_formatted_string(char buff[], t_format *f, va_list args)
{
	int 		ret;

	ret = 0;
	if (f->type == 'd' || f->type == 'i')
			ret = signed_integer(buff, f, args);
	else if (f->type == 'o' || f->type == 'u' || f->type == 'x' || f->type == 'X')
		ret = unsigned_integer(buff, f, args);
	else if (f->type == 's')
		ret = make_string(buff, f, args);
	else if (f->type == 'c')
		ret = make_char(buff, f, args);
	return (ret);
}