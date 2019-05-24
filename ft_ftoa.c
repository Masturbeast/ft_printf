#include "includes/ft_printf.h"

char	*neg_fround(int prec, long long int x, long double y, char *intcat)
{
	long long int 		t;
	int				i;
	long long int		power;

	power = ft_power(10, prec + 1);
	y = y * power;
	t = int_cat(x, y);
	i = ft_inttostr(t, intcat, 0) - 1;
	if (intcat[i] >= '5')
		t -= (10 - ft_atoi(&intcat[i]));
	if (ft_int_length(t) > (ft_int_length(x) + prec + 1))
			x -= 1;
	ft_strclr(intcat);
	i = ft_inttostr(x, intcat, 0);
	intcat[i] = '.';
	t -= (x * power);
	if (t < 0)
		t *= (-1);
	ft_inttostr(t, intcat + i + 1, prec + 1);
	return (intcat);
}

char	*pos_fround(int prec, long long int x, long double y, char *intcat)
{
	long long int 		t;
	int				i;
	long long int		power;

	power = ft_power(10, prec + 1);
	y = y * power;
	t = int_cat(x, y);
	i = ft_inttostr(t, intcat, 0) - 1;
	if (intcat[i] >= '5')
		t = t + (10 - ft_atoi(&intcat[i]));
	if (ft_int_length(t) > (ft_int_length(x) + prec + 1))
		x += 1;
	ft_strclr(intcat);
	i = ft_inttostr(x, intcat, 0);
	intcat[i] = '.';
	t -= (x * power);
	ft_inttostr(t, intcat + i + 1, prec + 1);
	return (intcat);
}

void	ft_ftoa(int prec, long double n, char *res)
{ 
    long int ipart;
	int i;
	long double fpart;
	
	i = 0;
	ipart = (long long int)n;
    fpart = n - ipart;
	if (fpart < 0)
		fpart *= (-1);
	if (n < 0)
		res = neg_fround(prec, ipart, fpart, res);
	else if (n > 0)
		res = pos_fround(prec, ipart, fpart, res);
}

int		main() 
{
    char res[50];
    long double n = 99999.999999999;
    char *str = "float nbr is: 99999.99999999";
    
    printf("%s\n", str);
    ft_ftoa(3, n, res);
	printf("      printf: %.3Lf\n", n); 
	printf("   my printf: %s\n", res);
    return (0); 
}