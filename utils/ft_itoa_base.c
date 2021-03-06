#include "ft_printf.h"

static	char	*ft_itoa_bis(uintmax_t tmp, int a, char *str, int base)
{
	const char	*baze = "0123456789abcdef";

	while (tmp)
	{
		str[--a] = baze[tmp % base];
		tmp /= base;
	}
	return (str);
}

char			*ft_itoa_base(uintmax_t value, int base)
{
	char			*str;
	uintmax_t		tmp;
	int				a;

	tmp = value;
	a = 0;
	while (value)
	{
		a++;
		value /= base;
	}
	if (tmp == 0 || (tmp < 0 && base == 10))
		a++;
	if (!(str = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	str[a] = '\0';
	if (tmp < 0)
	{
		if (base == 10)
			str[0] = '-';
		tmp = tmp * -1;
	}
	if (tmp == 0)
		str[0] = '0';
	return (ft_itoa_bis(tmp, a, str, base));
}