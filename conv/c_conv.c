#include "ft_printf.h"

int     c_conv(t_printf *pf)
{
    return (va_arg(pf->args, int));
}