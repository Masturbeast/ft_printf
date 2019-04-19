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
            else
                return (0);
        }
        ft_putchar(*pf.fmt);
        if (*pf.fmt != '\0')
            pf.fmt++;
        if (*pf.fmt == '\0')
            return (0);
    }
    va_end(pf.args);
    return(0);
}