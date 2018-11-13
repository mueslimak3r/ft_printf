#include "ft_printf.h"

int                                fround(double x)
{
        if (x < 0)
                return (int)(x - 0.5);
        else
                return (int)(x + 0.5);
}

char                                *ft_ftoa(float f, int size)
{
        int integer = (int)f;
        float flt = f - (float)integer;
        char *buff = ft_itoa(integer);
        char *newbuff = 0;
        int length = 0;
        newbuff = ft_expandwrite(buff, ft_strlen(buff), newbuff, &length);
        free(buff);
        if (size > 0)
        {
                newbuff = ft_expandwrite(".", 1, newbuff, &length);
                while (size--)
                        flt *= (10);
                buff = ft_itoa(fround((double)flt));
                newbuff = ft_expandwrite(buff, ft_strlen(buff) + 1, newbuff, &length);
        }
        return (newbuff);
}

size_t          parse_f(t_buffer *buffer, t_flags *flags)
{
    size_t      ret;
    char        *str;
    t_inbuf     buf;

    ret = 0;

    str = ft_ftoa();
    return (ret);
}

size_t          route_f(va_list list, t_buffer *buffer, t_flags *flags)
{
    t_inbuf     buf;

    if (flags->L == true)
        buf.f = va_arg(list, long double);
	else
		buf.f = (long double)va_arg(list, double);
	flags->inbuf = &buf;
    return (parse_f(buffer, flags));
}
