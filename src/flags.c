#include "ft_printf.h"

void			initflags(t_flags *flags)
{
	flags->chr = false;
	flags->shrt = false;
	flags->integer = false;
	flags->uinteger = false;
	flags->longint = false;
	flags->llong = false;
	flags->ulong = false;
	flags->ullong = false;
	flags->pound = false;
	flags->plus = false;
	flags->minus = false;
	flags->after_len = false;
	flags->before_len = false;
	flags->limit_size = false;
	flags->max_size = 0;
}

size_t			check_size(int index, const char *format, t_flags *flags)
{
	while ((format[index] >= '0') && (format[index] <= '9'))
	{
		flags->max_size *= 10;
		flags->max_size += (format[index] - '0');
		index++;
	}
	return (index);
}

size_t     		check_minus(size_t index, const char *format, t_flags *flags)
{
    flags->minus = true;
	while ((format[index] >= '0') && (format[index] <= '9'))
	{
		flags->after_len *= 10;
		flags->after_len += (format[index] - '0');
		index++;
	}
    return (index);
}

size_t			check_plusminus(size_t index, const char *format, t_flags *flags)
{
	if (format[index] == '-')
		return (check_minus(++index, format, flags));
	{
		while (format[index] == '0')
		{
			flags->zero = true;
			index++;
		}
		while ((format[index] >= '0') && (format[index] <= '9'))
		{
			flags->before_len *= 10;
			flags->before_len += (format[index] - '0');
			index++;
		}
	}
	return (index);
}

size_t			checkflags(const char *format, size_t index, t_flags *flags)
{
	initflags(flags);
	while (format[index] && (isflag(format[index]) == 0))
	{
		if (format[index] == '#')
			flags->pound = true;
		else if (format[index] == '+')
			flags->plus = true;
		else if ((format[index] == '-') || format[index] == '.' || ft_isdigit(format[index]))
			index = check_plusminus(index, format, flags);
		else if (format[index] == 'l' && format[index + 1] != 'l')
			flags->longint = true;
		if (!(isflag(format[index])))
			index++;
	}
	return (index);
}