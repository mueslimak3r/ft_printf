#include "ft_printf.h"

size_t      justify_chars(t_buffer *buffer, t_flags *flags, int size)
{
    size_t  ret;

    ret = 0;
    if (flags->min_len > size)
        ret += ft_savechar(buffer, ' ', flags->min_len - size);
    return (ret);
}

size_t      parse_chars(va_list list, char type, t_buffer *buffer, t_flags *flags)
{
    size_t  ret;
    char    *str;
    char    c;
    size_t  size;

    c = 0;
    ret = 0;
    ret += !(flags->minus) ? (justify_chars(buffer, flags, size)) : 0;
    if (type == 's')
    {
        str = va_arg(list, char*);
        size = (flags->limit_size && flags->max_size < (int)ft_strlen(str))
            ? flags->max_size : (int)ft_strlen(str);
        ret += ft_savestr(buffer, str, size);
    }
    else if (type == 'c')
        c = (char)va_arg(list, int);
    if (type == 'c' && (!(flags->limit_size) || flags->max_size > 0))
        ret += ft_savechar(buffer, c, 1);
    ret += !(flags->minus) ? 0 : (justify_chars(buffer, flags, size));
    return (ret);
}