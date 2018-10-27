#include "ft_printf.h"

void        initflags(t_flags *flags)
{
    if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
        return ;
}

void        getflags(const char *format, int pos, t_flags *flags)
{
    initflags(flags);
    while (format[pos])
    {
    }
}