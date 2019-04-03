#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
# include "libft/libft.h"

void    ft_print_char(const char *fmt, ...)
{
    int     i;
    char    *s;

    va_list(ap);
    va_start(ap, fmt);
    i = 0;
    while (fmt[i] != '\0')
    {
        if (fmt[i] == '%' && fmt[i + 1] == 's')
        {
            while (fmt[i] != 's')
            {
                s = va_arg(ap, char *);
                i++;
            }
            write(1, s, ft_strlen(s));
        }
        write(1, &fmt[i], 1);
        i++;
    }
    va_end(ap);
}

void  ft_printf(const char *fmt, ...)
{
    int     i;
    int     c;
    double  d;
    char    *s;

    va_list(ap);
    va_start(ap, fmt);

    if (*fmt == '%')
    {
        while (*fmt != '\0')
        {
            if (*fmt == 's' || *fmt == 'c')
            {
                if (*fmt == 'c')
                {
                    c = va_arg(ap, int);
                    write(1, &c, 1);
                }
                else
                {
                    s = va_arg(ap, char *);
                    write(1, s, ft_strlen(s));
                }  
            }
            ++fmt;
        }
    va_end(ap);
    }
}

int main()
{
    ft_print_char("str is: %s rge rgrge", "salut maggle");
    //ft_printf("%c", 97);
    //printf("resultat = %d\n", addn(2, 1, 2));
    return (0);
}