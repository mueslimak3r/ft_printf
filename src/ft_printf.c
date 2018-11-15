/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:24:06 by calamber          #+#    #+#             */
/*   Updated: 2018/10/01 22:03:39 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		parse(va_list list, char type, t_buffer *buffer, t_flags *flags)
{
	size_t	ret;

	ret = 0;
	if (!flags)
		return (0);
	if (type == '%')
		ret = ft_savechar(buffer, '%', 1);
	else if (type == 's' || type == 'c' || type == 'S')
		ret = route_chars(list, type, buffer, flags);
	else if (type == 'd' || type == 'i' )
		ret = route_d(list, buffer, flags);
	else if (type == 'f')
		ret = route_f(list, buffer, flags);
	else
		ret = route_u(list, type, buffer, flags);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list 	list;
	size_t		ret;
	size_t		i;
	t_buffer	buffer;
	t_flags		flags;

	ret = 0;
	va_start(list, format);
	initbuffer(&buffer);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = checkflags(format, ++i, &flags);
			if (!format[i])
				return (ret);
			if (isflag(format[i]) == 1)
				ret += parse(list, format[i], &buffer, &flags);
		}
		else
			ret += ft_savechar(&buffer, format[i], 1);
		if (format[i])
			i++;
	}
	va_end(list);
	if (buffer.chr)
	{
		write(1, buffer.chr, buffer.buf_usedchars);
		free(buffer.chr);
	}
	return ((int)ret);
}
