#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

#define PRINTF_BUF 8192

enum				size_spec
{
					nan,
					h,
					hh,
					l,
					ll,
					L
};

typedef	struct		s_flag
{
	int				minus;
	int				plus;
	int				space;
	int				hesh;
	int				zero;
}					t_flag;

typedef struct		s_format
{
	t_flag			flags;
	int				width;
	int				accuracy;
	enum size_spec	size_spec;
	char			type;
}					t_format;


char 				*make_number_string(unsigned long long int num, char type);
int 				signed_integer(char buff[], t_format *f, va_list args);
int 				unsigned_integer(char buff[], t_format *f, va_list args);
int 				make_formatted_string(char buff[], t_format *f, va_list args);
int 				is_it_type(char c);
char				*width_and_accuracy(t_format *f, char *p, va_list va_list);
char				*fill_format(t_format *f, char *param, va_list va_list);
void				fill_zero(t_format *f);
int					ft_printf(const char * restrict param, ...);


#endif //FT_PRINTF_FT_PRINTF_H
