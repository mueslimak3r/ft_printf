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

size_t			justify_d(t_buffer *b, t_flags *f, int size, int pos)
{
	size_t		ret;

	ret = 0;
	if (pos == 0)
	{
		if (f->min_len > size && f->min_len > f->max_size && f->max_size > 0 && f->minus == false)
			ret += ft_savechar(b, ' ', (f->min_len - f->max_size));
		else if (f->min_len > size && f->minus == false && (!((f->max_size > -1) || (f->zero))))
			ret += ft_savechar(b, ' ', (f->min_len - size));
		if (f->space && !(f->min_len > size && f->max_size < f->min_len))
			ret += ft_savechar(b, ' ', 1);
		if ((f->zero == false) && f->max_size > size)
			ret += (f->max_size > -1) ? ft_savechar(b, '0', (f->max_size - size)) : ft_savechar(b, '0', (f->min_len - size));
		else if (f->zero == true && ((f->max_size > -1 && f->max_size > size) || (f->min_len > size && f->max_size == -1)))
			ret += (f->max_size > -1 && f->max_size > size) ? ft_savechar(b, '0', (f->max_size - size)) : ft_savechar(b, '0', (f->min_len - size));
	}
	else if (pos == 1)
	{
		if (f->min_len > size && f->min_len > f->max_size && f->max_size > 0 && f->minus == true)
			ret += ft_savechar(b, ' ', (f->min_len - f->max_size));
		else if (f->min_len > size && !(f->min_len > f->max_size && f->max_size > 0) && f->minus == true)
			ret += ft_savechar(b, ' ', (f->min_len - size));
	}
	return (ret);
}

size_t			parse_d(t_buffer *buffer, t_flags *flags)
{
	int			size;
	char		*str;
	int			ret;

	ret = 0;
	str = ft_itoa_base(flags->inbuf->s, 10);
	flags->space = (flags->space == 1 && flags->inbuf->s > 0) ? 1 : 0;
	size = (int)ft_strlen(str);
	if (flags->inbuf->s > 0 && flags->plus)
	{
		ret += ft_savechar(buffer, '+', 1);
	}
	//printf("space: %d size: %d width: %d precision: %d\n", flags->space, size, flags->min_len, flags->max_size);
	ret += justify_d(buffer, flags, size, 0);
	ft_savestr(buffer, str, (int)ft_strlen(str));
	ret += justify_d(buffer, flags, size, 1);
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
