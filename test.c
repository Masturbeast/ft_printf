#include <stdio.h>
#include "ft_printf.h"

int main()
{
    t_printf pf;
    /*char c;
    int i;

    i = 0;
    c = 'e';
    pf.fmt = "hello";
    while (pf.fmt[i] != c)
        i++;
    if (pf.fmt[i] == c)
        pf.conv = pf.fmt[i];
    printf("%c\n", pf.conv);*/
    pf.fmt = "-#5hc";
    printf("%d\n", pf.prec);
    opt_check(&pf);
    width_check(&pf);
    prec_check(&pf);
    size_check(&pf);
    conv_check(&pf);
    printf("structure :\n optsize = %d\n width = %d\n prec = %d\n conv = %c\n", pf.opt_size, pf.width, pf.prec, pf.conv);
    return (0);
}