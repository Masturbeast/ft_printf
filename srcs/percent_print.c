#include "ft_printf.h"

void	percent_print(t_printf *pf)
{
	int twidth;

	twidth = pf->width - 1;
	pf->count++;
	if (pf->opt_size & O_MINUS)
	{
		write(1, "%", 1);
		padding(pf, twidth, ' ');
	}
	else
	{
		padding(pf, twidth, ' ');
		write(1, "%'", 1);
	}
}