#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int main()
{   
    char *str;
    //unsigned long long a;
    int a;
    int *b;

    a = 9223;
    b = &a;
    str = "TEP";


    //ft_printf("%30s\n", "ABCDEFGHIJKLMNOP");
    //printf("%30s\n", ft_itoa_base(42, 16));
    //printf("%30s\n", "ABCDEFGHIJKLMNOP");
    //ft_printf("%#f\n", 42.965165);
    //printf("%s\n" ft_itoa_base(40bbfd, 8));
    //printf("%o\n", 40bbfd);
    //printf("\n");
    ft_printf("%.7f\n", 7.5);
    printf("%.7f\n", 7.5);
    
    //printf("\n");
    //printf("pf count is %d\n", printf("%+60.55d\n", 0));
    //printf("%p\n", main);
}
 //     - + # 0 espace
 // example : 4242.42424242ß
