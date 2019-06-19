#include "ft_printf.h"

static char 				*build_octal_number(unsigned long long int nb)
{
	char 					*ret;
	unsigned long long int	cp;
	int 					size;

	size = 0;
	cp = nb;
	while (cp)
	{
		cp /= 8;
		size++;
	}
	ret = (char*)malloc(sizeof(char) * size + 1);
	ret[size--] = '\0';
	while(nb && size >= 0)
	{
		ret[size--] = (nb % 8) + '0';
		nb /= 8;
	}
	return (ret);
}

static char 				get_hexa_symb(int dec)
{
	char 					a;
	int 					n;

	a = 'a';
	n = 10;
	if (dec < 10)
		return (dec + '0');
	while (dec != n && a <= 'f')
	{
		a++;
		n++;
	}
	return (a);
}

static char 				*build_hexa_number(unsigned long long int nb)
{
	char 					*ret;
	unsigned long long int	cp;
	int 					size;

	size = 0;
	cp = nb;
	while (cp)
	{
		cp /= 16;
		size++;
	}
	ret = (char*)malloc(sizeof(char) * size + 1);
	ret[size--] = '\0';
	while(nb && size >= 0)
	{
		ret[size--] = get_hexa_symb(nb - ((nb / 16) * 16));
		nb /= 16;
	}
	return (ret);
}

static void					in_upper_case(char *nb)
{
	int 					i;

	i = 0;
	while (nb[i])
	{
		if (ft_isalpha(nb[i]))
			nb[i] = nb[i] - 32;
		i++;
	}
}

char 						*make_number_string(unsigned long long int num, char type)
{
	char 					*nb;

	if (type != 'o' && type != 'x' && type != 'X')
		return (ft_itoa(num));
	if (type == 'o')
		nb = build_octal_number(num);
	else
		nb = build_hexa_number(num);
	if (type == 'X')
		in_upper_case(nb);
	return (nb);
}