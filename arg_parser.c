#include "ft_printf.h"
#include <stdio.h>

/* 
Function that check the options by getting 'format'.
In this function, it also consider that:
- O_MINUS cancel O_ZERO.
- O_PLUS cancel O_SPQCE.
*/

void     opt_check(t_printf *format)
{
	int res;

	while ((res = get_opt("#0-+ ", *format->fmt)) && format->fmt++)
		format->opt |= res;
	if ((format->opt & O_MINUS) && (format->opt & O_ZERO))
		format->opt &= ~O_ZERO;
	if ((format->opt & O_PLUS) && (format->opt & O_SPACE))
		format->opt &= ~O_SPACE;
}

/*
Function that check the minimum width, specified by numbers (ASCII) or nothing.
Specifier is right after options.
*/

void	minwidth_check(t_printf *format)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (format->fmt[i] <= 49 && format->fmt[i] >= 57)
	{
		while (format->fmt[i] >= 49 && format->fmt[i] <= 57)
		{
			str[j] = format->fmt[i];
			i++;
			j++;
		}
		i++;
	}
	format->minwidth = ft_atoi(str);
}