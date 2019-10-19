#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"
#include <limits.h>

int main()
{
    char *str;
    int a;
    int *b;

    a = 69;
    b = &a;
    str = "A";
    char const *p = "hello";

    ft_printf("%-30p\n", p);
    printf("%-30p\n", p);
    /*printf("%d\n", 0x123);
    printf("%p\n", NULL);
    printf("%p\n", main);*/
}

 //     - + # 0 espace
 // example : 4242.42424242