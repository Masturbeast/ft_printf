#include "ft_printf.h"

/* 
Function that check the options by getting 'format'.
In this function, it also consider that:
- O_MINUS cancel O_ZERO.
- O_PLUS cancel O_SPQCE.
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
Specifier is right after the option ones.
*/

void	width_check(t_printf *pf)
{
	if (*pf->fmt >= 49 && *pf->fmt <= 57)
		pf->width = ft_atoi(pf->fmt);
	while (*pf->fmt >= 49 && *pf->fmt <= 57)
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
		pf->fmt++;
		if (*pf->fmt >= 48 && *pf->fmt <= 57)
			pf->prec = ft_atoi(pf->fmt);
	}
	else
		pf->prec = 0;
	while (*pf->fmt >= 49 && *pf->fmt <= 57)
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
			res <<= 5;
			pf->opt_size |= res;
		}
		if (*pf->fmt++ != )
	}

}

/*
Function that check the conversion type, it supposes to be a letter (char).
Last specifier.
*/

void	conv_check(t_printf *pf)
{
	char	*str;
	int		i;

	str = "cspdiouxXf";
	i = 0;
	while (str[i] != *pf->fmt)
		i++;
	if (str[i] == *pf->fmt)
	{
		pf->conv = str[i];
	}
}	