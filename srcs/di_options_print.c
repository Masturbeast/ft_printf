#include "ft_printf.h"

void    padding(int width, char c)
{
    int     i;

    i = 0;
    while (i < width)
    {
        ft_putchar(c);
        i++;
    }
}

int     is_prec(t_printf *pf)
{
    if (pf->prec)
        return (1);
    return (0);
}

int     is_neg_int(intmax_t nb)
{
    if (nb < 0)
        return (1);
    return (0);
}

void    di_options_print(t_printf *pf)
{
    int         twidth;
    uintmax_t   print;

    print = di_int_cast(pf);
    twidth = pf->width - ft_int_length(print);
    if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
    {
        ft_putnbr(print);
        padding(twidth, ' ');
    }
    else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || pf->opt_size & O_SPACE))
    {
        if (pf->opt_size & O_ZERO)
        {   
            if (pf->opt_size & O_SPACE)
            {    
                padding(1, ' ');
                twidth = twidth - 1;
            }
            padding(twidth, '0');
            ft_putnbr(print);
        }
        else
        {
            padding(twidth, ' ');
            ft_putnbr(print);
        }
    }
    else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
    {
        padding(1, ' ');
        ft_putnbr(print);
        padding(twidth - 1, ' ');
    }
    else
        ft_putnbr(print);
}