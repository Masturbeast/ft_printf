#include "ft_printf.h"

int     ft_printf(const char *fmt, ...)
{
    t_printf pf; 

    pf.fmt = (char *)fmt;
    //va_start(pf.args, fmt);
    while (*pf.fmt != '\0')
    {
        if (*pf.fmt == '%' && pf.fmt++)
        {
            if (arg_parser(&pf) == 1)
            {
                if (*pf.fmt != '%' || *pf.fmt != '\0')
                {
                    pf.fmt++;
                }
            }
        }
        ft_putchar(*pf.fmt);
        pf.fmt++;
    }
    //va_end(pf.args);
    return(0);
}