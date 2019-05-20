#include "includes/ft_printf.h"
#include <stdio.h> 

int		ft_power(int x, int power)
{
	int i;
	int a;

	a = x;
	if (power == 1)
		return (x);
	if (power < 0)
		return (0);
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
			}
		}
		else
			str[i - 1] += 1;
    }
    i++;
	if (str[i - 1] == '.')
    {
        if (str[i - 2] == '9')
		{	
			while (str[i - 2] == '9')
			{
				str[i - 2] = '0';
				i--;
			}
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
int		inttostr(int x, char *str, int d) 
{ 
    int i;

	i = 0;
    while (x) 
    {
        str[i++] = (x % 10) + '0'; 
        x = x / 10;	
    }
    // If number of digits required is more, then 
    while (i < d) 
        str[i++] = (x % 10) + '0';
    reverse(str, i); 
    str[i] = '\0'; 
    return (i); 
} 
  
void	ft_ftoa(float n, char *res, int afterpoint) 
{ 
    // Extract integer part 
    int ipart;
	int i;
	float fpart;
    float tmp;

    tmp = n;
    if (n < 0)
    {
        n *= (-1);
        res[0] = '-';
    }
	ipart = (int)n;
    // Extract floating part
    fpart = n - (float)ipart;
    // convert integer part to string
    if (tmp < 0)
        i = inttostr(ipart, res + 1, 0) + 1;
    else
        i = inttostr(ipart, res, 0);
	if (afterpoint != 0) 
    { 
        res[i] = '.';  // add dot 
  
        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter is needed 
        // to handle cases like 233.007 
        fpart = fpart * ft_power(10, afterpoint + 1); 
        inttostr((int)fpart, res + i + 1, afterpoint); 
    } 
}

int		main() 
{
    char res[20]; 
    float n = -42.561468;
    char *str = "-42.56145";
    printf("%s\n", str);
    ft_ftoa(n, res, 6);
    //fround(res);
    //res[9] = '\0';
    printf("%s\n", res);
	printf("%f\n", n); 
    return (0); 
}

/* NOTE: int afterpoint => pf->precision 
afterpoint is the precision in printf */ 