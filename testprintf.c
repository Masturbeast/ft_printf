#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
    /*write(1, "salut ", 6);
    printf("%d", 42);
    write(1, "salut2 ", 5);*/
    ft_printf("test ft_printf float: %.0f\n", 42.1516);
    printf("test printf float: %.0f\n", 42.1516);
    //write(1, "format", 2);
    //rintf("% 010d", 42);
    return (0);
}