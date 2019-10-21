#include "ft_printf.h"

void	reset_struct(t_printf *pf)
{
	pf->opt_size = 0;
	pf->prec = 0;
	pf->width = 0;
	pf->conv = 0;
    pf->ilenght = 0;
    pf->index = 0;
    pf->dot = 0;
}

int     ft_printf(const char *format, ...)
{
    t_printf pf; 

    pf.fmt = (char *)format;
    va_start(pf.args, format);
    while (*pf.fmt != '\0')
    {
        if (*pf.fmt == '%' && pf.fmt++)
        {
            reset_struct(&pf);
            if (arg_parser(&pf) == 1)
            {   
                if (pf.conv == 'c')
                    c_print(&pf);
                if (pf.conv == 's')
                    s_print(&pf);
                if (pf.conv == 'p')
                    p_print(&pf);
                if (pf.conv == 'f')
                    f_options_print(&pf);
                if (pf.conv == 'd' || pf.conv == 'i')
                    di_options_print(&pf);
                if (pf.conv == 'u')
                    u_options_print(&pf);
                if (pf.conv == 'o')
                    o_options_print(&pf);
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