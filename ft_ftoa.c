#include "includes/ft_printf.h"

char	*neg_fround(int prec, long long int x, long double y, char *intcat)
{
	long long int 		t;
	int					i;
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
	ft_inttostr(t, intcat + i + 1, prec);
	i += ft_inttostr(t, intcat + i + 1, prec);
	intcat[i] = '\0';
	return (intcat);
}

char	*pos_fround(int prec, long long int x, long double y, char *intcat)
{
	long long int 		t;
	int					i;
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
	i += ft_inttostr(t, intcat + i + 1, prec);
	intcat[i] = '\0';
	return (intcat);
}

char	*f_is_zero(int prec, char *intcat)
{
	int	i;
	int j;

	if (intcat[0] == '-')
	{
		intcat[1] = '0';
		intcat[2] = '.';
		i = prec + 3;
		j = 3;
	}
	else
	{
		intcat[0] = '0';
		intcat[1] = '.';
		i = prec + 2;
		j = 2;
	}
	while (j < i)
		intcat[j++] = '0';
	intcat[i] = '\0';
	return (intcat);
}

/*char	*f_is_inf(char *intcat)
{
	int	 i;
	char *str;

	if (intcat[0] == 'N')
		intcat = "nan";
	if (intcat[0] == '-')
	{

		str = "-inf";
	}
	else
		intcat = "inf";
	return (&str);
}*/

void	ft_ftoa(int prec, long double n, char *res)
{ 
    long int 	ipart;
	int 		i;
	long double fpart;
	long double	d;
	
	i = 0;
	if (n == 1 / 0.0)
		write(1, "inf", 4);
	if (n == 1 / -0.0)
		write(1, "-inf", 5);
	if (n == 0.0 / 0.0)
	{
		printf("test\n");
		write(1, "nan", 4);
	}
	if (n == 0)
	{
		if ((1 / n) < 0)
		{
			res[0] = '-';
			res = f_is_zero(prec, res);
		}
		else
			res = f_is_zero(prec, res);
	}
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
    long double n = 1.0 / 0.0;
    char *str = "float nbr is: -0";
    
    printf("%s\n", str);
    ft_ftoa(6, n, res);
	printf("\n");
	printf("%Lf\n", n); 
	//printf("   my printf: %s\n", res);
    return (0); 
}