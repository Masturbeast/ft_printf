#include <stdio.h>
#include "ft_printf.h"

int main()
{
    t_printf pf;
   /* char c;
    int i;

    i = 0;
    c = 'e';
    pf.fmt = "hello";
    while (pf.fmt[i] != c)
        i++;
    if (pf.fmt[i] == c)
        pf.conv = pf.fmt[i];
    printf("%c\n", pf.conv);*/
    pf.fmt = "hd";
    //int_padding(&pf);
    if (arg_parser(&pf) == 1)
        printf("structure :\n opt_size = %d\n width = %d\n prec = %d\n conv = %c\n", pf.opt_size, pf.width, pf.prec, pf.conv);
    else
        printf("No conv msk");
    //printf("%d", 42);
    return (0);
} 