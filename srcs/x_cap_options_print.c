#include "ft_printf.h"

void	x_cap_options_print(t_printf *pf)
{
	unsigned int	print;
	char 			*str;
	int 			len;
	int				twidth;

	print = oux_int_cast(pf);
	str = ft_itoa_base_cap(print, 16);
	len = ft_strlen(str);
	twidth = pf->width - len;
	if (pf->opt_size & O_HASH)
	{
		if ((!(pf->opt_size & O_MINUS)) && (!(pf->opt_size & O_ZERO)))
		{
			if (pf->prec == 0)
			{
				padding(pf, twidth - pf->prec - 1, ' ');
				write(1, "0x", 2);
			}
			else
			{
				padding(pf, pf->width - pf->prec, ' ');
				if (len >= pf->prec)
					padding(pf, 1, '0');
				else
					padding(pf, pf->prec - len, '0');
			}
			write(1, str, len);
		}
		if (pf->opt_size & O_ZERO)
		{
			if (pf->width == 0)
				padding(pf, 1, '0');
			else
				padding(pf, twidth, '0');
			write(1, str, len);
		}
		if (pf->opt_size & O_MINUS)
		{
			padding(pf, 1, '0');
			write(1, str, len);
			padding(pf, twidth - pf->prec - 1, ' ');
		}
	}
	else if (pf->opt_size & O_ZERO && (!(pf->opt_size & O_MINUS)) && (!(pf->opt_size & O_HASH)))
	{
		padding(pf, twidth, '0');
		write(1, str, len);
	}
	else if (pf->opt_size & O_MINUS)
	{
		padding(pf, pf->prec - len, '0');
		write(1, str, len);
		if (pf->prec)
			padding(pf, twidth - pf->prec + 1, ' ');
		else
			padding(pf, twidth - pf->prec, ' ');
	}
	else
	{	
		padding(pf, twidth, ' ');
		padding(pf, pf->prec - len, '0');
		write(1, str, len);
	}
}