#include "includes/ft_printf.h"
#include <stdio.h> 
#include <math.h>

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

// reverses a string 'str' of length 'len' 
void	reverse(char *str, int len) 
{ 
    int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
    while (i<j) 
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
    // add 0s at the beginning
    while (i < d) 
        str[i++] = '0';
    reverse(str, i + 1); 
    str[i] = '\0'; 
    return (i); 
} 
  
void	ftoa(float n, char *res, int afterpoint) 
{ 
    // Extract integer part 
    int ipart;
	int i;
	float fpart;

	if (n < 0)
		n = -n;
	ipart = (int)n; 
    // Extract floating part
    fpart = n - (float)ipart; 
  
    // convert integer part to string
    i = inttostr(ipart, res, 0);
	
	if (afterpoint != 0) 
    { 
        res[i] = '.';  // add dot 
  
        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter is needed 
        // to handle cases like 233.007 
        fpart = fpart * ft_power(10, afterpoint); 
        inttostr((int)fpart, res + i + 1, afterpoint); 
    } 
}

int		main() 
{ 
    char res[50]; 
    float n = -233.007; 
    ftoa(n, res, 3);
    printf("%s\n", res);
	printf("%.3f\n", n); 
    return 0; 
}

void	f_precision_print(t_printf *pf)
{
	
}





/* NOTE: int afterpoint => pf->precision 
afterpoint is the precision in printf */ 