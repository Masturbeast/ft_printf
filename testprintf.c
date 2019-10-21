#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int main()
{   
    char *str;
    unsigned long long a;

    a = 9223372036854775807;
    str = NULL;
    //ft_printf("%30s\n", "ABCDEFGHIJKLMNOP");
    //printf("%30s\n", ft_itoa_base(42, 16));
    //printf("%30s\n", "ABCDEFGHIJKLMNOP");
    //ft_printf("%#f\n", 42.965165);
    //printf("%s\n", ft_itoa_base(40bbfd, 8));
    //printf("%o\n", 40bbfd);
    ft_printf("%%%d ferfref%f\n", 10, 42.42);
    printf("%%%d ferfref%f\n", 10, 42.42);
    //printf("%p\n", main);
}
 //     - + # 0 espace
 // example : 4242.42424242