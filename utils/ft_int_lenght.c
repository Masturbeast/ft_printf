#include "../ft_printf.h"

size_t  ft_itoa_length(int n)
{
	size_t			len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
	{
		len++;
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		len += ft_itoa_length((int)(nb / 10));
	return (len);
}