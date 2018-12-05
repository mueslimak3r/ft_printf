/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:05:32 by calamber          #+#    #+#             */
/*   Updated: 2018/11/30 16:06:46 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			parse_d(t_buffer *buffer, t_flags *flags)
{
	int			size;
	char		*str;
	int			ret;

	str = ft_itoa_base(flags->inbuf->s, 10);
	size = (int)ft_strlen(str) + flags->plus;
	ret = !(flags->minus) ? (justify_chars(buffer, flags, size, 'd')) : 0;
	if (flags->inbuf->s > 0 && flags->plus)
		ret += ft_savechar(buffer, '+', 1);
	ft_savestr(buffer, str, (int)ft_strlen(str));
	ret += (flags->minus) ? (justify_chars(buffer, flags, size, 'd')) : 0;
	flags->inbuf->s = 0;
	return (ret);
}

size_t			route_d(va_list list, t_buffer *buffer, t_flags *flags)
{
	t_inbuf		buf;

	if (flags->longint == true)
		buf.s = (long long)va_arg(list, long);
	else if (flags->llong == true)
		buf.s = va_arg(list, long long);
	else if (flags->j == true)
		buf.s = (long long)va_arg(list, intmax_t);
	else if (flags->z == true)
		buf.s = (long long)va_arg(list, ssize_t);
	else
		buf.s = (long long)va_arg(list, int);
	flags->inbuf = &buf;
	return (parse_d(buffer, flags));
}
