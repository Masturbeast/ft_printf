#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    //printf("%lu\n", n - fwidth);
    /*write(1, "salut ", 6);
    printf("%d", 42);
    write(1, "salut2 ", 5);*/
    ft_printf("%+050.8f\n", 4242.15125616);
    printf("%+050.8f\n", 4242.15125616);
    //write(1, "format", 2);
    //rintf("% 010d", 42);
    return (0);
}