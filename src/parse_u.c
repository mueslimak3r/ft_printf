#include "ft_printf.h"

int     parse_u(va_list list, char type, t_buffer *buffer)
{
    size_t  ret;
    unsigned long long nb;
    ret = 0;
    if (type == 'o')
		ret = usenbr(buffer, type, nb, 8);
	else if (type == 'u')
		ret = usenbr(buffer, type, nb, 10);
	else if (type == 'x')
		ret = usenbr(buffer, type, nb, 16);
    return (ret);
}