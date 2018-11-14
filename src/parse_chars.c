#include "ft_printf.h"

size_t      justify_chars(t_buffer *buffer, t_flags *flags, int size, char type)
{
    size_t  ret;

    ret = 0;

    if (flags->min_len > size && (flags->zero == true) &&
        (flags->minus == false) && ((type == 'd' || type == 'i')))
        ret += ft_savechar(buffer, '0', flags->min_len - size);
    else if (flags->min_len > size)
        ret += ft_savechar(buffer, ' ', flags->min_len - size);
    return (ret);
}

size_t      parse_chars(char *data, int size, char type, t_buffer *buffer, t_flags *flags)
{
    size_t  ret;

    ret = 0;

    ret += !(flags->minus) ? (justify_chars(buffer, flags, size, type)) : 0;
    ret += (type == 's') ? ft_savestr(buffer, data, size) : (ft_savechar(buffer, *data, 1));
    ret += (flags->minus) ? (justify_chars(buffer, flags, size, type)) : 0;
    return (ret);
}

/*size_t      get_wchar(t_buffer *buffer, wchar_t c)
{
    char    b;
    int     i;
    int     size;

    i = 0;
    size = 0;
    if (c < 0xffff)
        size = (c < 0xff) ? 1 : 2;
    else
        size = (c < 0xffffff) ? 3 : 4;
    while (i < size)
    {
        b = (c & (0xff << (i * 8))) >> (i * 8);
        ft_savechar(buffer, b, 1);
        i++;
    }
    return (size);
}*/

size_t      parse_wchar(va_list list, t_buffer *buffer, t_flags *flags, char type)
{
    int     size;
    wchar_t *array;
    wchar_t single[2];
    int     i;

    i = 0;
    if (type == 'C' || (type == 'c' && flags->longint == true))
    {
        single[0] = (wchar_t)va_arg(list, wint_t);
        single[1] = 0;
        array = single;
    }
    else
        array = va_arg(list, wchar_t*);
    size = 0;
    while (array[i])
        size += get_wchar(buffer, array[i++]);
    return (size);
}

size_t      route_chars(va_list list, char type, t_buffer *buffer, t_flags *flags)
{
    char    *str;
    int     size;
    char    c;

    if (flags->longint || type == 'S' || type == 'C')
        return (parse_wchar(list, buffer, flags, type));
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