#include "ft_printf.h"

void	c_print(t_printf *pf)
{
	char c;
	
	c = c_conv(pf);
	write(1, &c, 1);
}