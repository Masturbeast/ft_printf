#include "../ft_printf.h"

int     get_opt_size(char *str, char c)
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