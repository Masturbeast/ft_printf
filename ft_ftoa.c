#include <stdio.h> 
#include <stdint.h>

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

size_t		ft_strlen(const char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char *t;

	t = s;
	while (n--)
		*t++ = c;
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}

long int	int_cat(long int x, long int y) 
{
    unsigned long int power; 
	
	power = 10;
    while(y >= power)
    	power *= 10;
    return (x * power + y);        
}

long int		ft_power(long int x, long int power)
{
	long int i;
	long int a;

	a = x;
	if (power == 1)
		return (x);
	/*if (power < 0)
		return (0);*/
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

int		ft_inttostr(long int x, char *str, int prec) 
{ 
    int i;

	i = 0;
    while (x) 
    {
        str[i++] = (x % 10) + '0'; 
        x = x / 10;	
    }
    while (i < prec) 
        str[i++] = (x % 10) + '0';
    ft_str_reverse(str, i); 
    str[i] = '\0'; 
    return (i); 
}

char	*fround(int prec, long int x, long double y)
{
	long int 	t;
	int			i;
	char 		*intcat;
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
	printf("t is: %ld\n", t);
	i = ft_inttostr(t, intcat, 0);
	ft_strclr(intcat);
	printf("i is %d\n", i);
	return (intcat);
}

void	ft_ftoa(int prec, long double n, char *res)
{ 
    long int ipart;
	int i;
	long double fpart;
    long double tmp;

    tmp = n;
    if (n < 0 && n != 0)
    {
        n *= (-1);
        res[0] = '-';
    }
    else if (n == 0)
        res[0] = '0';
    else
	    ipart = (long int)n;
    if (tmp < 0 || n == 0)
        i = ft_inttostr(ipart, res + 1, 0) + 1;
    else
        i = ft_inttostr(ipart, res, 0);
    fpart = n - ipart;
	res = fround(prec, ipart, fpart);
}

int		main() 
{
    char res[50];
    long double n = 999.9999999;
    char *str = "float nbr is: 999.9999999";
    
    printf("%s\n", str);
    ft_ftoa(6, n, res);
	printf("      printf: %.6Lf\n", n); 
	printf("   my printf: %s\n", res);
    return (0); 
}

/* NOTE: int afterpoint => pf->precision 
afterpoint is the precision in printf */ 