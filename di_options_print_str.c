/* Printing options with string */

#include "ft_printf.h"

void    padding(t_printf *pf, int width, char c)
{
	while (pf->i < width)
	{
		pf->str[pf->i] = c;
		pf->i++;
	}
}

int     is_prec(t_printf *pf)
{
	if (pf->prec)
		return (1);
	return (0);
}

int     is_neg_int(intmax_t nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

void    neg_int_print(t_printf *pf, int twidth, intmax_t print)
{
	pf->i = 0;
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		pf->str[pf->i++] = '-';
		pf->i += ft_inttostr(print, pf->str, 0);
		padding(pf, twidth, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || pf->opt_size & O_SPACE))
	{
		if (pf->opt_size & O_ZERO)
		{   
			pf->str[pf->i++] = '-';
			padding(pf, twidth, '0');
			pf->i += ft_inttostr(print, pf->str, 0);
		}
		else
		{
			padding(pf, twidth, ' ');
			pf->str[pf->i++] = '-';
			pf->i += ft_inttostr(print, pf->str, 0);
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		pf->str[pf->i++] = '-';
		pf->i += ft_inttostr(print, pf->str, 0);
		padding(pf, twidth, ' ');
	}
	else
		pf->i += ft_inttostr(print, pf->str, 0);
}

void	pos_int_print(t_printf *pf, int twidth, uintmax_t print)
{
	pf->i = 0;
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_PLUS)
		{
			pf->str[pf->i++] = '+';
			twidth = twidth - 1;
		}
		pf->i += ft_inttostr(print, pf->str, 0);
		padding(pf, twidth, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || pf->opt_size & O_SPACE))
	{
		if (pf->opt_size & O_ZERO)
		{   
			if (pf->opt_size & O_SPACE)
			{    
				padding(pf, twidth, ' ');
				twidth = twidth - 1;
			}
			else if (pf->opt_size & O_PLUS)
			{	
				pf->str[pf->i++] = '+';
				twidth = twidth - 1;
			}
			padding(pf, twidth, '0');
			pf->i += ft_inttostr(print, pf->str, 0);
		}
		else
		{
			if (pf->opt_size & O_PLUS)
			{
				padding(pf, twidth - 1, ' ');
				pf->str[pf->i++] = '+';
				pf->i += ft_inttostr(print, pf->str, 0);
			}
			else
			{
				padding(pf, twidth, ' ');
				pf->i += ft_inttostr(print, pf->str, 0);
			}
		}
		if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
		{
			padding(pf, 1, ' ');
			pf->i += ft_inttostr(print, pf->str, 0);
			padding(pf, twidth - 1, ' ');
		}
		else
			pf->i += ft_inttostr(print, pf->str, 0);
	}
}

void    di_options_print(t_printf *pf)
{
	int         twidth;
	intmax_t	print;

	print = di_int_cast(pf);
	twidth = pf->width - ft_int_length(print);
	
	if (is_neg_int(print) == 1)
	{
		print = print * -1;
		neg_int_print(pf, twidth, print);
		write(1, pf->str, ft_strlen(pf->str));
	}
	else if (is_neg_int(print) == 0)
	{
		print = (uintmax_t)print;
		pos_int_print(pf, twidth, print);
		write(1, pf->str, ft_strlen(pf->str));
	}
}