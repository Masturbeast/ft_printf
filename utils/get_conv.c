#include "ft_printf.h"

char     get_conv(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (str[i]);
        i++;
    }
    return (0);
}