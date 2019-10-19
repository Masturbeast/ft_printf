#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"
#include <limits.h>

int main()
{
    char *str;

    str = "Alex";
    //printf("%lu\n", n - fwidth);
    /*write(1, "salut ", 6);
    printf("%d", 42);
    write(1, "salut2 ", 5);*/
    ft_printf("%c\n", 'Q');
    printf("%c\n", 'Q');
    //printf("% 5.f\n", 2.71);
    //ft_printf("%d\n", 4242);
    //printf("%d\n", 4242);
    //write(1, "format", 2);
    //printf("% 010d", 42);
    return (0);
}

 //     - + # 0 espace
 // example : 4242.42424242