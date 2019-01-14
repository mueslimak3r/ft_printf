#include <stdio.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

int     ft_printf(const char *format, ...);

int     main(void)
{
/*
    char    *str;
    wchar_t warray[2] = {0x1f984, 0};
    int     ret;

    ret = 0;
    setlocale(LC_ALL, "");
    str = "Hello World!";
    ret = ft_printf("str: %020.7s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);

    ret = printf("ref: %-20.7s %s c: %c-end-\n", "hello world!", " string2", 'c');
    ft_printf("ret: %d\n", ret);

    ret = ft_printf("str: %-20p-end-\n", INT_MAX);
    ft_printf("ret: %d\n", ret);
    ret = printf("ref: %+-20d-end-\n", INT_MAX);
    ft_printf("ret: %d\n", ret);

    ret = ft_printf("mine: %ls\n", warray);
    ft_printf("ret: %d\n", ret);
    ret = printf("ref:: %ls\n", warray);
    ft_printf("ret: %d\n", ret);


    double db = 3.9;
    ret = ft_printf("mine: %f\n", db);
    ft_printf("ret: %d\n", ret);
    ret = printf("ref:: %lf\n", db);
    ft_printf("ret: %d\n", ret);

    printf ("part 2\n");

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
    
    ft_printf("|%+04.15d|\n", 42);
    printf("|%+04.15d|\n", 42);

    ft_printf("@moulitest: a%5.xb a%5.0xb-\n", 0, 0);
    printf("@moulitest: a%5.xb a%5.0xb-\n", 0, 0);
    ft_printf("@moulitest: a%5.xb a%5.0xb-\n", 42, 42);
    printf("@moulitest: a%5.xb a%5.0xb-\n", 42, 42);
    ft_printf("data: %c", 0);

    ft_printf("data:%+10.4d-\n", 56);
    printf("data:%+10.4d-\n", 56);
    ft_printf("data:%10.4d-\n", 56);
    printf("data:%10.4d-\n", 56);

    ft_printf("data:%-10.4d-\n", 56);
    printf("data:%-10.4d-\n", 56);

    ft_printf("%-6o-\n", 2500);
    printf("%-6o-\n", 2500);
    //ft_printf("%-#6o", 2500);
*/

    ft_printf("@moulitest: -%-10.9d-\n", -42);
    printf("@moulitest: -%-10.9d-\n", -42);

    //long long ii = -9223372036854775808;

    char w = 'w';
    ft_printf("%ld\n", LONG_MAX);
    printf("%ld\n", LONG_MAX);
    ft_printf("%zd\n", 4294967295);
    printf("%zd\n", 4294967295);

    ft_printf("%hhd\n", w);
    printf("%hhd\n", w);

    ft_printf("@moulitest: [%.o] [%.0o]--\n", 42, 43);
    printf("@moulitest: [%.o] [%.0o]--\n", 42, 43);

    ft_printf("@moulitest: [%5.o] [%5.0o]--\n", 0, 0);
    printf("@moulitest: [%5.o] [%5.0o]--\n", 0, 0);

    ft_printf("%-5.10o-\n", 2500);
    printf("%-5.10o-\n", 2500);

    ft_printf("%+10.5d-\n", 4242);
    printf("%+10.5d-\n", 4242);

    ft_printf("%0+5d--\n", 42);
    printf("%0+5d--\n", 42);

    ft_printf("@moulitest: %.10d-\n", -42);
    printf("@moulitest: %.10d-\n", -42);

    ft_printf("@moulitest: %#.o %#.0o-\n", 0, 0);
    printf("@moulitest: %#.o %#.0o-\n", 0, 0);

    ft_printf("@moulitest: %.o %.0o-\n", 0, 0);
    printf("@moulitest: %.o %.0o-\n", 0, 0);

    ft_printf("{%+03d}-\n", 1);
    printf("{%+03d}-\n", 1);

    ft_printf("{%+03d}\n", 0);
    printf("{%+03d}\n", 0);
    return (0);
}
