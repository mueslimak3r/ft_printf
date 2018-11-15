#include "ft_printf.h"

int		ft_ftoa(t_flags *flags, t_buffer *buffer, int size)
{
	long double nb;
	int		integer;
	long	fraction;
	char    *str;
	char	*str2;
	int		ret;
	int		size2;

	size2 = size;
	integer = (int)flags->inbuf->f;
	nb = (flags->inbuf->f) - (long double)integer;
	while (size2-- > 0)
		nb *= 10;
	fraction = (long long)nb;// + ((((long long)nb + 1) % 10) < ((long long)nb % 10) ? -(long long)nb : 0);
	//integer += (((((long long)nb + 1) % 10) < ((long long)nb % 10) ? 1 : 0));
	str = ft_itoa(integer);
	str2 = ft_itoa(fraction);
	ret = ft_savestr(buffer, str, -1);
	ret += ft_savechar(buffer, '.', 1);
	ret += (fraction == 0) ? (ft_savechar(buffer, '0', size)) : (ft_savestr(buffer, str2, -1));
	free(str);
	free(str2);
	return (ret);
}

size_t          route_f(va_list list, t_buffer *buffer, t_flags *flags)
{
    t_inbuf     buf;
	int			size;

	size = (flags->limit_size == true) ? flags->max_size : 6;
	if (flags->L == true)
		buf.f = va_arg(list, long double);
	else
		buf.f = (long double)va_arg(list, double);
	flags->inbuf = &buf;
	return (ft_ftoa(flags, buffer, size));
}
