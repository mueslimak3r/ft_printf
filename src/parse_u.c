#include "ft_printf.h"

size_t		usenbr(t_buffer *buffer, char type, unsigned long long int nbr, int base)
{
	size_t	ret;
	char	*str;

	ret = 0;
	printf("value: %llu\n", nbr);
	str = uitoa_base(nbr, base);
	if (str)
	{
		if (type == 'p')
			ret += ft_savestr(buffer, "0x", -1);
		ret += ft_savestr(buffer, str, -1);
		free(str);
	}
	return (ret);
}

void				get_u(va_list list, t_flags *flags)
{
	t_inbuf			buf;

	if (flags->chr == true)
		buf.u = (unsigned char)va_arg(list, unsigned long long int);
	else if (flags->shrt == true)
		buf.u = (unsigned short)va_arg(list, unsigned long long int);
	else if (flags->longint == true)
		buf.u = (unsigned long)va_arg(list, unsigned long long int);
	else if (flags->llong == true)
		buf.u = (unsigned long long)va_arg(list, unsigned long long int);
	else if (flags->j == true)
		buf.u = (uintmax_t)va_arg(list, unsigned long long int);
	else if (flags->z == true)
		buf.u = (size_t)va_arg(list, unsigned long long int);
	else
		buf.u = va_arg(list, unsigned long long int);
	flags->inbuf = &buf;
}

size_t				parse_u(char type, t_buffer *buffer, t_flags *flags)
{
	size_t				ret;

	ret = 0;
	printf("value: %llu\n", flags->inbuf->u);
	if (type == 'o')
		ret = usenbr(buffer, type, (flags->inbuf->u), 8);
	else if (type == 'u')
		ret = usenbr(buffer, type, flags->inbuf->u, 10);
	else if (type == 'x')
		ret = usenbr(buffer, type, flags->inbuf->u, 16);
	return (ret);
}

size_t		route_u(va_list list, char type, t_buffer *buffer, t_flags *flags)
{
	get_u(list, flags);
	printf("value: %llu\n", flags->inbuf->u);
	return (parse_u(type, buffer, flags));
}