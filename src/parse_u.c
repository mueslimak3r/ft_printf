/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:45:37 by calamber          #+#    #+#             */
/*   Updated: 2018/11/30 16:00:36 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			usenbr(t_flags *flags, t_buffer *buffer, char type, int base)
{
	size_t		ret;
	char		*str;
	int			size;

	ret = 0;
	str = uitoa_base(flags->inbuf->u, base);
	size = (int)ft_strlen(str);
	flags->inbuf->u = 0;
	if (type == 'p' || ((type == 'x' || type == 'X') && flags->pound))
		ret += (ft_isupper(type)) ? ft_savestr(buffer, "0X", -1)
			: ft_savestr(buffer, "0x", -1);
	str = (ft_isupper(type)) ? ft_strcase(str, 'a') : str;
	size += (type == 'p' || ((type == 'x' ||
					type == 'X') && flags->pound)) ? 2 : 0;
	ret += !(flags->minus) ? (justify_chars(buffer, flags, size, type)) : 0;
	ret += ft_savestr(buffer, str, -1);
	ret += (flags->minus) ? (justify_chars(buffer, flags, size, type)) : 0;
	free(str);
	return (ret);
}

size_t			parse_u(char type, t_buffer *buffer, t_flags *flags)
{
	size_t		ret;

	ret = 0;
	if (type == 'o')
		ret = usenbr(flags, buffer, type, 8);
	else if (type == 'u')
		ret = usenbr(flags, buffer, type, 10);
	else if (type == 'x' || type == 'X' || type == 'p')
		ret = usenbr(flags, buffer, type, 16);
	return (ret);
}

size_t			route_u(va_list l, char t, t_buffer *b, t_flags *f)
{
	t_inbuf		buf;

	if (t == 'p')
		buf.u = va_arg(l, unsigned long long);
	else if (f->shrt == true || f->chr == true)
		buf.u = (unsigned long long)va_arg(l, int);
	else if (f->longint == true)
		buf.u = (unsigned long long)va_arg(l, unsigned long);
	else if (f->llong == true)
		buf.u = va_arg(l, unsigned long long);
	else if (f->j == true)
		buf.u = (unsigned long long)va_arg(l, uintmax_t);
	else if (f->z == true)
		buf.u = (unsigned long long)va_arg(l, size_t);
	else
		buf.u = (unsigned long)va_arg(l, unsigned long);
	f->inbuf = &buf;
	return (parse_u(t, b, f));
	return (0);
}
