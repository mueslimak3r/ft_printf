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

size_t			justify2(t_buffer *b, t_flags *f, char t, int s)
{
	size_t		ret;

	ret = 0;
	ret += (f->plus && (t == 'd' || t == 'i')) ? ft_savechar(b, '+', 1) : 0;
	ret += (f->isneg && (t == 'd' || t == 'i')) ? ft_savechar(b, '-', 1) : 0;
	if (t == 'p' || ((t == 'x' || t == 'X') && f->pound))
		ret += (ft_isupper(t)) ? ft_savestr(b, "0X", -1)
			: ft_savestr(b, "0x", -1);
	if ((f->zero == false) && f->max_size > s)
		ret += ft_savechar(b, '0', (f->max_size - s + f->plus));
	else if (f->zero == true && (f->max_size > s || (f->min_len > s && !f->minus)))
		ret += (f->max_size > s) ? ft_savechar(b, '0', (f->max_size - s + f->plus)) : ft_savechar(b, '0', (f->min_len - s + f->plus));
	return (ret);
}

size_t			justify_d(t_buffer *b, t_flags *f, char t, int s, int p)
{
	size_t		ret;

	ret = 0;
	if (p == 0)
	{
		if (f->min_len > s && f->min_len > f->max_size && f->max_size > s && f->minus == false)
			ret += ft_savechar(b, ' ', (f->min_len - f->max_size - f->plus));
		else if (f->min_len > s && f->minus == false && (!((f->max_size > s) || (f->zero))))
			ret += ft_savechar(b, ' ', (f->min_len - s - f->plus));
		if (f->space && !(f->min_len > s && f->max_size < f->min_len) && (t == 'd' || t == 'i'))
			ret += ft_savechar(b, ' ', 1);
		ret += justify2(b, f, t, s);
	}
	else if (p == 1)
	{
		if (f->min_len > s && f->min_len > f->max_size && f->max_size > 0 && f->minus == true)
			ret += ft_savechar(b, ' ', (f->min_len - f->max_size - f->plus));
		else if (f->min_len > s && !(f->min_len > f->max_size && f->max_size > 0) && f->minus == true)
			ret += ft_savechar(b, ' ', (f->min_len - s) - f->plus);
	}
	return (ret);
}

// (f->max_size > f->min_len && f->min_len > 0) ? 
//  : ft_savechar(b, ' ', (f->min_len - s))

size_t			parse_d(t_buffer *b, t_flags *f)
{
	int			size;
	char		*str;
	int			ret;

	ret = 0;
	str = ft_itoa_base(f->inbuf->s, 10);
	f->space = (f->space && !f->plus && f->inbuf->s > 0) ? 1 : 0;
	size = (f->isneg) ? (int)ft_strlen(str) - 1 : (int)ft_strlen(str);
	f->plus = (f->inbuf->s >= 0 && f->plus) ? 1 : 0; 
	ret += justify_d(b, f, 'd', size, 0);
	ret += (f->max_size == 0 || (f->l_size && f->max_size == -1)) ? 0 : ft_savestr(b, str + f->isneg, (int)ft_strlen(str));
	ret += justify_d(b, f, 'd', size, 1);
	f->inbuf->s = 0;
	free (str);
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
	flags->isneg = (buf.s < 0) ? 1 : 0;
	flags->inbuf = &buf;
	return (parse_d(buffer, flags));
}
