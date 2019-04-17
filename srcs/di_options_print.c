#include "ft_printf.h"

void    padding(int width)
{
    int     i;

    i = 0;
    while (i < width)
    {
        ft_putchar(' ');
        i++;
    }
}

void    di_options_print(t_printf *pf)
{
    int         twidth;
    uintmax_t   print;

    print = di_int_cast(pf);
    twidth = pf->width - ft_int_length(print);
    if (pf->opt_size & O_MINUS)
    {
        ft_putnbr(print);
        padding(twidth);
    }
    if (pf->opt_size & O_SPACE)
    {
        padding(twidth);
        ft_putnbr(print);
    }
}