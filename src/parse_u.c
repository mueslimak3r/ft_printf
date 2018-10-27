#include "ft_printf.h"

unsigned long long  get_u(va_list list, char type)
{
	if (type == 0)
		return (0);
	return((unsigned long long)va_arg(list, unsigned int));
}

int     parse_u(va_list list, char type, t_buffer *buffer)
{
	size_t  ret;
	unsigned long long nb;

	nb = get_u(list, type);
	ret = 0;
	if (type == 'o')
		ret = usenbr(buffer, type, nb, 8);
	else if (type == 'u')
		ret = usenbr(buffer, type, nb, 10);
	else if (type == 'x')
		ret = usenbr(buffer, type, nb, 16);
	return (ret);
}