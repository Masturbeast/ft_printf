#include "ft_printf.h"

void    u_options_print(t_printf *pf)
{
	int				twidth;
	uintmax_t		print;

	print = oux_int_cast(pf);
	twidth = pf->width - ft_uint_length(print);
	pf->count += ft_uint_length(print);
	pos_uint_print(pf, twidth, print);
}

void	pos_uint_print(t_printf *pf, int twidth, uintmax_t print)
{
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		ft_uputnbr(print);
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
						padding(pf, pf->width - pf->prec, ' ');
						padding(pf, pf->prec - ft_uint_length(print), '0');
				}
			}
			if (print == 0 && pf->prec != 0)
			{
				ft_uputnbr(print);
			}
			else
			{
				ft_uputnbr(print);
			}
		}
		else if (pf->opt_size & O_PLUS || pf->opt_size & O_SPACE)
		{
				if (pf->dot == 1 && print == 0)
				{
					twidth += 1;
				}
				padding(pf, twidth - 1, ' ');
				if (pf->dot == 0 || (pf->dot == 1 && print != 0))
				{
					ft_uputnbr(print);
				}
			else if (pf->opt_size & O_SPACE)
			{
				if (pf->dot == 0 || (pf->dot == 1 && print != 0))
				{
					ft_uputnbr(print);
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
				ft_uputnbr(print);
			}
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		padding(pf, 1, ' ');
		ft_uputnbr(print);
		padding(pf, twidth - 1, ' ');
	}	
}
