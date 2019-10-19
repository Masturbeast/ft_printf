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
		padding(twidth - 1, ' ');
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
				padding(twidth - 1, '0');
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
					padding(twidth - 1, ' ');
					write(1, "-", 1);
					write(1, res, (pf->ilenght + pf->prec + 1));
				}
			}
			else
			{
				padding(twidth - 1, ' ');
				write(1, "-", 1);
				write(1, res, (pf->ilenght + pf->prec + 1));
			}
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		write(1, "-", 1);
		write(1, res, (pf->ilenght + pf->prec + 1));
		padding(twidth - 1, ' ');
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
		padding(twidth, ' ');
	}
	else if ((!(pf->opt_size & O_MINUS)) && ((!(pf->opt_size & O_SPACE)) || (pf->opt_size & O_SPACE)))
	{
		if (pf->opt_size & O_ZERO)
		{   
			if (pf->opt_size & O_SPACE)
				padding(1, ' ');
			else if (pf->opt_size & O_PLUS)
			{	
				ft_putchar('+');
				twidth = twidth - 1;
			}
			padding(twidth, '0');
			write(1, res, (pf->ilenght + pf->prec));
		}
		else
		{
			if (pf->opt_size & O_PLUS)
			{
				padding(twidth - 1, ' ');
				ft_putchar('+');
				write(1, res, (pf->ilenght + pf->prec));
			}
			else if (pf->opt_size & O_SPACE)
			{
				if (pf->width == 0)
				{
					padding(1, ' ');
					write(1, res, (pf->ilenght + pf->prec));
				}
				else if (pf->width <= (pf->ilenght + pf->prec))
				{
					padding(twidth, ' ');
					write(1, res, (pf->ilenght + pf->prec));
				}
				else
				{
					padding(twidth, ' ');
					write(1, res, (pf->ilenght + pf->prec));
				}
			}
			else
			{
				padding(twidth, ' ');	
				write(1, res, (pf->ilenght + pf->prec));
			}
		}
	}
	else if (pf->opt_size & O_MINUS && pf->opt_size & O_SPACE)
	{
		printf("test\n");
		padding(1, ' ');
		write(1, res, (pf->ilenght + pf->prec));
		padding(twidth, ' ');
	}
}

int    f_options_print(t_printf *pf)
{
	int					twidth;
	long double			print;

	print = f_float_cast(pf);
	//printf("in f_options_print, print is : %Lf\n", print);
	/*if ((pf->res = (char*)malloc(sizeof(char) * (pf->ilenght + pf->prec + 1))) == NULL)
		return (0);*/
	ft_ftoa(pf, print);
	//printf("in f_options_print, print2 is : %Lf\n", print);
	//printf("in f_options_print, pf->res is : %s\n", pf->res);
	//printf("in f_options_print, pf->ilenght is : %d\n", pf->ilenght);
	//printf("in f_options_print, pf->prec is : %d\n", pf->prec);
	twidth = pf->width - (pf->ilenght + pf->prec);
	if (is_neg_float(print) == 1)
	{
		pf->ilenght -= 1;
		neg_float_print(pf, twidth, pf->res);
		//printf("in f_options_print, pf->opt_size is : %d\n", pf->opt_size);
	}
	if (is_neg_float(print) == 0)
	{
		/*printf("in f_options_print, pf->conv is : %c\n", pf->conv);
		printf("in f_options_print, pf->prec is : %d\n", pf->prec);
		printf("in f_options_print, pf->opt_size is : %d\n", pf->opt_size);
		printf("in f_options_print, pf->width is : %d\n", pf->width);
		printf("in f_options_print, pf->ilenght is : %d\n", pf->ilenght);*/
		pos_float_print(pf, twidth, pf->res);
		//printf("in f_options_print, pf->res2 is : %s\n", pf->res);
	}
	//free(pf->res);
	return (0);
}