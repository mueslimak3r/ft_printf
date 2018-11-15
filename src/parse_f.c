#include "ft_printf.h"

char            *ft_ftoa(t_flags *flags, int size)
{
	long double nb;
	int		integer;
	long	fraction;
	char    *str;
	char	*str2;
	char	*ret;

	integer = (int)flags->inbuf->f;
	str = ft_itoa(integer);
	nb = (flags->inbuf->f) - (long double)integer;
	while (size-- > 0)
		nb *= 10;
	fraction = (long)nb;
	str2 = ft_itoa(fraction);
	ret = ft_strnew(ft_strlen(str) + ft_strlen(str2) + 2);
	ret = ft_strcpy(ret, str);
	ret[ft_strlen(str)] = '.';
	ret = ft_strcat(ret, str2);
	free(str);
	free(str2);
	return (ret);
}

size_t          route_f(va_list list, t_buffer *buffer, t_flags *flags)
{
    t_inbuf     buf;
    char        *str;
	int			size;
	int			ret;

	size = (flags->limit_size == true) ? flags->max_size : 6;
	if (flags->L == true)
		buf.f = va_arg(list, long double);
	else
		buf.f = (long double)va_arg(list, double);
	flags->inbuf = &buf;
    str = ft_ftoa(flags, size);
	ret = ft_savestr(buffer, str, -1);
	free(str);
	return (ft_strlen(str));
}
