#include "ft_printf.h"

void    u_options_print(t_printf *pf)
{
	int				twidth;
	unsigned int	print;

	print = oux_int_cast(pf);
	twidth = pf->width - ft_int_length(print);
	pos_int_print(pf, twidth, print);
}