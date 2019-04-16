#include "ft_printf.h"

int     ft_printf(const char *fmt, ...)
{
    t_printf pf; 

    pf.fmt = (char *)fmt;

    va_start(pf.args, fmt);
    if (*pf.fmt == '%' && pf.fmt++)
    {
        if (arg_parser(&pf) == 1)
        {
            if (pf.conv)
            {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                printf("%ld\n", di_int_cast(&pf));
                //printf("%hhd\n", n);
            }
        }
    }
    va_end(pf.args);
    return(0);
}