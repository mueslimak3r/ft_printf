#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

int     ft_printf(const char *format, ...);

int     main(void)
{
    /*char    *str;
    wchar_t warray[2] = {0x1f984, 0};
    int     ret;

    ret = 0;
    setlocale(LC_ALL, "");
    str = "Hello World!";
    ret = ft_printf("str: %20s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);
    ret = printf("ref: %20s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);
    ret = ft_printf("str: %-20s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);
    ret = printf("ref: %-20s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);

    ret = ft_printf("str: %020.7s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);
    ret = ft_printf("str: %-20.7s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);

    ret = ft_printf("mine: %llX-end-\n", (unsigned long long)str);
    ft_printf("ret: %d\n", ret);
    ret = ft_printf("mine: %llX-end-\n", (unsigned long long)str);
    ft_printf("ret: %d\n", ret);
    ret = ft_printf("mine: %-9d-end-\n", 19999);
    ft_printf("ret: %d\n", ret);
    ret = ft_printf("mine: %-20p-end-\n", str);
    ft_printf("ret: %d\n", ret);
    ret = ft_printf("mine: %+-20d-end-\n", INT_MAX);
    ft_printf("ret: %d\n", ret);

    ret = ft_printf("mine: %ls\n", warray);
    ft_printf("ret: %d\n", ret);
    ret = printf("ref:: %ls\n", warray);
    ft_printf("ret: %d\n", ret);
    wchar_t single = 0x1f984;
    ret = ft_printf("mine: %lc\n", single);
    ft_printf("ret: %d\n", ret);
    ret = printf("ref:: %lc\n", single);
    ft_printf("ret: %d\n", ret);

    double db = 3.9;
    ret = ft_printf("mine: %f\n", db);
    ft_printf("ret: %d\n", ret);
    ret = printf("ref:: %lf\n", db);
    ft_printf("ret: %d\n", ret);
*/
    ft_printf("%4.5d\n", 42);
    printf("%4.5d\n", 42);
    return (0);
}
