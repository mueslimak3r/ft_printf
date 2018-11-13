#include <stdio.h>
#include <limits.h>

int     ft_printf(const char *format, ...);

int     main(void)
{
    char    *str;

    str = "Hello World!";
    ft_printf("str: %20s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("str: %-20s %s c: %c-end-\n", "hello world!", " string2", 'c');

    ft_printf("str: %020.7s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("str: %-20.7s %s c: %c-end-\n", "hello world!", " string2", 'c');
    printf("str: %20.7s %s c: %c-end-\n", "hello world!", " string2", 'c');

    ft_printf("mine: %llX-end-\n", (unsigned long long)str);
    ft_printf("mine: %llX-end-\n", (unsigned long long)str);
    ft_printf("mine: %-9d-end-\n", 19999);
    printf("ref:: %-9d-end-\n", 19999);

    ft_printf("mine: %-20p-end-\n", str);
    printf("ref:: %-20p-end-\n", str);

    ft_printf("mine: %+-20d-end-\n", INT_MAX);
    printf("ref:: %+-20d-end-\n", INT_MAX);
    return (0);
}
