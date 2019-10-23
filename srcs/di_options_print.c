#include "ft_printf.h"

void    padding(t_printf *pf, int width, char c)
{
	int     i;

	i = 0;
	while (i < width)
	{
		ft_putchar(c);
		pf->count++;
		i++;
	}
}

int     is_neg_int(intmax_t nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

/*void    neg_int_print(t_printf *pf, int twidth, intmax_t print)
{
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		ft_putchar('-');
		ft_putnbr(print);
		padding(twidth, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || pf->opt_size & O_SPACE))
	{
		if (pf->opt_size & O_ZERO || pf->prec > 0)
		{   
			if (pf->width > pf->prec && pf->prec != 0)
				padding(twidth, ' ');
			ft_putchar('-');
			if (pf->prec > 0)
				padding(pf->prec - ft_int_length(print), '0');
			else
				padding(twidth, '0');
			ft_putnbr(print);
		}
		else
		{
			padding(twidth, ' ');
			ft_putchar('-');
			ft_putnbr(print);
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		ft_putchar('-');
		ft_putnbr(print);
		padding(twidth, ' ');
	}
	else
		ft_putnbr(print);
}*/

void	pos_int_print(t_printf *pf, int twidth, uintmax_t print)
{
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_PLUS)
		{
			ft_putchar('+');
			pf->count++;
			twidth = twidth - 1;
		}
		ft_putnbr(print);
		padding(pf, twidth, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || pf->opt_size & O_SPACE))
	{
		if (pf->opt_size & O_ZERO || pf->prec > 0)
		{   
			twidth += pf->prec;
			if (pf->opt_size & O_SPACE)
			{    
				padding(pf, 1, ' ');
				twidth = twidth - 1;
			}
			if (pf->width == 0 && pf->prec > 0)
				padding(pf, twidth, '0');
			else
			{
				if (pf->prec == 0)
				{
					padding(pf, twidth, '0');
				}
				else
				{
					if (pf->opt_size & O_PLUS)
					{
						padding(pf, pf->width - pf->prec - 1, ' ');
						ft_putchar('+');
						pf->count++;
						padding(pf, pf->prec - ft_int_length(print), '0');
					}
					else
					{
						padding(pf, pf->width - pf->prec, ' ');
						padding(pf, pf->prec - ft_int_length(print), '0');
					}
				}
			}
			if (print == 0 && pf->prec != 0)
			{
				ft_putnbr(print);
			}
			else
			{
				ft_putnbr(print);
			}
		}
		else if (pf->opt_size & O_PLUS || pf->opt_size & O_SPACE)
		{
			if (pf->opt_size & O_PLUS)
			{
				if (pf->dot == 1 && print == 0)
				{
					twidth += 1;
				}
				padding(pf, twidth - 1, ' ');
				ft_putchar('+');
				pf->count++;
				if (pf->dot == 0 || (pf->dot == 1 && print != 0))
				{
					ft_putnbr(print);
				}
			}
			else if (pf->opt_size & O_SPACE)
			{
				if (pf->width == 0)
				{
					padding(pf, 1, ' ');
				}
				else
				{
					padding(pf, twidth + 1, ' ');
				}
				if (pf->dot == 0 || (pf->dot == 1 && print != 0))
				{
					ft_putnbr(print);
				}
			}
		}
		else
		{
			if (pf->dot == 1 && pf->prec == 0 && print == 0)
			{
				padding(pf, twidth + 1, ' ');
			}
			else
			{
				padding(pf, twidth, ' ');
				ft_putnbr(print);
			}
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		padding(pf, 1, ' ');
		ft_putnbr(print);
		padding(pf, twidth - 1, ' ');
	}
}

void    di_options_print(t_printf *pf)
{
	int			twidth;
	int			print;

	print = di_int_cast(pf);
	twidth = pf->width - ft_int_length(print);
	pf->count += ft_nbrlen(print, 10);
	if (is_neg_int(print) == 1)
	{
		print = print * (-1);
		neg_int_print(pf, twidth, print);
	}
	else if (is_neg_int(print) == 0)
		pos_int_print(pf, twidth, print);
}

/*void	pos_int_print(t_printf *pf, int twidth, uintmax_t print)
{
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_PLUS)
		{
			ft_putchar('+');
			pf->count++;
			twidth = twidth - 1;
		}
		ft_putnbr(print);
		padding(twidth, ' ');
		pf->count += ft_nbrlen(print, 10) + twidth;
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || pf->opt_size & O_SPACE))
	{
		if (pf->opt_size & O_ZERO || pf->prec > 0)
		{   
			twidth += pf->prec;
			if (pf->opt_size & O_SPACE)
			{    
				padding(1, ' ');
				pf->count++;
				twidth = twidth - 1;
			}
			if (pf->width == 0 && pf->prec > 0)
				padding(twidth, '0');
			else
			{
				if (pf->prec == 0)
				{
					padding(twidth, '0');
					pf->count += twidth;
				}
				else
				{
					if (pf->opt_size & O_PLUS)
					{
						padding(pf->width - pf->prec - 1, ' ');
						ft_putchar('+');
						padding(pf->prec - ft_int_length(print), '0');
						pf->count += (twidth - ft_nbrlen(print, 10));
					}
					else
					{
						padding(pf->width - pf->prec, ' ');
						padding(pf->prec - ft_int_length(print), '0');
						pf->count += (pf->width - ft_nbrlen(print, 10));
					}
				}
			}
			if (print == 0 && pf->prec != 0)
			{
				ft_putnbr(print);
				pf->count += ft_nbrlen(print, 10);
			}
			else
			{
				ft_putnbr(print);
				pf->count += ft_nbrlen(print, 10);
			}
		}
		else if (pf->opt_size & O_PLUS || pf->opt_size & O_SPACE)
		{
			if (pf->opt_size & O_PLUS)
			{
				if (pf->dot == 1 && print == 0)
				{
					twidth += 1;
				}
				padding(twidth - 1, ' ');
				ft_putchar('+');
				pf->count += twidth;
				if (pf->dot == 0 || (pf->dot == 1 && print != 0))
				{
					ft_putnbr(print);
					pf->count += ft_nbrlen(print, 10);
				}
			}
			else if (pf->opt_size & O_SPACE)
			{
				if (pf->width == 0)
				{
					padding(1, ' ');
					pf->count++;
				}
				else
				{
					padding(twidth + 1, ' ');
					pf->count += twidth + 1;
				}
				if (pf->dot == 0 || (pf->dot == 1 && print != 0))
				{
					ft_putnbr(print);
					pf->count += ft_nbrlen(print, 10);
				}
			}
		}
		else
		{
			if (pf->dot == 1 && pf->prec == 0 && print == 0)
			{
				padding(twidth + 1, ' ');
				pf->count += twidth + 1;
			}
			else
			{
				padding(twidth, ' ');
				ft_putnbr(print);
				pf->count += twidth + ft_nbrlen(print, 10);
			}
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		padding(1, ' ');
		ft_putnbr(print);
		padding(twidth - 1, ' ');
		pf->count += twidth + ft_nbrlen(print, 10);
	}
}

void    di_options_print(t_printf *pf)
{
	int			twidth;
	int			print;

	print = di_int_cast(pf);
	twidth = pf->width - ft_int_length(print);
	if (is_neg_int(print) == 1)
	{
		print = print * (-1);
		neg_int_print(pf, twidth, print);
	}
	else if (is_neg_int(print) == 0)
		pos_int_print(pf, twidth, print);
}*/