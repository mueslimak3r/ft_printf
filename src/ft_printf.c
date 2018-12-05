/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:24:06 by calamber          #+#    #+#             */
/*   Updated: 2018/11/30 16:24:17 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			parse(va_list l, char t, t_buffer *b, t_flags *f)
{
	size_t		ret;

	ret = 0;
	if (!f)
		return (0);
	if (t == '%')
		ret = ft_savechar(b, '%', 1);
	else if (t == 's' || t == 'c' || t == 'S')
		ret = route_chars(l, t, b, f);
	else if (t == 'd' || t == 'i')
		ret = route_d(l, b, f);
	else
		ret = route_u(l, t, b, f);
	return (ret);
}

size_t			checkf(va_list list, t_buffer *buffer, const char *format)
{
	size_t		ret;
	size_t		i;
	t_flags		flags;

	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = checkflags(format, ++i, &flags);
			if (!format[i])
				return (ret);
			if (isflag(format[i]) == 1)
				ret += parse(list, format[i], buffer, &flags);
		}
		else
			ret += ft_savechar(buffer, format[i], 1);
		if (format[i])
			i++;
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		list;
	size_t		ret;
	t_buffer	buffer;

	va_start(list, format);
	initbuffer(&buffer);
	ret = checkf(list, &buffer, format);
	va_end(list);
	if (buffer.chr)
	{
		write(1, buffer.chr, buffer.buf_usedchars);
		free(buffer.chr);
	}
	return ((int)ret);
}
