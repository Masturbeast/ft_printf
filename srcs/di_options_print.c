#include "ft_printf.h"

void    minus_padding(int width)
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
    int t_width;

    t_width = 
    if (pf->opt_size & O_MINUS)
    {
        ft_putnbr();
        minus_padding();
    }
}