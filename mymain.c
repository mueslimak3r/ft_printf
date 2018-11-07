#include <stdio.h>

int     ft_printf(const char *format, ...);

int     main(void)
{
    ft_printf("oct: %-5s\n", "hello world!");
    return (0);
}