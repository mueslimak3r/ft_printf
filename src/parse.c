/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:28:25 by calamber          #+#    #+#             */
/*   Updated: 2018/10/01 22:03:58 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ischar(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int			isflag(char c)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'i' ||
			c == 'p' || c == 'o' || c == 'u' || c == 'x')
		return (1);
	return (0);
}

size_t		usenbr(t_buffer *buffer, char type, unsigned long long nbr, int base)
{
	size_t	ret;
	char	*str;

	ret = 0;
	str = uitoa_base(nbr, base);
	if (str)
	{
		if (type == 'p')
			ret += ft_savestr(buffer, "0x");
		ret += ft_savestr(buffer, str);
		free(str);
	}
	return (ret);
}
