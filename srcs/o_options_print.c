#include "ft_printf.h"

void	o_options_print(t_printf *pf)
{
	unsigned int	print;
	char 			*str;

	print = oux_int_cast(pf);
	str = ft_itoa_base(print, 42);
	printf("o print is : %s\n", str);
}