#include "libft.h"

long long                   ft_pow(long long a, long long b)
{
        long long           res;

        res = a;
        while (b-- > 0)
                res *= a;
        return (res);
}

char                        *ft_itoa_base(long long value, int base)
{
        char                *buffer;
        int                 buffsize;
        long                cpy;
        int                 mul;
        char                *alpha;

        alpha = "0123456789abcdefghijklmnopqrstuvwxyz";
        buffsize = 0;
        cpy = value;
        mul = 0;
        while (cpy >= (long long)base || cpy <= (long long)-base)
        {
                cpy /= base;
                mul++;
        }
        buffer = (char*)ft_memalloc(sizeof(char) * mul + 3);
        if (value < 0 && base == 10)
                buffer[buffsize++] = '-';
        while (mul-- > 0)
        {
                cpy = (value / ft_pow(base, mul) % base);
                buffer[buffsize++] = alpha[cpy < 0 ? -cpy : cpy];
        }
        buffer[buffsize++] = alpha[(value < 0 ? -value : value) % base];
        buffer[buffsize++] = '\0';
        return (buffer);
}