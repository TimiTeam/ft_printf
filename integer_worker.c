#include "ft_printf.h"

int 						integer_len(long long int num)
{
	int 					len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num = (num - (num % 10)) / 10;
		len++;
	}
	return (len);
}

int 						fill_numbers(char *b, int from, int to, long long nb)
{
	char 					*num;
	int 					i;

	i = 0;
	num = ft_itoa(nb);
	if (num[i] == '-')
		i++;
	while (from < to && num[i])
	{
		b[from] = num[i];
		from++;
		i++;
	}
	ft_strdel(&num);
	return (from);
}

int 						copy_n_chars(char *dst, const char *src, int len)
{
	int 					ret;

	ret = 0;
	if (!dst || !src)
		return (0);
	while (ret <= len && src[ret])
	{
		dst[ret] = src[ret];
		ret++;
	}
	return (ret);
}

int 						fill_char(char *b, int from, int to, char sy)
{
	while (from < to)
	{
		b[from] = sy;
		from++;
	}
	return (from);
}

int 						make_signed_integer(char buff[], t_format *f, long long int num)
{
	int 					ret;
	int 					size;
	int 					int_len;
	int 					space;

	ret = 0;
	int_len = integer_len(num);
	size = int_len > f->width ? int_len : f->width;
	size = size > f->accuracy ? size : f->accuracy;
	space = size - (int_len > f->accuracy ? int_len : f->accuracy);
	if (f->flags.space || f->flags.plus || (int)num < 0)
		space -= 1;
	while (ret < space && !f->flags.minus)
		buff[ret++] = ' ';
	if ((int)num > 0 && (f->flags.space || f->flags.plus))
		buff[ret++] = f->flags.space > f->flags.plus ? ' ' : '+';
	if (f->width <= size && !(f->width > int_len && f->width > f->accuracy) && (f->flags.space || f->flags.plus))
		size++;
	if ((int)num < 0)
		buff[ret++] = '-';
	if (f->accuracy > int_len || !f->flags.minus)
	{
		if (f->flags.minus)
			ret = fill_char(buff, ret, ret + (f->accuracy - int_len), '0');
		else
			ret = fill_char(buff, ret, size - int_len , '0');
		ret = fill_numbers(buff, ret, size, num);
	}
	else if(f->flags.minus)
	{
		//ret = fill_numbers(buff, ret, (f->flags.plus || f->flags.space ? int_len + 1 : int_len), num);
		ret = fill_numbers(buff, ret, int_len + ret, num);
		ret = fill_char(buff, ret, size, ' ');
	}
	ret = fill_char(buff, ret, size, ' ');
	return (ret);
}

int 						make_unsigned_integer(char buff[], t_format *f, unsigned long long int num)
{
	int 					ret;
	int 					size;
	int 					int_len;
	int 					space;
	char 					*nb;

	ret = 0;
	nb = make_number_string(num, f->type);
	int_len = ft_strlen(nb);
	size = int_len > f->width ? int_len : f->width;
	size = size > f->accuracy ? size : f->accuracy;
	space = size - (int_len > f->accuracy ? int_len : f->accuracy);
	if (f->flags.hesh && (f->type == 'x' || f->type == 'X'))
		space -= 2;
	while (ret < space && !f->flags.minus)
		buff[ret++] = ' ';
	if (f->flags.hesh && (f->type == 'x' || f->type == 'X'))
		ret += copy_n_chars(&buff[ret], f->type == 'x' ? "0x" : "0X", 2);
	if (!f->flags.minus)
	{
		ret = fill_char(buff, ret, size - int_len , '0');
		ret += copy_n_chars(&buff[ret], nb, int_len);
	}
	else if (f->flags.minus)
	{
		//ret = fill_char(buff, ret, f->accuracy - int_len , '0');
		ret = fill_char(buff, ret, ret + (f->accuracy - int_len), '0');
		ret += copy_n_chars(&buff[ret], nb, int_len);
		ret = fill_char(buff, ret, size, ' ');
	}
	ft_strdel(&nb);
	return (ret);
}

int 						signed_integer(char buff[], t_format *f, va_list args)
{
	int 					ret;
	long long int			num;

	num = 0;
	if (f->size_spec == nan)
		num = va_arg(args, int);
	else if (f->size_spec == ll)
		num = va_arg(args, long long int);
	else if (f->size_spec == l)
		num = (long int)va_arg(args, long int);
	else if (f->size_spec == h)
		num = (short int)va_arg(args, int);
	else if (f->size_spec == hh)
		num = (signed char)va_arg(args, int);
	ret = make_signed_integer(buff, f, num);
	return (ret);
}

int 						unsigned_integer(char buff[], t_format *f, va_list args)
{
	int 					ret;
	unsigned long long int	num;

	num = 0;
	if (f->size_spec == ll || f->size_spec == nan)
		num = va_arg(args, unsigned long long int);
	else if (f->size_spec == l)
		num = (long int)va_arg(args, unsigned long int);
	else if (f->size_spec == h)
		num = (unsigned short int)va_arg(args, int);
	else if (f->size_spec == hh)
		num = (unsigned char)va_arg(args, int);
	ret = make_unsigned_integer(buff, f, num);
	return (ret);
}