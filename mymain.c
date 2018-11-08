#include <stdio.h>

int     ft_printf(const char *format, ...);

int     main(void)
{
    ft_printf("oct: %20s-end-\n", "hello world!");
    ft_printf("oct: %-20s-end-\n", "hello world!");

    ft_printf("oct: %20.7s-end-\n", "hello world!");
    ft_printf("oct: %-20.7s-end-\n", "hello world!");
    return (0);
}