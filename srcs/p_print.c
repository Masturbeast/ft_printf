#include "ft_printf.h"

unsigned long  p_conv(t_printf *pf)
{
   return(va_arg(pf->args, unsigned long));
}

void    p_print(t_printf *pf)
{
   unsigned long	ptr;
   char const		*base;
   char				res[9];
   int				i;
 
   ptr = p_conv(pf);
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