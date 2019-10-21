#include "ft_printf.h"

void	s_print(t_printf *pf)
{
	char	*str;
	int		twidth;
	int		len;
	
	str = s_conv(pf);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	twidth = pf->width - len;
	if (pf->opt_size & O_MINUS)
	{
		write(1, str, len);
		padding(twidth, ' ');
	}
	else
	{
		padding(twidth, ' ');
		write(1, str, len);
	}
}