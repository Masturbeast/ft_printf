#include "includes/ft_printf.h"
#include <stdio.h> 

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

//round function
void	fround(char *str)
{
    int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
		i++;
	i--;
	if (str[i] >= '5')
	{
		if (str[i - 1] == '9')
		{	
			while (str[i - 1] == '9')
			{
				str[i - 1] = '0';
				i--;
                if (str[i - 1] != '9' && str[i - 1] != '.')
                    str[i - 1] += 1;
			}
		}
		else if (str[i - 1] != '.')
			str[i - 1] += 1;
    }
	if (str[i - 1] == '.')
    {
        if (str[i] >= '5' && str[i - 2] != '9')
        {
            str[i - 2] += 1;
            str[i - 1] = '\0';
        }
        if (str[i - 2] == '9')
		{	
			while (str[i - 2] == '9')
			{
				str[i - 2] = '0';
				i--;
			}
            str[i - 2] += 1;
        }
    }
}
// reverses a string 'str' of length 'len' 
void	reverse(char *str, int len) 
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
  
 // Converts a given integer x to string str[].  d is the number 
 // of digits required in output. If d is more than the number 
 // of digits in x, then 0s are added at the beginning. 
int		inttostr(long int x, char *str, int prec) 
{ 
    int i;

	i = 0;
    while (x) 
    {
        str[i++] = (x % 10) + '0'; 
        x = x / 10;	
    }
    // If number of digits required is more, then 
    while (i < prec) 
        str[i++] = (x % 10) + '0';
    reverse(str, i); 
    str[i] = '\0'; 
    return (i); 
} 
  
void	ft_ftoa(int prec, long double n, char *res) 
{ 
    // Extract integer part 
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
    printf("        n is: %.10Lf\n", n);
    // convert integer part to string
    if (tmp < 0 || n == 0)
        i = inttostr(ipart, res + 1, 0) + 1;
    else
        i = inttostr(ipart, res, 0);
         // Extract floating part
    printf("int part is: %ld\n", ipart);
    fpart = n - ipart;
    //printf("fpart: %.10Lf\n", fpart);
	if (prec >= 0) 
    { 
        res[i] = '.';  // add dot 
  
        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter is needed 
        // to handle cases like 233.007 
        fpart = fpart * ft_power(10, prec + 1);
        printf("fpart after power: %Lf\n", fpart);
        inttostr((long int)fpart, res + i + 1, prec);
        fround(res);
    } 
}

int		main() 
{
    char res[50];
    long double n = 8999.59995151915157986;
    char *str = "float nbr is: 51.599995151915157986";
    
    printf("%s\n", str);
    ft_ftoa(0, n, res);
    //res[9] = '\0';
    printf("      printf: %.0Lf\n", n); 
    printf("   my printf: %s\n", res);
    return (0); 
}

/* NOTE: int afterpoint => pf->precision 
afterpoint is the precision in printf */ 