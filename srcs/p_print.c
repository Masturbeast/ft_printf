#include "ft_printf.h"

unsigned long  p_conv(t_printf *pf)
{
   return(va_arg(pf->args, unsigned long));
}

void    p_print2(unsigned long ptr)
{
   char const		*base;
   char				res[9];
   int				i;
 
   base = "0123456789abcdef";
   i = 8;
   while ((ptr / 16) > 0 || i >= 8)
   {
      res[i] = base[(ptr % 16)];
      ptr /= 16;
      i--;
   }
   res[i] = base[(ptr % 16)];
   ft_putchar('0');
   ft_putchar('x');
   while (i < 9)
   {
      ft_putchar(res[i]);
      i++;
   }
}

void  p_print(t_printf *pf)
{
   unsigned long	ptr;
   int		      twidth;
   int            len;
 
   ptr = p_conv(pf);
   len = ft_int_length(ptr);
   twidth = pf->width - len;
	if (pf->opt_size & O_MINUS)
	{
		p_print2(ptr);
		padding(twidth - 1, ' ');
	}
	else
	{
		padding(twidth - 1, ' ');
		p_print2(ptr);
	}
}