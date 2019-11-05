#include "ft_printf.h"
 
char	*pos_fround(t_printf *pf, long long int x, long double y)
{
	long long int 	t;
	int				i;
	long long int	power;

	power = ft_power(10, pf->prec + 1);
	y = y * power;
	if (x != 0)
		t = int_cat(x, y);
	else
		t = 0;
	i = ft_inttostr(t, pf->res, 0) - 1;
	printf("res is %s\n", pf->res);
	if (x != 0 && pf->res[i] >= '5')
		t = t + (10 - ft_atoi(&pf->res[i]));
	if (pf->prec == 0)
	{
		t /= 10;
		x = t;
		if (x == 0 && y > 5)
			x += 1;
	}
	ft_strclr(pf->res);
	i = ft_inttostr(x, pf->res, 0);
	if (pf->prec != 0 || pf->opt_size & O_HASH)
	{
		pf->res[i] = '.';
		i++;
		if (y == 0)
			t = 0;
		else if (x == 0)
		{
			t = (long long int)y;
			if (x == 0 && y > 5)
				t += 1;
		}
		else
			t -= (x * power);
		pf->ilenght += 1;
	}
	i += ft_inttostr(t, pf->res + i, pf->prec);
	ft_strcpy(pf->res, pf->res);
	printf("res is %s\n", pf->res);
	return (pf->res);
}

char	*f_is_zero(t_printf *pf, int n)
{
	int	i;
	int j;
	long long int ipart;

	ipart = (long long int)n;
	pf->ilenght = ft_int_length(ipart);
	pf->res[0] = '0';
	if (pf->prec != 0)
	{
		pf->res[1] = '.';
		i = pf->prec + 2;
		j = 2;
		pf->ilenght += 1;
	}
	else
	{
		i = pf->prec + 1;
		j = 1;
	}
	while (j < i)
		pf->res[j++] = '0';
	pf->res[i++] = '\0';
	return (pf->res);
}

void	ft_ftoa(t_printf *pf, long double n)
{ 
    long long int 	ipart;
	long double 	fpart;
	
	if (n == 1 / 0.0)
		write(1, "inf", 4);
	if (n == 1 / -0.0)
		write(1, "-inf", 5);
	if (n == 0.0 / 0.0)
		write(1, "nan", 4);
	if (n == 0)
	{
		if ((1 / n) < 0)
		{
			pf->res[0] = '-';
			ft_strcpy(pf->res, f_is_zero(pf, n));
		}
		else
			ft_strcpy(pf->res, f_is_zero(pf, n));
	}
	else
	{
		ipart = (long long int)n;
    	fpart = n - ipart;
		if (ipart < 0)
			ipart *= (-1);
		if (fpart < 0)
			fpart *= (-1);
		pf->ilenght = ft_int_length(ipart);
		ft_strcpy(pf->res, pos_fround(pf, ipart, fpart));
	}
}