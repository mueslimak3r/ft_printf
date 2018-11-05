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

size_t		getint(va_list list, t_buffer *buffer)
{
	size_t	ret;
	int		nbr;

	ret = 0;
	nbr = va_arg(list, int);
	if (nbr < 0)
	{
		ret += ft_savechar(buffer, '-', 1);
		if (nbr == -2147483648)
			return (ret + ft_savestr(buffer, "2147483648"));
		nbr = -nbr;
	}
	ret += usenbr(buffer, 'd', nbr, 10);
	return (ret);
}

size_t		parse(va_list list, char type, t_buffer *buffer)
{
	size_t	ret;

	ret = 0;
	if (type == 's')
		ret = ft_savestr(buffer, va_arg(list, char*));
	else if (type == '%')
		ret = ft_savechar(buffer, '%', 1);
	else if (type == 'c')
		ret = ft_savechar(buffer, (char)va_arg(list, int), 1);
	else if (type == 'd' || type == 'i')
		ret = getint(list, buffer);
	else if (type == 'p')
		ret = usenbr(buffer, type, va_arg(list, unsigned long long), 16);
	else
		return (parse_u(list, type, buffer));
	return (ret);
}

int			findnext(const char *format, int pos)
{
	while (format[pos])
	{
		if (ischar(format[pos]))
			return (pos);
		else if (format[pos] == '%')
			return (pos);
		pos++;
	}
	return (pos);
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
	i = checkflags(format, &flags);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = findnext(format, ++i);
			if (!format[i])
				return (ret);
			if ((isflag(format[i]) == 1) || format[i] == '%')
				ret += parse(list, format[i], &buffer);
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
