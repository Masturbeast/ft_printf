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

char    *int_options()