#include "ft_printf.h"

char	*s_conv(t_printf *pf)
{
        return(va_arg(pf->args, char*));
}