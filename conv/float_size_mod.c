#include "ft_printf.h"

long double     f_float_cast(t_printf *pf)
{
    if (pf->opt_size & S_LONG)      //opt_size = 'l'
        return (va_arg(pf->args, double));
	if (pf->opt_size & S_LDOUBLE)   //opt_size = 'L'
        return (va_arg(pf->args, long double));
    return (va_arg(pf->args, double));
}