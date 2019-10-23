#include "ft_printf.h"

void	o_options_print(t_printf *pf)
{
	unsigned int	print;
	char 			*str;
	int 			len;
	int				twidth;

	print = oux_int_cast(pf);
	str = ft_itoa_base(print, 8);
	len = ft_strlen(str);
	twidth = pf->width - len;
	if (pf->opt_size & O_HASH)
	{
		if ((!(pf->opt_size & O_MINUS)) && (!(pf->opt_size & O_ZERO)))
		{
			if (pf->prec == 0)
			{
				padding(twidth - pf->prec - 1, ' ');
				padding(1, '0');
			}
			else
			{
				padding(pf->width - pf->prec, ' ');
				if (len >= pf->prec)
					padding(1, '0');
				else
					padding(pf->prec - len, '0');
			}
			write(1, str, len);
		}
		if (pf->opt_size & O_ZERO)
		{
			if (pf->width == 0)
				padding(1, '0');
			else
				padding(twidth, '0');
			write(1, str, len);
		}
		if (pf->opt_size & O_MINUS)
		{
			padding(1, '0');
			write(1, str, len);
			padding(twidth - pf->prec - 1, ' ');
		}
	}
	else if (pf->opt_size & O_ZERO && (!(pf->opt_size & O_MINUS)) && (!(pf->opt_size & O_HASH)))
	{
		padding(twidth, '0');
		write(1, str, len);
	}
	else if (pf->opt_size & O_MINUS)
	{
		padding(pf->prec - len, '0');
		write(1, str, len);
		if (pf->prec)
			padding(twidth - pf->prec + 1, ' ');
		else
			padding(twidth - pf->prec, ' ');
	}
	else
	{	
		padding(twidth, ' ');
		padding(pf->prec - len, '0');
		write(1, str, len);
	}
}