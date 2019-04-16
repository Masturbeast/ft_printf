#include "ft_printf.h"

intmax_t     di_int_cast(t_printf *pf)
{
    if (pf->opt_size & S_SHORT)
        return ((short)(va_arg(pf->args, int)));
    if (pf->opt_size & S_LONG)
    {
        printf("je passe par la\n");
        return (va_arg(pf->args, long));
    }
    if (pf->opt_size & S_INTMAX)
        return (va_arg(pf->args, intmax_t));
    if (pf->opt_size & S_SIZE_T)
        return (va_arg(pf->args, ssize_t));
    if (pf->opt_size & S_CHAR)
        return ((char)va_arg(pf->args, int));
    if (pf->opt_size & S_LLONG)
        return (va_arg(pf->args, long long));
    return (va_arg(pf->args, int));
}