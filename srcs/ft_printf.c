#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    t_printf pf; 

    pf.fmt = (char *)format;
    va_start(pf.args, format);
    while (*pf.fmt != '\0')
    {
        if (*pf.fmt == '%' && pf.fmt++)
        {
            if (arg_parser(&pf) == 1)
            {   
                di_options_print(&pf);
            }
        }
        if (*pf.fmt == '\0')
            return (0);
        else
        {
            ft_putchar(*pf.fmt);
            pf.fmt++;
        }
    }
    va_end(pf.args);
    return(0);
}