#include "ft_printf.h"

size_t      justify_chars(t_buffer *buffer, t_flags *flags, int size)
{
    size_t  ret;

    ret = 0;

    if (flags->zero == true)
        ft_printf("flags-zero");
    if (flags->min_len > size && (flags->zero == true))
        ret += ft_savechar(buffer, '0', flags->min_len - size);
    else if (flags->min_len > size && (flags->zero == false))
        ret += ft_savechar(buffer, ' ', flags->min_len - size);
    return (ret);
}

size_t      parse_chars(char *data, int size, char type, t_buffer *buffer, t_flags *flags)
{
    size_t  ret;

    ret = 0;

    ret += !(flags->minus) ? (justify_chars(buffer, flags, size)) : 0;
    ret += (type == 's') ? ft_savestr(buffer, data, size) : (ft_savechar(buffer, *data, 1));
    ret += (flags->minus) ? (justify_chars(buffer, flags, size)) : 0;
    return (ret);
}

size_t      route_chars(va_list list, char type, t_buffer *buffer, t_flags *flags)
{
    char    *str;
    int     size;
    char    c;

    if (type == 's')
    {
        str = va_arg(list, char*);
        size = (flags->limit_size && flags->max_size < (int)ft_strlen(str))
            ? flags->max_size : (int)ft_strlen(str);
        return (parse_chars(str, size, type, buffer, flags));
    }
    else if (type == 'c')
    {
        c = (char)va_arg(list, int);
        return (parse_chars(&c, 1, type, buffer, flags));
    }
    return (0);
}