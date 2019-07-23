#include "ft_printf.h"

int     is_prec(t_printf *pf)
{
	if (pf->prec)
		return (1);
	return (0);
}

int     is_neg_float(long double nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

void       pos_float_print(t_printf *pf, unsigned long twidth, char *res)
{
	if ((pf->opt_size & O_MINUS) && (!(pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_PLUS)
		{
			ft_putchar('+');
			twidth = twidth - 1;
		}
		write(1, res, (pf->ilenght + pf->prec + 1));
		padding(twidth, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || pf->opt_size & O_SPACE))
	{
		if (pf->opt_size & O_ZERO)
		{   
			if (pf->opt_size & O_SPACE)
			{    
				padding(1, ' ');
				twidth = twidth - 1;
			}
			else if (pf->opt_size & O_PLUS)
			{	
				ft_putchar('+');
				twidth = twidth - 1;
			}
			padding(twidth, '0');
			write(1, res, (pf->ilenght + pf->prec + 1));
		}
		else
		{
			if (pf->opt_size & O_PLUS)
			{
				padding(twidth - 1, ' ');
				ft_putchar('+');
				write(1, res, (pf->ilenght + pf->prec + 1));
			}
			else
			{
				padding(twidth, ' ');
				write(1, res, (pf->ilenght + pf->prec + 1));
			}
		}
	}
}

int    f_options_print(t_printf *pf)
{
	int					twidth;
	long double			print;

	print = f_float_cast(pf);
	if ((pf->res = (char*)malloc(sizeof(char) * (pf->ilenght + pf->prec + 1))) == NULL)
		return (0);
	ft_ftoa(pf, print);
	twidth = pf->width - (pf->ilenght + pf->prec + 1);
	
	/*if (is_neg_float(print) == 1)
	{
		print = print * (-1);
		ft_ftoa(pf, print);
		//neg_int_print(pf, twidth, print);
	}*/
	if (is_neg_float(print) == 0)
	{
		//print = (long double)print;
		//printf("pf->res is: %s\n", pf->res);

		pos_float_print(pf, twidth, pf->res);
		free(pf->res);
	}
	return (0);
}