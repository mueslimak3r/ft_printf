#include "ft_printf.h"

void			initflags(t_flags *flags)
{
	flags->chr = false;
	flags->shrt = false;
	flags->longint = false;
	flags->llong = false;
	flags->L = false;
	flags->j = false;
	flags->z = false;
	flags->pound = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->minus = false;
	flags->min_len = false;
	flags->limit_size = false;
	flags->max_size = 0;
	flags->inbuf = NULL;
}

size_t			check_size(int index, const char *format, t_flags *flags)
{
	while ((format[index] >= '0') && (format[index] <= '9'))
	{
		flags->limit_size = true;
		flags->max_size *= 10;
		flags->max_size += (format[index] - '0');
		index++;
	}
	return (index);
}

size_t			check_plusminus(size_t index, const char *format, t_flags *flags)
{
	if (format[index] == '-')
	{
		flags->minus = true;
		index++;
	}
	if (format[index] == '.')
		index = check_size(++index, format,flags);
	else if (format[index] == '0' && !(ft_isdigit(format[index - 1])))
	{
		flags->zero = true;
		index++;
	}
	while ((format[index] >= '0') && (format[index] <= '9'))
	{
		flags->min_len *= 10;
		flags->min_len += (format[index] - '0');
		index++;
	}
	if (format[index] == '.')
		index = check_size(++index, format,flags);
	return (index);
}

size_t			checkflags(const char *format, size_t index, t_flags *flags)
{
	initflags(flags);
	while (format[index] && (isflag(format[index]) == 0))
	{
		if (format[index] == '#')
			flags->pound = 2;
		else if (format[index] == ' ')
			flags->space = 1;
		else if (format[index] == '+')
			flags->plus = 1;
		else if (format[index] == 'L')
			flags->L = true;
		else if ((format[index] == '-') || format[index] == '.' || ft_isdigit(format[index]))
			index = check_plusminus(index, format, flags);
		else if (format[index] == 'l' && format[index + 1] != 'l')
			flags->longint = true;
		if (!(isflag(format[index])))
			index++;
	}
	return (index);
}