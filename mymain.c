#include <stdio.h>

int     ft_printf(const char *format, ...);

int     main(void)
{
    ft_printf("str: %20s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("str: %-20s %s c: %c-end-\n", "hello world!", " string2", 'c');

    ft_printf("str: %020.7s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("str: %-20.7s %s c: %c-end-\n", "hello world!", " string2", 'c');

    ft_printf("oct: %o %o\n", 56, 0);
    return (0);
}