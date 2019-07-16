#include "includes/ft_printf.h"

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

long long int	int_cat(long long int x, long long int y) 
{
	long long int power;
	
	power = 10;
    while(y >= power)
	{
    	power *= 10;
	}
	if (x < 0)
	{
    	return (x * power - y);
	}
	return (x * power + y);        
}

int		ft_inttostr(long long int x, char *str, int prec) 
{ 
    int			i;
	long long int 	tmp;

	tmp = x;
	i = 0;
	if (x < 0)
		x *= (-1);
    while (x) 
    {
        str[i++] = (x % 10) + '0'; 
        x = x / 10;	
    }
	if (tmp == 0)
	{
		str[i++] = '0';
		str[i++] = '-';
	}
    while (i < prec) 
        str[i++] = (x % 10) + '0';
    ft_str_reverse(str, i); 
    str[i] = '\0';
    return (i); 
}

int		ft_atoi(const char *str)
{
	int i;
	int a;
	int r;

	i = 0;
	a = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == 45)
		a = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (int)str[i] - 48;
		i++;
	}
	return (a * r);
}

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

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char *t;

	t = s;
	while (n--)
		*t++ = c;
	return (s);
}

size_t		ft_strlen(const char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void	ft_str_reverse(char *str, int len) 
{ 
    int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
    while (i < j) 
    { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
		j--; 
    } 
}

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
	if (prec != 0)
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
	if (prec != 0)
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
    long double n = 34.145;
    char *str = "float nbr is: 34.145";
    
    printf("%s\n", str);
    ft_ftoa(6, n, res);
	//printf("\n");
	printf(" real printf: %.6Lf\n", n); 
	printf("   my printf: %s\n", res);
    return (0); 
}