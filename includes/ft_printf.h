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
# include "../libft/libft.h"

typedef struct				s_buffer
{
	char					*chr;
	int						buf_charsize;
	int						buf_usedchars;
}							t_buffer;

typedef struct				s_flags
{
	int 					f_long;
	int						f_llong;
	int						f_ulong;
	int						u_llong;
	int						chr;
	int						shrt;
}							t_flags;

size_t		parse(va_list list, char type, t_buffer *buffer);
int			ft_printf(const char *format, ...);
int			print_addr(char *addr);
char		*uitoa_base(unsigned long long nbr, int base);
int			isflag(char c);
size_t		usenbr(t_buffer *buffer, char type, unsigned long long nbr, int base);
int			ischar(char c);
int			ft_savechar(t_buffer *buffer, char s, int repeat);
int			ft_savestr(t_buffer *buffer, char *s);
void		initbuffer(t_buffer *buffer);
int     	parse_u(va_list list, char type, t_buffer *buffer);

#endif
