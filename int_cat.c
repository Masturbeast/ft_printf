long long int	int_cat(long long int x, long long int y) 
{
	long long int power;
	
	power = 10;
    while (y >= power)
		power *= 10;
	if (x < 0)
	{
    	return (x * power - y);
	}
	return (x * power + y);        
}