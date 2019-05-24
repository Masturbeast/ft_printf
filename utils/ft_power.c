#include "ft_printf.h"

long long int		ft_power(long long int x, long long int power)
{
	long long int i;
	long long int a;

	a = x;
	if (power == 1)
		return (x);
	if (power == 0)
		return (1);
	i = 2;
	while (i <= power)
	{
		a = a * x;
		i++;
	}
	return (a);
}