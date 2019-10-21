#include "ft_printf.h"

unsigned long  p_conv(t_printf *pf)
{
   return(va_arg(pf->args, unsigned long));
}