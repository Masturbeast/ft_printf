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
	if (pf->prec || (pf->prec == 0 && pf->dot == 1))
		len = pf->prec;
	pf->count += len;
	twidth = pf->width - len;
	if (pf->opt_size & O_MINUS)
	{
		write(1, str, len);
		padding(pf, twidth, ' ');
	}
	else
	{
		padding(pf, twidth, ' ');
		write(1, str, len);
	}
}