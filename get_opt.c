#include <stdio.h>
#include "ft_printf.h"

int     get_opt(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (1 << i);
        i++;
    }
    return (0);
}