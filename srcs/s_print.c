#include "ft_printf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((int)((unsigned char)(s1[i]) - (unsigned char)(s2[i])));
		i++;
	}
	return ((int)((unsigned char)(s1[i]) - (unsigned char)(s2[i])));
}


void	s_print(t_printf *pf)
{
	char	*str;
	int		twidth;
	int		len;
	
	str = s_conv(pf);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if ((pf->prec || (pf->prec == 0 && pf->dot == 1)) && (ft_strcmp(str, "") != 0))
		len = pf->prec;
	pf->count += len;
	twidth = pf->width - len;
	if (pf->opt_size & O_MINUS)
	{
		if((ft_strcmp(str, "") != 0))
			write(1, str, len);
		padding(pf, twidth, ' ');
	}
	else
	{
		padding(pf, twidth, ' ');
		if((ft_strcmp(str, "") != 0))
			write(1, str, len);
	}
}