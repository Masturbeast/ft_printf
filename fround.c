#include <stdio.h>

char	*fround(long int x, long double y, int prec)
{
	long int 	t;
	int			i;
	char 		*intcat;
	int			len;
	long int	power;

	power = ft_power(10, prec + 1);
	y = y * power;
	t = int_cat(x, y);
	i = ft_inttostr(t, intcat, 0);
	while (intcat[i] != '\0')
		i++;
	i--;
	if (intcat[i] >= '5')
		t = t + (10 - ft_atoi(&intcat[i]));
	ft_strclr(intcat);
	i = ft_inttostr(x, intcat, 0);
	intcat[i] = '.';
	t = t - (x * power);
	ft_inttostr(t, intcat + i + 1, prec);
	return (intcat);
}