#include "ft_printf.h"

size_t		ft_int_length(intmax_t n)
{
	size_t			len;
	uintmax_t		nb;

	len = 1;
	if (n < 0)
	{
		len++;
		nb = (uintmax_t)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		len += ft_int_length((int)(nb / 10));
	return (len);
}