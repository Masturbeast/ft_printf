#include "ft_printf.h"

void	percent_print(t_printf *pf)
{
	int twidth;

	twidth = pf->width - 1;
	if (pf->opt_size & O_MINUS)
	{
		write(1, "%", 1);
		padding(twidth, ' ');
	}
	else
	{
		padding(twidth, ' ');
		write(1, "%'", 1);
	}
}