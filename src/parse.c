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
			c == 'p' || c == 'o' || c == 'u' || c == 'x' || c == '%' ||
				c == 'X')
		return (1);
	return (0);
}
