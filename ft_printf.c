#include "ft_printf.h"

int     ft_printf(const char *fmt, ...)
{
    va_list(args);

    va_start(args, fmt);
    
    if (strcmp(fmt, "%s%c") == 0)
    {
       printf("%c\n", va_arg(args, int));
       printf("%s\n", va_arg(args, char *));
    }
    va_end(args);
    return(0);
}