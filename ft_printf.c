#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    va_end(argList);
}