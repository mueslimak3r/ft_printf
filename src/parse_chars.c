#include "ft_printf.h"

size_t      justify_chars(t_buffer *buffer, t_flags *flags, size_t size, int pos)
{
    size_t  ret;

    ret = 0;
    if (pos == 1 || size || buffer)
    {
        return (ret);
    }
    else if (pos == 2 || flags)
    {
        return (ret);
    }
    return (ret);
}

size_t      parse_chars(va_list list, char type, t_buffer *buffer, t_flags *flags)
{
    size_t  ret;
    char    *str;
    char    c;
    size_t  size;

    str = NULL;
    c = 0;
    ret = 0;
    if (type == 's')
        str = va_arg(list, char*);
    else if (type == 'c')
        c = (char)va_arg(list, int);
    size = (type == 'c') ? 1 : ft_strlen(str);
    ret += justify_chars(buffer, flags, size, 1);
    if (flags->limit_size && type == 'c' && flags->max_size > 0)
        ret += ft_savechar(buffer, c, 1);
    else
    {
        if (type == 'c')
            ret += ft_savechar(buffer, c, 1);
        else if (type == 's')
	        ret += ft_savestr(buffer, str, size);
    }
    ret += justify_chars(buffer, flags, size, 2);
    return (ret);
}