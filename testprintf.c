#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    /*write(1, "salut ", 6);
    printf("%d", 42);
    write(1, "salut2 ", 5);*/
    ft_printf("Je print %040.30ld en int\n", 2147483649);
    printf("Il print %040.30ld en int\n", 2147483649);
    //write(1, "format", 2);
    //rintf("% 010d", 42);
    return (0);
}