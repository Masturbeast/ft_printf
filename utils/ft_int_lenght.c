#include "ft_printf.h"

size_t	ft_int_length(long long int n)
{
	size_t i;

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