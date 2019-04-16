#include "ft_printf.h"

void    call_cast(t_printf *pf)
{
    if (pf->conv == 'd' || pf->conv == 'i')
        di_int_cast(&pf);
    else
}