#include "libft.h"

char*       ft_strcase(char *str, char format)
{
    char    *ret;

    if (!str)
        return (NULL);
    ret = str;
    while (*str)
    {
        if (format >= 'a' && format <= 'z')
            *str = ft_toupper(*str);
        else
            *str = ft_tolower(*str);
        str++;
    }
    return (ret);
}