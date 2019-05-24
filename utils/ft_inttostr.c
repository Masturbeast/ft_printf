#include "ft_printf.h"

int		ft_inttostr(long long int x, char *str, int prec) 
{ 
    int			i;
	long long int 	tmp;

	tmp = x;
	i = 0;
	if (x < 0)
		x *= (-1);
    while (x) 
    {
        str[i++] = (x % 10) + '0'; 
        x = x / 10;	
    }
	if (tmp < 0)
		str[i++] = '-';
    while (i < prec) 
        str[i++] = (x % 10) + '0';
    ft_str_reverse(str, i); 
    str[i] = '\0';
    return (i); 
}