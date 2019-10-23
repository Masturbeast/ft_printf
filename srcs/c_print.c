#include "ft_printf.h"

void	c_print(t_printf *pf)
{
	int		twidth;
	char 	c;
	
	c = c_conv(pf);
	twidth = pf->width - 1;
	if (pf->opt_size & O_MINUS)
	{
		write(1, &c, 1);
		padding(pf, twidth, ' ');
	}
	else
	{
		padding(pf, twidth, ' ');
		write(1, &c, 1);
	}
}