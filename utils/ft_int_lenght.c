#include "ft_printf.h"

int		ft_int_length(intmax_t n)
{
	int i;

	i = 1;

	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n / 10)
		i += ft_int_length(n / 10);
	return (i);
}

int		ft_uint_length(uintmax_t n)
{
	int i;

	i = 1;

	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n / 10)
		i += ft_uint_length(n / 10);
	return (i);
}