#include "ft_printf.h"
#include <stdio.h>

char    *ft_format_parsing(char *fmt)
{
    int i;

    i = 0;
    while (fmt[i] != '\0')
    {
        if (fmt[i] != '%')
            return (NULL);
        else
        {
            /* call fonctions for each flags */
        }
        
    }
}