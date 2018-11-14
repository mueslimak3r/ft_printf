#include "ft_printf.h"

size_t		usenbr(t_flags *flags, t_buffer *buffer, char type, int base)
{
	size_t	ret;
	char	*str;
	int		size;

	ret = 0;
	str = uitoa_base(flags->inbuf->u, base);
	size = (int)ft_strlen(str);
	flags->inbuf->u = 0;
	if (type == 'p' || ((type == 'x' || type == 'X') && flags->pound))
		ret += (ft_isupper(type)) ? ft_savestr(buffer, "0X", -1) : ft_savestr(buffer, "0x", -1);
	str = (ft_isupper(type)) ? ft_strcase(str, 'a') : str;
	size += (type == 'p' || ((type == 'x' || type == 'X') && flags->pound)) ? 2 : 0;
    ret += !(flags->minus) ? (justify_chars(buffer, flags, size, type)) : 0;
    ret += ft_savestr(buffer, str, -1);
    ret += (flags->minus) ? (justify_chars(buffer, flags, size, type)) : 0;
	free(str);
	return (ret);
}

size_t				parse_u(char type, t_buffer *buffer, t_flags *flags)
{
	size_t				ret;

	ret = 0;
	if (type == 'o')
		ret = usenbr(flags, buffer, type, 8);
	else if (type == 'u')
		ret = usenbr(flags, buffer, type, 10);
	else if (type == 'x' || type == 'X' || type == 'p')
		ret = usenbr(flags, buffer, type, 16);
	return (ret);
}

size_t				route_u(va_list list, char type, t_buffer *buffer, t_flags *flags)
{
	t_inbuf			buf;

	if (type == 'p')
		buf.u = va_arg(list, unsigned long long);
	else if (flags->shrt == true || flags->chr == true)
		buf.u = (unsigned long long)va_arg(list, int);
	else if (flags->longint == true)
		buf.u = (unsigned long long)va_arg(list, unsigned long);
	else if (flags->llong == true)
		buf.u = va_arg(list, unsigned long long);
	else if (flags->j == true)
		buf.u = (unsigned long long)va_arg(list, uintmax_t);
	else if (flags->z == true)
		buf.u = (unsigned long long)va_arg(list, size_t);
	else
		buf.u = (unsigned long)va_arg(list, unsigned long);
	flags->inbuf = &buf;
	return (parse_u(type, buffer, flags));
	return (0);
}
