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
}

size_t			checkflags(const char *format, t_flags *flags)
{
	size_t		i;

	i = 0;
	if (format)
	{
		initflags(flags);
		i = parseflags(flags);
	}
	return (i);
}