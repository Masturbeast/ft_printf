#include "ft_printf.h"

void	s_print(t_printf *pf)
{
	char *str;
	
	str = s_conv(pf);
	write(1, str, ft_strlen(str));
}