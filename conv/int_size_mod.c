#include "ft_printf.h"

intmax_t     di_int_cast(t_printf *pf)
{
    if (pf->opt_size & S_SHORT)     //opt_size = 'h'
        return ((short)(va_arg(pf->args, int)));
    if (pf->opt_size & S_LONG)      //opt_size = 'l'
        return (va_arg(pf->args, long));
    if (pf->opt_size & S_INTMAX)    //opt_size = 'j'
        return (va_arg(pf->args, intmax_t));
    if (pf->opt_size & S_SIZE_T)    //opt_size = 'z'
        return (va_arg(pf->args, ssize_t));
    if (pf->opt_size & S_CHAR)      //opt_size = "hh"
        return ((char)va_arg(pf->args, int));
    if (pf->opt_size & S_LLONG)     //opt_size = "ll"
        return (va_arg(pf->args, long long));
    return (va_arg(pf->args, int));
}

uintmax_t   oux_int_cast(t_printf *pf)
{
    if (pf->opt_size & S_SHORT)
        return ((unsigned short)(va_arg(pf->args, unsigned int)));
    if (pf->opt_size & S_LONG)
        return (va_arg(pf->args, unsigned long));
    if (pf->opt_size & S_INTMAX)
        return (va_arg(pf->args, uintmax_t));
    if (pf->opt_size & S_SIZE_T)
        return (va_arg(pf->args, size_t));
    if (pf->opt_size & S_CHAR)
        return ((unsigned char)va_arg(pf->args, unsigned int));
    if (pf->opt_size & S_LLONG)
        return (va_arg(pf->args, unsigned long long));
    return (va_arg(pf->args, unsigned int));
}