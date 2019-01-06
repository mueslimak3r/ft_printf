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

    ft_printf("|% 3d|\n", 42);
    printf("|% 3d|\n", 42);

    ft_printf("|% 5d|\n", 42);
    printf("|% 5d|\n", 42);

    ft_printf("|%+04d|\n", 42);
    printf("|%+04d|\n", 42);

    ft_printf("|% 4.5i|\n", 42);
    printf("|% 4.5i|\n", 42);

    ft_printf("m: |%4.2i|\n", 42);
    printf("r: |%4.2i|\n", 42);

    ft_printf("m: |%4.3i|\n", 42);
    printf("r: |%4.3i|\n", 42);

    ft_printf("|% 4.5i|\n", 42);
    printf("|% 4.5i|\n", 42);

    ft_printf("|%-5.3d|\n", 42);
    printf("|%-5.3d|\n", 42);

    ft_printf("|% 4.5i|\n", 42);
    printf("|% 4.5i|\n", 42);

    ft_printf("|% 06.4i|\n", 42);
    printf("|% 06.4i|\n", 42);

    ft_printf("|%04.3i|\n", 42);
    printf("|%04.3i|\n", 42);

    ft_printf("|% 04.2i|\n", 42);
    printf("|% 04.2i|\n", 42);

    ft_printf("|%-5.3s|\n", "LYDI");
    printf("|%-5.3s|\n", "LYDI");

    ft_printf("|%04d|\n", 42);
    printf("|%04d|\n", 42);

    ft_printf("|%05d|\n", 42);
    printf("|%05d|\n", 42);

    ft_printf("|% 4d|\n", 42);
    printf("|% 4d|\n", 42);   

    ft_printf("|%+04d|\n", 42);
    printf("|%+04d|\n", 42);   
    
    ft_printf("|%+04.15x|\n", 42);
    printf("|%+04.15x|\n", 42);

    char* str = "hello";

    ft_printf("%#20o!\n", &str);
    printf("%#20o!\n", &str);
*/
    ft_printf("%-#6o", 2500);
    return (0);
}
