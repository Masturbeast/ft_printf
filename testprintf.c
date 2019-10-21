#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int main()
{   
    char *str;

    str = NULL;
    //ft_printf("%30s %-15s\n", str, "TEP");
    //printf("%30s\n", ft_itoa_base(42, 16));
    printf("%#.0f\n", 42.9532);
    /*printf("%d\n", 0x123);
    printf("%p\n", NULL);
    printf("%p\n", main);*/
}

 //     - + # 0 espace
 // example : 4242.42424242