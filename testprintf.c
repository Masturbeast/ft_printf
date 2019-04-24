#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    /*write(1, "salut ", 6);
    printf("%d", 42);
    write(1, "salut2 ", 5);*/
    ft_printf("%-17hhd\n", -313018768);
    printf("%-17hhd\n", -313018768);
    //write(1, "format", 2);
    //rintf("% 010d", 42);
    return (0);
}