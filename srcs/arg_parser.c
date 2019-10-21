#include "ft_printf.h"

/* 
Function that check the options by getting 'format'.
In this function, it also consider that:
- O_MINUS cancel O_ZERO.
- O_PLUS cancel O_SPACE.
First specifier.
*/

void     opt_check(t_printf *pf)
{
	int res;

	while ((res = get_opt_size("#0-+ ", *pf->fmt)) && pf->fmt++)
		pf->opt_size |= res;
	if ((pf->opt_size & O_MINUS) && (pf->opt_size & O_ZERO))
		pf->opt_size &= ~O_ZERO;
	if ((pf->opt_size & O_PLUS) && (pf->opt_size & O_SPACE))
		pf->opt_size &= ~O_SPACE;
}

/*
Function that check the minimum width, specified by numbers (ASCII) or nothing.
It can be the width for the option too.
Specifier is right after the option ones.
*/

void	width_check(t_printf *pf)
{
	if (*pf->fmt >= 49 && *pf->fmt <= 57)
		pf->width = ft_atoi(pf->fmt);
	while (*pf->fmt >= 48 && *pf->fmt <= 57)
		pf->fmt++;
}

/*
Function that check the precision, starting with ".".
Specifier is right after the width one.
*/

void	prec_check(t_printf *pf)
{
	if (*pf->fmt == 46)
	{	
		pf->dot = 1;
		pf->fmt++;
		if (*pf->fmt >= 48 && *pf->fmt <= 57)
			pf->prec = ft_atoi(pf->fmt);
		else
			pf->prec = 0;
	}
	else
	{
		pf->prec = 6;
		pf->dot	= 0;
	}
	while (*pf->fmt >= 48 && *pf->fmt <= 57)
		pf->fmt++;
}

/*
Function that check the size modifier, it supposes to be a letter (char).
104 is the ASCII for 'h'.
108 is the ASCII for 'l'.
Specifier is right after the precision one.
*/

void	size_check(t_printf *pf)
{
	int res;

	if ((res = get_opt_size("hlLjz", *pf->fmt)) && pf->fmt++)
	{
		res <<= 5;
		pf->opt_size |= res;
		if ((*pf->fmt == 104 && *pf->fmt++ == 104) || (*pf->fmt == 108 && *pf->fmt++ == 108))
		{
			pf->opt_size &= ~S_SHORT;
			pf->opt_size &= ~S_LONG;
			res <<= 5;
			pf->opt_size |= res;
		}
	}
} 

/*
Function that check the conversion type, it supposes to be a letter (char).
Last specifier.s
*/

int		conv_check(t_printf *pf)
{
	char	*str;
	int		i;

	/*printf("*pf->fmt is : %c\n", *pf->fmt);
	printf("*pf->conv is : %c\n", pf->conv);*/
	str = "cspdiouxXf%";
	i = 0;
	while (str[i] && str[i] != *pf->fmt)
		i++;
	if (str[i] == *pf->fmt)
	{
		pf->conv = str[i];
		pf->fmt++;
		/*if(pf->conv == '%')
		{
			i = 0;
			while (str[i] && str[i] != *pf->fmt)
			{
				if (str[i] == *pf->fmt)
				{
					pf->conv = str[i];
					pf->fmt++;
				}
				i++;
			}
		}*/
		return (1);
	}
	return (0);
}

int		arg_parser(t_printf *pf)
{
	opt_check(pf);
    width_check(pf);
    prec_check(pf);
    size_check(pf);
	if (conv_check(pf) == 0 || !pf->conv)
		return (0);
	if (pf->conv != 'f' && pf->dot == 0)
		pf->prec = 0;
	//printf("In format, pf.fmt = %c\n", *pf->fmt);
	//printf("in parser, conv is : %c\n", pf->conv);
	return (1);	
}