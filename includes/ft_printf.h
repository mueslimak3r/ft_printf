/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:23:09 by calamber          #+#    #+#             */
/*   Updated: 2018/10/01 22:04:52 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include "../libft/libft.h"

typedef struct				s_buffer
{
	char					*chr;
	int						buf_charsize;
	int						buf_usedchars;
}							t_buffer;

typedef struct				s_inbuf
{
	unsigned long long		u;
	long long int			s;
	long double				f;
}							t_inbuf;

typedef struct				s_flags
{
	bool					chr;
	bool					shrt;
	bool					longint;
	bool					llong;
	bool					L;
	bool					j;
	bool					z;
	int						pound;
	int						plus;
	bool					minus;
	bool					zero;
	bool					limit_size;
	int						max_size;
	int						min_len;
	t_inbuf					*inbuf;
}							t_flags;

int			ft_printf(const char *format, ...);

void		initbuffer(t_buffer *buffer);
void		initflags(t_flags *flags);
size_t		checkflags(const char *format, size_t pos, t_flags *flags);

size_t		parse(va_list list, char type, t_buffer *buffer, t_flags *flags);
size_t      route_chars(va_list list, char type, t_buffer *buffer, t_flags *flags);
size_t		usenbr(t_flags *flags, t_buffer *buffer, char type, int base);
size_t     	route_u(va_list list, char type, t_buffer *buffer, t_flags *flags);
size_t      route_d(va_list list, t_buffer *buffer, t_flags *flags);
size_t		route_f(va_list list, t_buffer *buffer, t_flags *flags);

int			ft_savechar(t_buffer *buffer, char s, int repeat);
int			ft_savestr(t_buffer *buffer, char *s, int size);

char		*uitoa_base(unsigned long long nbr, int base);
char		*ft_ftoa(float f, int size);
size_t		get_wchar(t_buffer *buffer, wchar_t wc);

size_t      justify_chars(t_buffer *buffer, t_flags *flags, int size, char type);
int			ischar(char c);
int			isflag(char c);

#endif
