#include "ft_printf.h"


void			fill_zero(t_format *f)
{
	f->width = 0;
	f->accuracy = 0;
	f->size_spec = nan;
	f->flags.hesh = 0;
	f->flags.minus = 0;
	f->flags.plus = 0;
	f->flags.space = 0;
	f->flags.zero = 0;
	f->type = '\0';
}

static int		is_flags (char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '0' || c == '#')
		return (1);
	return (0);
}

static char		*skip_flags(t_format *f, char *p)
{
	while (*p == ' ')
	{
		f->flags.space = 1;
		p++;
	}
	while (*p == '+')
	{
		f->flags.plus = 1;
		p++;
	}
	while (*p == '-')
	{
		f->flags.minus = 1;
		p++;
	}
	while (*p == '#')
	{
		f->flags.hesh = 1;
		p++;
	}
	while (*p == '0')
	{
		f->flags.zero = 1;
		p++;
	}
	return (p);
}

static char		*get_size_specifiers(t_format *f, char *p)
{
	if (*p == 'h' && *(p + 1) != 'h')
		f->size_spec = h;
	else if (*p == 'h' && *(p + 1) == 'h')
	{
		f->size_spec = hh;
		p++;
	}
	else if (*p == 'l' && *(p + 1) != 'l')
		f->size_spec = l;
	else if (*p == 'l' && *(p + 1) == 'l')
	{
		f->size_spec = ll;
		p++;
	}
	else if (*p == 'L')
		f->size_spec = L;
	p++;
	return (p);
}

char			*fill_format(t_format *f, char *param, va_list va_list)
{
	while (*param && is_flags(*param))
		param = skip_flags(f, param);
	param = width_and_accuracy(f, param, va_list);
	if (*param == 'h' || *param == 'l' || *param == 'L')
		param = get_size_specifiers(f, param);
	while (*param && !is_it_type(*param))
		param++;
	f->type = *param++;
	return (param);
}