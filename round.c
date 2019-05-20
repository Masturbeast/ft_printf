#include <stdio.h>

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