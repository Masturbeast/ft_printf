#include "ft_printf.h"

int     is_prec(t_printf *pf)
{
	if (pf->prec)
		return (1);
	return (0);
}

int     is_neg_float(long double nb)
{
	if ((nb < 0) || (1 / nb < 0))
		return (1);
	return (0);
}

void       neg_float_print(t_printf *pf, unsigned int twidth, char *res)
{
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		write(1, "-", 1);
		write(1, res, (pf->ilenght + pf->prec));
		padding(pf, twidth - 1, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || (pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_ZERO)
		{   
			write(1, "-", 1);
			if (pf->opt_size & O_SPACE)
			{
				//write(1, "-", 1);
			}
			else
			{
				//write(1, "-", 1);
				padding(pf, twidth - 1, '0');
				write(1, res, (pf->ilenght + pf->prec + 1));
			}
		}
		else
		{
			if (pf->opt_size & O_SPACE)
			{
				if (pf->width == 0)
				{
					write(1, "-", 1);
					write(1, res, (pf->ilenght + pf->prec + 1));
				}
				else if (pf->width <= (pf->ilenght + pf->prec))
				{
					write(1, "-", 1);
					write(1, res, (pf->ilenght + pf->prec + 1));
				}
				else
				{
					padding(pf, twidth - 1, ' ');
					write(1, "-", 1);
					write(1, res, (pf->ilenght + pf->prec + 1));
				}
			}
			else
			{
				padding(pf, twidth - 1, ' ');
				write(1, "-", 1);
				write(1, res, (pf->ilenght + pf->prec + 1));
			}
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		write(1, "-", 1);
		write(1, res, (pf->ilenght + pf->prec + 1));
		padding(pf, twidth - 1, ' ');
	}
}

void       pos_float_print(t_printf *pf, int twidth, char *res)
{
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_PLUS)
		{
			ft_putchar('+');
			twidth = twidth - 1;
		}
		write(1, res, (pf->ilenght + pf->prec));
		padding(pf, twidth, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || (pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_ZERO)
		{   
			if (pf->opt_size & O_SPACE)
				padding(pf, 1, ' ');
			else if (pf->opt_size & O_PLUS)
			{	
				ft_putchar('+');
				twidth = twidth - 1;
			}
			padding(pf, twidth, '0');
			write(1, res, (pf->ilenght + pf->prec));
		}
		else
		{
			if (pf->opt_size & O_PLUS)
			{
				padding(pf, twidth - 1, ' ');
				ft_putchar('+');
				write(1, res, (pf->ilenght + pf->prec));
			}
			else if (pf->opt_size & O_SPACE)
			{
				if (pf->width == 0)
				{
					padding(pf, 1, ' ');
					write(1, res, (pf->ilenght + pf->prec));
				}
				else if (pf->width <= (pf->ilenght + pf->prec))
				{
					padding(pf, twidth, ' ');
					write(1, res, (pf->ilenght + pf->prec));
				}
				else
				{
					padding(pf, twidth, ' ');
					write(1, res, (pf->ilenght + pf->prec));
				}
			}
			else
			{
				padding(pf, twidth, ' ');	
				write(1, res, (pf->ilenght + pf->prec));
			}
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		padding(pf, 1, ' ');
		write(1, res, (pf->ilenght + pf->prec));
		padding(pf, twidth, ' ');
	}
}

int    f_options_print(t_printf *pf)
{
	int					twidth;
	long double			print;

	print = f_float_cast(pf);
	ft_ftoa(pf, print);
	twidth = pf->width - (pf->ilenght + pf->prec);
	if (is_neg_float(print) == 1)
	{
		pf->ilenght -= 1;
		neg_float_print(pf, twidth, pf->res);
		pf->count += (pf->ilenght + pf->prec + 2);
	}
	if (is_neg_float(print) == 0)
	{
		pos_float_print(pf, twidth, pf->res);
		pf->count += (pf->ilenght + pf->prec);
	}
	ft_strclr(pf->res);
	return (0);
}